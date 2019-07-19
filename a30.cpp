/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following prompts the user for 10 grades and
*    calculates the average of the grades
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
   for (int i = 0; i < 10; i++)
   {
      sum += grades[i];
   }
   return (sum / 10);
}

/**********************************************************************
 * Calls the functions and displays the average of the grades
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);
   float average = computeAverage(grades);
   cout << "Average Grade: " << average << "%\n";
   return 0;
}
