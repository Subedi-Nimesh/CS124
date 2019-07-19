/***********************************************************************
* Program:
*    Assignment 16, Computing tax
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program prompts the user for income and the calculates
*    his tax.
************************************************************************/

#include <iostream>
using namespace std;

int computeTax(float income);

/**********************************************************************
 * displays the tax brackets from tax.
 ***********************************************************************/
int main()
{
   float income;
   cout << "Income: ";
   cin >> income;
   cout << "Your tax bracket is " << computeTax(income) << "%" << endl;
   return 0;
}

/*********************************************************************
* calculate tax using If-Else statement.
*********************************************************************/
int computeTax(float income)
{
   int tax;
   if (income > 0 && income <= 15100)
      tax = 10;
   else if (income > 15100 && income <= 61300)
      tax = 15;
   else if (income > 61300 && income < 123700)
      tax = 25;
   else if (income > 123700 && income < 188450)
      tax = 28;
   else if (income > 188450 && income < 336550)
      tax = 33;
   else
      tax = 35;
   return tax;
}
