/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Comeau, CS 124
* Author:
*    Nimesh Subedi
* Summary:
* The following program calculates your monthly budget.
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* Monthly budget on the screen.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float income;
   float actuallivingexpenses;
   float actualtaxes;
   float livingexpenses;
   float actualtithe;
   float otherexpenses;
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> livingexpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actuallivingexpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualtaxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualtithe;
   cout << "\tYour actual other expenses: ";
   cin >> otherexpenses;
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income << "    $";
   cout << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << 0.00 << "    $";
   cout << setw(11) << actualtaxes << endl;
   cout << "\tTithing         $" << setw(11) << 0.00 << "    $";
   cout << setw(11) << actualtithe << endl;
   cout << "\tLiving          $" << setw(11) << livingexpenses << "    $";
   cout << setw(11) << actuallivingexpenses << endl;
   cout << "\tOther           $" << setw(11) << 0.00 << "    $";
   cout << setw(11) << otherexpenses << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.00  << "    $";
   cout << setw(11) << 0.00 << endl;
   
   return 0;
}
