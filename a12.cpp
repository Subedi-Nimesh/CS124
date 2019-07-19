/***********************************************************************
 * Program:
 *    Assignment 12, Income
 *    Brother Comeau, CS 124
 * Author:
 *    Nimesh Subedi
 * Summary:
 * The following program prompts the user for his income
 * and then prints their income.
 ************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * prompt the user and display the income
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float age;
   cout << "\tYour monthly income: ";
   cin >> age;
   cout << "Your income is: $";
   cout << setw(9) << age;
   cout << "\n";
   return 0;
}

