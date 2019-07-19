/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary:
* The following program displays a monthly budget.
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* The monthly budget on the screen
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint); 
   cout.precision(2);
   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome         $" << setw(9) << 1000.00 << "\n";
   cout << "\tTaxes          $" << setw(9) << 100.00 << "\n";
   cout << "\tTithing        $" << setw(9) << 100.00 << "\n";
   cout << "\tLiving         $" << setw(9) << 650.00 << "\n";
   cout << "\tOther          $" << setw(9) << 90.00 << "\n";
   cout << "\t=============  ==========\n";
   cout << "\tDelta          $" << setw(9) << 60.00 << "\n";
   return 0;
}
