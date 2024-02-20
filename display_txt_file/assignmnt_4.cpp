#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
	string name;
	char gender;
	string college;
	int score;
	double number;
	double total;
	int count;
	string reply;
	string line;
	string token;
	string inputFileName;
	ifstream inputFile;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Input the file name of coded text: ";
	getline (cin, inputFileName);
	inputFile.open(inputFileName.c_str()); 
	
	if (! inputFile.is_open() ) {
		cout << "Unable to open input file." << endl;
		cout << "Press enter to continue...";
		getline (cin, reply);
		exit(1);
	}
	
	count = 0;
	total = 0;
	
	while (inputFile.peek() != EOF) {
		getline (inputFile, line);
		cout << line << endl;
	}
	
	cout << endl << "End of Line reached." << endl;
	

	
	cout << "Press enter to continue...";
		getline (cin, reply);
		exit(1);
}
