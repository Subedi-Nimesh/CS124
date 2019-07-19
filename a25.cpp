/***********************************************************************
* Program:
*    Assignment 25, Calendar
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program prompts the user for number of day and
*    for the offset and that creates the output of the following month.
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int numDays, int offset);

/*****************************************************************
 * The following Function reads the number of days.
 ****************************************************************/
int getNumDays()
{
   int numDays;
   cout << "Number of days: ";
   cin >> numDays;
   while (numDays < 28 || numDays > 31)
   {
      cout << "Number of Days  must be between 28 and 31.\n"
           << "Number of days: ";
      cin >> numDays;
   }
   return numDays;
}

/*****************************************************************
 * The following Function reads the Offset.
 ****************************************************************/
int getOffset()
{
   int offset;
   cout << "Offset: ";
   cin >> offset;

   while (offset < 0 || offset > 6)
   {
      cout << "Offset must be between 0 and 6.\n"
           << "Offset: ";
      cin >> offset;
   }
   return offset;
}

/*****************************************************************
 * The following Function displays the table in format.
 ****************************************************************/
void displayTable(int numDays,int offset)
{
   int day;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   if (offset == 0)
   {
      day = 2;
      cout << setw(6);
   }
   else if (offset == 1)
   {
      day = 3;
      cout << setw(10);
   }
   else if (offset == 2)
   {
      day = 4;
      cout << setw(14);
   }
   else if (offset == 3)
   {
      day = 5;
      cout << setw(18);
   }
   else if (offset == 4)
   {
      day = 6;
      cout << setw(22);
   }
   else if (offset == 5)
   {
      day = 7;
      cout << setw(26);
   }
   else if (offset == 6)
   {
      day = 1;
      cout << setw(2);
   }
   else
      cout << "Offset must be >= 0 and <= 6\n";
   
   // Displays the days and ending the line
   for (int daysCount = 1; daysCount <= numDays; daysCount++ )
   {
      cout << "  " <<  setw(2) << daysCount;
      ++day;
      if (day == 8)
      {
         cout << "\n";
         day = 1;
      }
   }
   if ( day >= 2 && day <= 7)
      cout << "\n";
   return;
}

/*************************************************************************
 * prompts the user for number of days and offset and displays the table.
 ************************************************************************/
int main()
{
   int numDays = getNumDays();
   int offset = getOffset();
   displayTable(numDays,offset);
   return 0;
}
