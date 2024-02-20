// Brigham Webster
// Date: 11/14/15
// sources: cplusplus.com; stackoverflow.com

#include <iostream>                 
#include <iomanip>                  
#include <fstream>                  
#include <string>         
#include <cmath>                   

using namespace std;
int toShiftCalc (string x);
void decipherOutput (string y, string z, int a);

int main ()
{
	string inputFileName, outputFileName;
	int letterShift;
	string reply;
	
	cout << "Welcome to Brigham Webster's caesar cipher program" << endl; //Intro
	cout << "Input the name of the file to be deciphered: "; //Ask user for name of the encoded txt file
	cin >> inputFileName; //User inputs name of exhisting tobe ciphered file

	letterShift = toShiftCalc(inputFileName); //Set the value of the shift equal to the return value of the function that calculates the int shift value.
	//cout << letterShift << endl; //necessary for debugging	
	cout << "Input the desired name of the output file:"; //Ask user for the desired name of the output file
	cin >> outputFileName; //User inputs name
	
	decipherOutput (inputFileName, outputFileName, letterShift); //call forth function to output the shifted file
	
	cout << "Your deciphered message is waiting in the " << outputFileName << " file." << endl; //notification
	cout << "Thank you for using Brigham Webster's caeser cipher program." << endl; //greeting
	cout << "Press enter to continue...";
	getline(cin, reply);
	exit(1); //exit status
}
//toShiftCalc function counts the number of times each letter appears in the given text. Then it takes the number that appeared the most
//and assigns it to the int value letterShift. This value is then returned to the main function variable letterShift and then used
//in the second void function of decipherOutput.
int toShiftCalc (string x) { 
	ifstream inputFile;
	char charMem, character, countTrack[128] = {};
	int tobeShift, newChar, letterShift, countCopy, countHold = 0, letterCount[128] = {};
	string reply;
	
	inputFile.open(x.c_str()); //The user string input is used by the ifstream variable to open designated file.

	if (!inputFile.is_open()) { //If the file does not open then print error message
    	cout << "Unable to open input file." << endl;
    	cout << "Press enter to continue...";
    	getline(cin, reply);
    	exit(1);
	}

	while (inputFile >> character) { //reads each character from file into the value of character
    	if (!inputFile.fail()) {
			letterCount[static_cast<int>(character)]++;
	    }
	}

	for (int i=0; i<=127; i++) { //counts the number of times each character appears
    	if (letterCount[i] > 0) {
        	cout << static_cast<char>(i) << " " << letterCount[i] << endl; // Neccessary for debugging
        	countCopy = letterCount[i]; //copies the values
				if (countCopy > countHold) { //records the largest number of times a character occured
        			countHold = countCopy;
        			charMem = static_cast<char>(i); //records the most frequently appeared character
        		}
			}
		}
	
	cout << countHold << " " << charMem << endl; //neccessary for debugging
	letterShift = static_cast<int>('e') - static_cast<int>(charMem); //sets the value of lettershift to the AScii value of the most frequent character
	//in the english language "e" minus the AScii value of the most frequent character in the given text.
	cout << static_cast<char>(static_cast<int>(charMem) + letterShift) << endl; //neccessary for debugging
	cout << letterShift << endl; //neccessary for debugging
	inputFile.close(); // closes the input file
	
	return letterShift; //returns an int value of the amount the text needs to be shifted by
}
//This function takes the input value of both the input txt file and output txt file as well as the int value that represents the amount that each
//character needs to be shifted by. It applies this value to the text to be deciphered line by line printing each line in the output txt file
//that was specified by the user. 
void decipherOutput (string y, string z, int a) {
	ifstream inputFile;
	ofstream outputFile;
	string line;
	int count = 0, length;
	
	outputFile.open(z.c_str()); //Opens the output file
	
	inputFile.open(y.c_str());	//opens the input file
	
	while (getline(inputFile, line)) { //Takes in the input file line by line
		length = (int)line.length(); //
		
		for (count = 0; count < length; count++) { 
			if (isalpha(line[count])) {
				line[count] = tolower(line[count]); //sets all the values to the lower case of each letter so that the AScii values are not 
				//inaccurately altered in the process.
				for (int i=0; i < (26 - (-1 * a)); i++) {
					if (line[count] == 'z') { // starts the value over again from the lower case so that the letter shift does not alter
					//it inaccurately
						line[count] = 'a';
					} else {
						line[count]++;
					}
				}
			}
		}
		outputFile << line << endl;//Outputs the shifted txt line to the specified output file.
	}	
	outputFile.close(); //close output file
	inputFile.close(); //close input file
}
