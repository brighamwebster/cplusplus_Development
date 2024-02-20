// Brigham Webster
// Date: 12/4/15
// Assignment 8 : Library Database
// Sources: Stack Overflow

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1000; 
struct song {
	string title;
	string artist;
	string duration;
	string album;
	
};

song songs [ARRAY_SIZE];

int loadData(string pathname);
void showAll(int count);
void sortByTitle (int count);
void sortByArtist (int count);
int showSongsByArtist (int count, string name);
int showSongsByTitle (int count, string title);


int main ()
{
	int numFound, nextNumFound, numOfSongs;
	char reply;
	string outputFile, songTitles, artistName, backupFile;
	cout << "Welcome to Brigham's music library organizer." << endl;
	cout << "If one exists, enter the name of the backup file (otherwise enter 'none'):";
	cin >> backupFile;
	numOfSongs = loadData (backupFile);
	if (numOfSongs == 0) {
		cout << "Please enter the desired name of the output file: ";
		cin >> outputFile;
	} else if (numOfSongs == -1) { 
		cout << numOfSongs << " songs loaded successfully" << endl;
		exit(1);
	} else {
		cout << numOfSongs << " songs loaded successfully." << endl; // Displays number of books in database
	}	
	
	do { //do while loop for the options
		cout << "Enter Q to (Q)uit, Search (A)rtist, Search (T)itle, (S)how All: ";
		cin >> reply;
		if (reply == 'a' || reply == 'A') {
			sortByArtist (numOfSongs);
			cout << endl << "Artist's name: ";
			getline(cin.ignore(), artistName);
			numFound = showSongsByArtist(numOfSongs, artistName);
			cout << numFound << " records found." << endl << endl;
		} else if (reply == 'q' || reply == 'Q') {
			exit(1);
		} else if (reply == 's' || reply == 'S') {
			sortByTitle (numOfSongs);
			cout << endl;
			showAll(numOfSongs);
			cout << endl;
		} else if (reply == 't' || reply == 'T') {
			sortByTitle (numOfSongs);
			cout << endl << "Song title: ";
			getline(cin.ignore(), songTitles);
			nextNumFound = showSongsByTitle(numOfSongs, songTitles);
			cout << nextNumFound << " records found." << endl << endl;
		} else {
			cout << endl << "Invalid input" << endl;
		}
	} while (reply != 'q' && reply != 'Q');
}


int loadData (string pathname){ // Loads the data from the input file into the parrallel string arrays and returns the number of books
	int count = 0, noCount = -1; // in the "database"
	ifstream inputFile;
	string noInputFile, line, reply;
	noInputFile = "none";
	
	if (pathname == noInputFile) {
		return count;
	} else {
	
		inputFile.open(pathname.c_str()); 
	
		if (!inputFile.is_open()) { //If the file does not open then print error message
    		cout << "Unable to open input file." << endl;
    		return noCount;
		}
		
		for (int i = 1; i < ARRAY_SIZE; i++) {
		
				getline(inputFile, songs[i].title, ';');
				cout << songs[i].title << endl;
				getline(inputFile, songs[i].artist, ';');
				cout << songs[i].artist << endl;
				getline(inputFile, songs[i].duration, ';');
				cout << songs[i].duration << endl;
				getline(inputFile, songs[i].album, ';');
				cout << songs[i].album << endl;	
				count++;
				
			 	if(inputFile.eof()) {
				 	return count;
				 }
			
		}
	}
}

void showAll (int count) {
	for (int j = 1; j <= count; j++) { // Displays every title artist duration and 
		cout << "Title: " << songs[j].title << endl;
		cout << "Artist: " << songs[j].artist << endl;
		cout << "Duration: " << songs[j].duration << " min" << endl;
		cout << "Album: " << songs[j].album << endl;
		cout << endl;
	}
}

int showSongsByArtist (int count, string name) { // Lets the user search books by author Returns all titles and authors
	int numByArtist;                              // based on a 1 word search
	for (int i = 1; i <= count; i++) {
		if(songs[i].artist.find(name) != string::npos) { // Searches the string for another string
			cout << songs[i].title << " (" << songs[i].artist << ")" << endl; // If the searched for string is found in the searched string then prints
			numByArtist++; // the searched string and also adds 1 to the value of songs found
		}
	}
	return numByArtist;
}

int showSongsByTitle (int count, string title) {
	int numByTitle;
	for (int i = 1; i <= count; i++) {
		if (songs[i].title.find(title) != string::npos) { // searches the string for another string
			cout << songs[i].title << " (" << songs[i].artist << ")" << endl; // If the searched for string is found in the searched string returns that string
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
            if (songs[j].title > songs[j+1].title) {    // ascending order simply changes to <
                temp = songs[j].title;             // swap elements
                songs[j].title = songs[j+1].title;
                songs[j+1].title = temp;
                flag = 1;        // indicates that a swap occurred.
            }
        }
        
    }
    
}
	


void sortByArtist (int count) {
	int i, j, flag = 1;    // set flag to 1 to start first pass
    string temp;             // holding variable 
    
	for(i = 1; (i <= count) && flag; i++) {
        flag = 0;
        for (j=1; j < (count); j++) {    
            if (songs[j].artist > songs[j+1].artist) {    // ascending order simply changes to <
                temp = songs[j].artist;             // swap elements
                songs[j].artist = songs[j+1].artist;
                songs[j+1].artist = temp;
                flag = 1;        // indicates that a swap occurred.
            }
        }
        
    }
}
