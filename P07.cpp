/************************************************************************
* Program:
*    Project 07, Calendar
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*   The following program prompts the user for the month and the year
*   to display the calendar for that year with proper indentation.
***********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
void display(int month, int year, int offset);
bool isLeapYear(int year);
int numDaysMonth(int month, int year);
int computeOffset(int month, int year);

/***********************************************************************
 * Prompts the user for month and validates it.
 **********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/**********************************************************************
 * Prompts the user for year and validates it.
 *********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;

   while ( year < 1753)
   {
      cout << "Year must be 1753 or later.\n"
           << "Enter year: ";
      cin >> year;
   }
   return year;
}

/*********************************************************************
 * Displays the month and year in Calendar format.
 ********************************************************************/
void display(int month, int year, int offset)
{
   int day;
   cout << endl;
   if ( month == 1)
      cout << "January";
   else if ( month == 2)
      cout << "February";
   else if ( month == 3)
      cout << "March";
   else if ( month == 4)
      cout << "April";
   else if ( month == 5)
      cout << "May";
   else if ( month == 6)
      cout << "June";
   else if ( month == 7)
      cout << "July";
   else if ( month == 8)
      cout << "August";
   else if ( month == 9)
      cout << "September";
   else if ( month == 10)
      cout << "October";
   else if ( month == 11)
      cout << "November";
   else if ( month == 12)
      cout << "December";

   cout << ", " << year << endl;
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   // Calculates offset and width of the line on the right
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
      cout << "Error offset must be >= 0 and <=6\n";

   // Displays the days and corrects indentation.
   for (int days = 1; days <= numDaysMonth(month, year); days++ )
   {
      cout << "  " << setw(2) << days;
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

/**********************************************************************
 * validates if the year is a leap year or not.
 *********************************************************************/
bool isLeapYear(int year)
{
   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      return true;
   else
      return false;
}

/********************************************************************
 * Calculates the number of days in the month.
 *******************************************************************/
int numDaysMonth(int month, int year)
{
   int days;

   if ( month == 1)
      days = 31;
   else if ( month == 2)
   {
      if (isLeapYear(year))
         days = 29;
      else
         days = 28;
   }
   else if ( month == 3)
      days = 31;
   else if ( month == 4)
      days = 30;
   else if ( month == 5)
      days = 31;
   else if ( month == 6)
      days = 30;
   else if ( month == 7)
      days = 31;
   else if ( month == 8)
      days = 31;
   else if ( month == 9)
      days = 30;
   else if ( month == 10)
      days = 31;
   else if ( month == 11)
      days = 30;
   else if ( month == 12)
      days = 31;

   return days;
}

/********************************************************************
 * This function computes the offset
 *******************************************************************/
int computeOffset(int month, int year)
{
   int numDays = 0;
   for (int yearCount = 1753; yearCount < year; yearCount++)
   {
      if (isLeapYear(yearCount) == true)
         numDays = numDays + 366;
      else
         numDays = numDays + 365;
   }

   for (int monthCount = 1; monthCount < month; monthCount++)
   {
      numDays = numDays + numDaysMonth(monthCount, year);
   }

   return numDays % 7;
}

/*******************************************************************
 * Main calls the functions and displays the whole calendar.
 ******************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   
   display(month, year, offset);
      
   return 0;
}
