/***********************************************************************
* Program:
*    Assignment 33, Letter Count
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following prompts the user for a letter and a sentence and
*    counts the reoccurring letter in the sentence.
************************************************************************/

#include <iostream>
using namespace std;
void date(float *pAccount);

/**********************************************************************
 * counts the number of reoccurring letter in a sentence.
 *********************************************************************/
void date(float * pAccount)
{
   float dinner;
   float movie;
   float iceCream;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   
   
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;
   *pAccount = *pAccount - dinner - movie - iceCream;
   return;
}

/**********************************************************************
 * Prompts the user for a word and a sentence and calls the functions
 * and displays the number of times the word occurs.
 ***********************************************************************/
int main()
{
   float account1;
   float account2;
   cout << "What is Sam's balance? ";
   cin >> account1;
   cout << "What is Sue's balance? ";
   cin >> account2;
   float * pAccount;
   if (account1 > account2)
      pAccount = &account1;
   else
      pAccount = &account2;
   date(pAccount);
   cout << "Sam's balance: $" << account1  << endl;
   cout << "Sue's balance: $" << account2 << endl; 
   return 0;
}
