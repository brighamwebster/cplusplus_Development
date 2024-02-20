// Brigham Webster
// Date: 12/4/15
// Assignment 8 : Library Database
// Sources: Stack Overflow

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1000; // line 12 - 19 as specified by assignment
struct book {
	string title;
	string author;
};

book books [ARRAY_SIZE];

int loadData(string pathname);
void showAll(int count);
void sortByTitle (int count);
void sortByAuthor (int count);
int showBooksByAuthor (int count, string name);
int showBooksByTitle (int count, string title);


int main ()
{
	int numFound, nextNumFound, numOfBooks;
	char reply;
	string bookTitles, authorName, backupFile;
	cout << "Welcome to Brigham's library database." << endl;
	cout << "Please enter the name of the backup file:";
	cin >> backupFile;
	numOfBooks = loadData (backupFile);
	if (numOfBooks == -1) { // Sets the value of the number of books in the database to -1 if the input file does not exist
		cout << numOfBooks << " books loaded successfully" << endl;
		exit(1);
	} else {
		cout << numOfBooks << " books loaded successfully." << endl; // Displays number of books in database
	}	
	
	do { //do while loop for the options
		cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";
		cin >> reply;
		if (reply == 'a' || reply == 'A') {
			sortByAuthor (numOfBooks);
			cout << endl << "Author's name: ";
			getline(cin.ignore(), authorName);
			numFound = showBooksByAuthor(numOfBooks, authorName);
			cout << numFound << " records found." << endl << endl;
		} else if (reply == 'q' || reply == 'Q') {
			exit(1);
		} else if (reply == 's' || reply == 'S') {
			sortByTitle (numOfBooks);
			cout << endl;
			showAll(numOfBooks);
			cout << endl;
		} else if (reply == 't' || reply == 'T') {
			sortByTitle (numOfBooks);
			cout << endl << "Book title: ";
			getline(cin.ignore(), bookTitles);
			nextNumFound = showBooksByTitle(numOfBooks, bookTitles);
			cout << nextNumFound << " records found." << endl << endl;
		} else {
			cout << endl << "Invalid input" << endl;
		}
	} while (reply != 'q' && reply != 'Q');
}


int loadData (string pathname){ // Loads the data from the input file into the parrallel string arrays and returns the number of books
	int count = 0, noCount = -1; // in the "database"
	ifstream inputFile;
	string line, reply;
	
	inputFile.open(pathname.c_str()); 
	
	if (!inputFile.is_open()) { //If the file does not open then print error message
    	cout << "Unable to open input file." << endl;
    	return noCount;
	}
	
		for (int i = 1; i < ARRAY_SIZE; i++) {
			
				getline(inputFile, books[i].title);
				getline(inputFile, books[i].author);
				//cout << bookTitle[i] << endl;
				//cout << bookAuthor[i] << endl;	
				count++;
				 if(inputFile.eof()) {
				 	return count;
				 }
		}
}

void showAll (int count) {
	for (int j = 1; j <= count; j++) { // Displays every title and author in a single line
		cout << books[j].title << " (" << books[j].author << ")" << endl;
	}
}

int showBooksByAuthor (int count, string name) { // Lets the user search books by author Returns all titles and authors
	int numByAuthor;                              // based on a 1 word search
	for (int i = 1; i <= count; i++) {
		if(books[i].author.find(name) != string::npos) { // Searches the string for another string
			cout << books[i].title << " (" << books[i].author << ")" << endl; // If the searched for string is found in the searched string then prints
			numByAuthor++; // the searched string and also adds 1 to the value of books found
		}
	}
	return numByAuthor;
}

int showBooksByTitle (int count, string title) {
	int numByTitle;
	for (int i = 1; i <= count; i++) {
		if (books[i].title.find(title) != string::npos) { // searches the string for another string
			cout << books[i].title << " (" << books[i].author << ")" << endl; // If the searched for string is found in the searched string returns that string
			numByTitle++; // and also adds 1 to the value of books found
		}
	}
	return numByTitle;
}

void sortByTitle (int count) {
	int i, j, flag = 1;    // set flag to 1 to start first pass
    string temp;             // holding variable 
    
	for(i = 1; (i <= count) && flag; i++) {
        flag = 0;
        for (j=1; j < (count); j++) {    
            if (books[j].title > books[j+1].title) {    // ascending order simply changes to <
                temp = books[j].title;             // swap elements
                books[j].title = books[j+1].title;
                books[j+1].title = temp;
                flag = 1;        // indicates that a swap occurred.
            }
        }
        
    }
    //for (int q = 1; q <= count; q++) {
    //	cout << books[q].title << endl;
	//} 
}
	


void sortByAuthor (int count) {
	int i, j, flag = 1;    // set flag to 1 to start first pass
    string temp;             // holding variable 
    
	for(i = 1; (i <= count) && flag; i++) {
        flag = 0;
        for (j=1; j < (count); j++) {    
            if (books[j].author > books[j+1].author) {    // ascending order simply changes to <
                temp = books[j].author;             // swap elements
                books[j].author = books[j+1].author;
                books[j+1].author = temp;
                flag = 1;        // indicates that a swap occurred.
            }
        }
        
    }
}
