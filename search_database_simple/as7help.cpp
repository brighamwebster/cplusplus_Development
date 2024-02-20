#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main ()
{
	ifstream inputFile;
	string inputFileName;
	
	cin >> inputFileName;
	inputFile.open(inputFileName.c_str()); 
	
	if (!inputFile.is_open()) {
		cout << "Nope";
	} else {
		cout << "Yep";
	}
}
