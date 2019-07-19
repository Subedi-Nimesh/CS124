/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following prompts the user for 10 grades and calculates
*    the average of the grades and ignores if it is negative.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompts the user for 10 grades
 *********************************************************************/
void getGrades(int grades[])
{
   for (int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
   return;
}

/**********************************************************************
 * Calculates the average of grades.
 *********************************************************************/
int computeAverage(int grades[])
{
   int sum = 0;
   int count = 0;
   int average;
   for (int i = 0; i < 10; i++)
   {
      if (grades[i] >= 0 && grades[i] <= 100)
      {
         sum += grades[i];
         count++;
      }
   }
   if (count != 0)
   {
      average = sum / count;
      return average;
   }
}

/**********************************************************************
 * Calls the functions and displays the average of the grades
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);
   float average = computeAverage(grades);
   if (average >= 0 && average <= 100)
      cout << "Average Grade: " << average << "%\n";
   else
      cout << "Average Grade: ---%\n";
   return 0;
}
