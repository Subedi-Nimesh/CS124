/***********************************************************************
* Program:
*    Assignment 13, Temperature conversion
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program prompts the user to enter temperature
*    in Fahrenheit and converts to Celsius.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Converts temperature from Fahrenheit to Celsius.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);
   float tempF;
   cout << "Please enter Fahrenheit degrees: ";
   cin >> tempF;
   float tempC = 5.0 / 9 * (tempF - 32);
   cout << "Celsius: " << tempC << endl;
   return 0;
}
