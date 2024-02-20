// Brigham Webster
// Assignment_3
// Sources: class content
// Date: 10/07/2015

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
	int adults, child, length, newLength;
	double price, fuel;
	char answer1, answer2, dollar;
	
	dollar = '$';
	
	// Introducing the program. Asks for number of adults, children and if they have a vehicle.
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome to Brigham Webster's fare calculator" << endl;
	cout << "How manay adults (age 12 and over) are in your party:";
	cin >> adults;
	cout << "How many children (age 5 to 11) are in your party?";
	cin >> child;
	cout << "Are you driving a vehicle onto the ferry? (y/n):";
	cin >> answer1;
	
	//first if/else statement determining whether or not a vehicle is included in fare calculator.
	
	if (answer1 == 'y' || answer1 == 'Y') {
		cout << "What is the length of the vehicle in feet:";
		cin >> length;
		
		// Second if statement inside if statement determines if the vehicle is over 20 feet in length.
		
		if (length > 20) {
			cout << "Is the vehicle over 7 feet high? (y/n):";
			cin >> answer2;
			
			// Third if statement determines if the vehicle is over 7 feet high.
			//If yes the fare is calculated base on an over 7 foot tall vehicle.
			
			if (answer2 == 'y' || answer2 == 'Y'){
				newLength = length - 20;
				price = (13.00 * adults) + (6.50 * child) + 69.00 + (3.45 * newLength);
				fuel = (1.25 * adults) + (1.25 * child) + 10.40;			
		
			// Else/if the vehicle is 7 feet or under then fare is calculated accordingly.
		
			} else if (answer2 == 'n' || answer2 == 'N') {
				newLength = length - 20;
				price = (13.00 * adults) + (6.50 * child) + 43.00 + (2.15 * newLength);
				fuel = (1.25 * adults) + (1.25 * child) + 4.15;
				
			}	
			
		// Else statement if the vehicle length is equal to or less than 20 feet.	
		
		} else {
			
			cout << "Is the vehicle over 7 feet high? (y/n):";
			cin >> answer2;
			
			// If statement determines if the vehicle is over 7 feet high.
			// If yes the fare is calculated base on an over 7 foot tall vehicle.
			// This calculation is done without the newLength variable.
			
			if (answer2 == 'y' || answer2 == 'Y') {
				
				price = (13.00 * adults) + (6.50 * child) + 69.00;
				fuel = (1.25 * adults) + (1.25 * child) + 10.40;
		
			// Else/if the vehicle is 7 feet or under then fare is calculated accordingly.
			// This calculation is done without the newLength variable.
		
			} else if (answer2 == 'n' || answer2 == 'N') {
				
				price = (13.00 * adults) + (6.50 * child) + 43.00;
				fuel = (1.25 * adults) + (1.25 * child) + 4.15;
			
			}
		}
		
	// Else/if there is no car included in the party then the fare is calculated without any vehicle variables	
						
	} else if (answer1 == 'n' || answer1 == 'N') {
		
		price = (13.00 * adults) + (6.50* child);
		fuel = (1.25 * adults) + (1.25 * child);
	
	} 
	
	// The end greeting/results is produced regardless of the fare type calculator.
	
	cout << "Your fare is a total of " << dollar << price << " plus a fuel surcharge of " << dollar << fuel << endl;
	cout << "Total amount payable is " << dollar << price + fuel << endl;
	cout << "Thank you for using Brigham Webster's fare calculator" << endl;
	
	return 0;

}
