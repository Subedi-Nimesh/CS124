/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    This program will reveal if a person is a full tithe payer or not
*    using his income and tithe.
************************************************************************/

#include <iostream>
using namespace std;

/*************************************************************
* Checks if the 10 percent of income is more or equal to tithe
*************************************************************/
bool isFullTithePayer(float income, float tithe)
{
   if (0.1 * income <= tithe)
      return true;
   else
      return false;
}


/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}
