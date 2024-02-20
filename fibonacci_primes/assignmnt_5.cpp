// Brigham Webster
// Assignment 5
// Date: 11/1/2015
// Sources: none

#include <iostream>
#include <iomanip> //included so that I could make the initial text pretty.

using namespace std;

bool isPrime (long long x); // My bool function I had a particularly difficult time grasping the concept of functions outside the main.

int main ()
{
	long long n, fibNum, fibOne, fibTwo; //my fibonacci counter variable followed by my fibonacci manipulated variables.
	n = 0;
	fibNum = 0;
	fibOne = 0;
	fibTwo = 1;
	
	cout << "Fibonacci primes by Brigham Webster" << endl << endl;
	cout << "  n                Fibonacci Primes" << endl;
	cout << "===================================" << endl; // initial text header
		
	while (fibNum <= 1000000000) {
		if (isPrime(fibNum) == 1) {
			cout << " " << setw(2) << ++n << setw(32) << fibNum << endl;
		}
		fibNum = fibOne + fibTwo; 
		fibOne = fibTwo;
		fibTwo = fibNum; // Had a very hard time with the outside my main function functions.
	}                    // was finally able to create my bool function and call it inside my fibonacci function.
}

bool isPrime (long long x) {
	for ( int i = 2; i <= (x/2); i++ )
          {
              if (x % i == 0)
              return (0); 
          }
          return (1); // my bool function for determining whether or not a number is prime.
}


