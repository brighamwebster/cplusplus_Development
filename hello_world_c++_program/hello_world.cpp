/* 
* Assignment #1
* Author: Brigham Webster
* Date: 09/21/15
*/

#include <stdio.h>

int main ()
{
	char name[20] = "0"; //Size 20 to allow for large word.
	char subject[20] = "0"; //Size 20 to allow for large word. I used a string type for both variables.
	
    printf("Welcome to Brigham Webster's crystal ball! \n"); 
    printf("What is your name, please? ");
    
    scanf("%s", name);
    
    printf("Hello, %s. My name is Brigham. \n", name);
    printf("What subject are you studying?");
    
    scanf("%s", subject);
    
    printf("Well, %s, Brigham's' crystal ball says \nyou will do very well in %s this term.\n", name, subject);
    printf("Good Luck!\n");
    
	return 0;
}
