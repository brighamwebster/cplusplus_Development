/* 
* Assignment #1
* Author: Brigham Webster
* Date: 09/21/15
*/

#include <iostream>

using namespace std;

int main ()
{
	string name, subject; // I put the same var type on the same line.
		
	cout << "Welcome to Brigham Webster's crystal ball! \n"; //New line sign.
	cout << "What is your name, please?";
	
    cin >> name; //I take a 1 word no space input.
	
	cout << "Hello, " << name << ". My name is Brigham. \n";
	cout << "What subject are you studying?";
	
	cin >> subject; // I take another 1 word no space input
	
	cout << "Well, " << name << ", Brigham's crystal ball says \n"; 
	cout << "you will do very well in " << subject << " this term."; // Call on previously read inputs and display them as outputs.
	
	/* I have no experience with c++ only c. I wrote the whole program in c at first
	   not realizing that they had a very different layout. I think the program is
	   formatted fine but any pointers are much appreciated. Thank you. 
	   - Brigham Webster*/
}
