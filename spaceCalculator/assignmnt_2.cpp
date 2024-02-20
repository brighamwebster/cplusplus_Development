//Brigham Webster
//Class: D2L CS-161
//Date: 10/2/2015

#include <iostream>
#include <iomanip> // I included this so I could control the float variable's decimal places (for setprecision()).

using namespace std;

int main ()
{
	int a, b, c, d, height, door, window; //I kept all of the cin variables together.
	int sum, area, doorArea, winArea; //I kept all of the "altered" variables together.
	float paintArea, paint;

	
	cout << "Welcome to Brigham's paint estimator!" << endl;
	cout << "What is the length of wall 1: ";
	cin >> a;
	cout << "What is the length of wall 2: ";
	cin >> b;
	cout << "What is the length of wall 3: ";
	cin >> c;
	cout << "What is the length of wall 4: ";
	cin >> d;
	
	sum = a + b + c + d; //Blocked the code at each variable definition.
	
	cout << "The total length of the wall is " << sum << " feet." << endl;
	cout << "What is the height of the wall: ";
	cin >> height;
	
	area = sum * height;
	
	cout << "The total area of the wall is " << area << " square feet." << endl;
	cout << "How many doors are there: ";
	cin >> door;
	cout << "How many windows are there: ";
	cin >> window;
	
	doorArea = 20 * door;
	winArea = 15 * window;
	paintArea = area - (doorArea + winArea);
	
	cout << "Wall area to paint is " << paintArea << " square feet." << endl;
	
	paint = paintArea / 350;
		
	cout << "This will require " << setprecision(2) << paint << " gallon(s) of paint." << endl;	
	
	return 0;
	
	//I wasn't quite sure if there was a different way that you could/should set your variables equal...
	//...to in c++ than c. Example "paint = paintArea / 350". I thought I saw an example of...
	//...a different way to define your variables in c++. I guess my question is if the way...
	//...shown above is the standard way in c++. Thanks for the tips,
	// - Brigham Webster
}
