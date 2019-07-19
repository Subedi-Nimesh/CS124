/***********************************************************************
* Program:
*    Assignment 35, Calculate Grade
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary:
*    The following prompts the user for his grades and calculates
*    the grades and its sign.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Calculates the letter grades.
 *********************************************************************/
int computeLetterGrade(int percentage)
{
   char letterGrade;
   switch (percentage / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
   return letterGrade;
}

/**********************************************************************
 * the functions computes the sign of the grades
 ***********************************************************************/
char computeGradeSign(int percentage)
{
   char gradeSign;
   if (percentage >= 60 && percentage <= 95)
      gradeSign = (percentage % 10 > 6) ? '+' :
         (percentage % 10 < 3) ? '-' : '*';
   else
      gradeSign = '*';
   return gradeSign;
}

/**********************************************************************
 * Calls the functions and displays the grades with its sign
 ***********************************************************************/
int main()
{
   int percentage;
   cout << "Enter number grade: ";
   cin >> percentage;
   char letterGrade = computeLetterGrade(percentage);
   char gradeSign = computeGradeSign(percentage);
   if (gradeSign == '*')
      cout << percentage << "% is " << letterGrade << endl;
   else
      cout << percentage << "% is " << letterGrade << gradeSign << endl;
   return 0;
}
