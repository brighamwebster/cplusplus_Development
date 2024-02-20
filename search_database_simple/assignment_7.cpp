// Author: Brigham Webster
// Assignment #7
// Date: 11/28/2015
// sources: stackoverflow.com

#include <iostream>
#include <fstream> //for input txt file
#include <iomanip> // for setw
#include <stdlib.h> //for converting string to double
#include <string> // for the string

using namespace std;

struct Item {
		string plu;
		string name;
		double price;
	};

int loadData ();	//using specified functions
string getName(string x, int currentIndex); //using specified functions
double getPrice(string y, int currentIndex); //using specified functions

const int MAX_ITEMS = 100; //using int MAX_ITEMS for the size of the array
Item items [MAX_ITEMS];
string reply;

int main ()
{
	int numOfItems, numPurchased;
	string enteredPlu, product;
	double total = 0.0, thePrice;
	
	cout << "Welcome to Brigham's grocery!" << endl; //introduction
	numOfItems = loadData();
	cout << numOfItems << " items loaded successfully." << endl << endl;
	do {
		cout << "Barcode: ";
		cin >> enteredPlu;
		if (enteredPlu == "q" || enteredPlu == "Q") { //So that entered q or Q does not print out "item not found" message
			cout << endl;
		} else if (enteredPlu.length() < 5) { //Sets the limited length of the plu num to 5 digits so not to return a value for a substring of a 
				cout << "Item not found" << endl;
		} else {
			product = getName(enteredPlu, numOfItems); // sets the string values to the associated name and price of the entered plu number
			thePrice = getPrice(enteredPlu, numOfItems);
			if (product == "") {
				cout << "Item not found" << endl;
			} else {
				cout << setw(25) << product << "     $" << setw(6) << thePrice << endl;
				numPurchased++; // counts the number of things bought by the user
				total += thePrice; // Prints out the total price
			}
		}
	} while (enteredPlu != "q" && enteredPlu != "Q"); // if the entered plu equals q or Q then the loop breaks
	cout << "You bought " << numPurchased << " items." << endl;
	cout << "The total cost is " << setw(25) << "$  " << total << endl;
	cout << "Thank you for shopping at Brigham's grocery." << endl; // says goodbye
	
	return 0;
}

//the following function should load the text from the input file into the structure
int loadData () {
	string line, firstSub, secSub, thirdSub;
	string inputFileName;
	ifstream inputFile;
	int currentIndex = 0;
	char* asd;
	
	cout << "Please input the name of the backup file: "; 
	cin >> inputFileName; //read user input for the location of the backup file
	inputFile.open(inputFileName.c_str()); //open specified document
	
	if (!inputFile.is_open()) { //If the file does not open then print error message
    	cout << "Unable to open input file." << endl;
    	cout << "Press enter to exit... ";
    	getline(cin, reply);
    	exit(1);
	} 
	
	while (getline(inputFile, line)) { //get's each line from the string
		firstSub = line.substr(0, 10);//devides string into smaller components for struct members
		secSub = line.substr(10, 25);
		thirdSub = line.substr(35);
		items[currentIndex].plu = firstSub;
		items[currentIndex].name = secSub;
		items[currentIndex].price = atof(thirdSub.c_str()); // converts the substring into a double and copies to the struct double member
		
	//	cout << items[currentIndex].plu << "     " << items[currentIndex].name << "     " << items[currentIndex].price << endl;
		currentIndex++; //couts the number of items in the specified backup file
	}
	cout << endl << endl;
	return currentIndex;	//returns the total num of books
}
//The following function should return the price of the given plu input
double getPrice(string x, int currentIndex) {
	for ( int i = 0; i <= currentIndex; i++) {
		if (items[i].plu.find(x) == 0) {
			return items[i].price; // returns the price of the entered plu
		} 
	}
}
//the following function should return the name of the given plu number
string getName(string y, int currentIndex) {
	string nada = "";
	for (int i = 0; i <= currentIndex; i++) {
		if (items[i].plu.find(y) == 0) {
			return items[i].name; //returns the name of the item associated with the entered plu
		}
	}
	return nada; //if the plu doesn't match then returns a string nada
}
