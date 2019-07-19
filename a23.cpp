/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program asks a number and  displays the sum of
*    multiple of the user given number.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Displays the sum of multiple of the user given number.
 ***********************************************************************/
int main()
{
   int choiceNumber;
   int sumOfMultiple = 0;
   int numMultiple = 1;
   int multiple = 0;
   cout << "What multiples are we adding? ";
   cin >> choiceNumber;
   while (multiple < 100)
   {
      sumOfMultiple = sumOfMultiple + multiple;
      multiple = choiceNumber * numMultiple;
      numMultiple++;
   }
   cout << "The sum of multiples of " << choiceNumber
        << " less than 100 are: " << sumOfMultiple << endl;
   return 0;
}
