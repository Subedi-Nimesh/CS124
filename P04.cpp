/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Comeau, CS 124
* Author:
*    Nimesh Subedi
* Summary:
* The following program calculates your monthly budget.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
 * Declare the function types and variables.
 **********************************************************************/

void display(double income, double budgetLiving, double actualTax,
             double actualTithing, double actualLiving, double actualOther);

/***********************************************************************
 * Displays welcome message.
 **********************************************************************/
void displayWelcomeMessage()
{
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   return;
}

/***********************************************************************
 * Prompts the user of Income and returns it.
 **********************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/***********************************************************************
 * Prompts the user of Budget Living and returns it.
 **********************************************************************/
double getBudgetLiving()
{
   double budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/***********************************************************************
 * Prompts the user of Actual Living and returns it.
 **********************************************************************/
double getActualLiving()
{
   double actualLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/***********************************************************************
 * Prompts the user of Actual Tax and returns it.
 **********************************************************************/
double getActualTax()
{
   double actualTax;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;
}

/***********************************************************************
 * Prompts the user of Actual Tithing and returns it.
 **********************************************************************/
double getActualTithing()
{
   double actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/***********************************************************************
 * Prompts the user of Actual Other and returns it.
 **********************************************************************/
double getActualOther()
{
   double actualOther;
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/***********************************************************************
 * calculates the tax and returns it.
 **********************************************************************/
double computeTax(double monthlyIncome)
{
   double yearlyIncome = monthlyIncome * 12;
   double yearlyTax;
   if (yearlyIncome > 0 && yearlyIncome <= 15100)
      yearlyTax = yearlyIncome * 0.10;
   else if (yearlyIncome > 15100 && yearlyIncome <= 61300)
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
   else if (yearlyIncome > 61300 && yearlyIncome < 123700)
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
   else if (yearlyIncome > 123700 && yearlyIncome < 188450)
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
   else if (yearlyIncome > 188450 && yearlyIncome < 336550)
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
   else
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
   double monthlyTax = yearlyTax / 12;
   return monthlyTax;
}

/***********************************************************************
 * calculates the Actual Tithing and returns it.
 **********************************************************************/
double computeTithing(double income)
{
   double totalTithing = 0.1 * income;
   return totalTithing;
}

/***********************************************************************
 * Displays the user given values and calculates the remaining.
 **********************************************************************/
void display(double income, double budgetLiving, double actualTax,
             double actualTithing, double actualLiving, double actualOther)
{
   double budgetTax =  computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   double actualDifference = income - actualTax - actualTithing
      - actualLiving - actualOther;
   double budgetDifference = 0.0;
   
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income << "    $";
   cout << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << budgetTax << "    $";
   cout << setw(11) << actualTax << endl;
   cout << "\tTithing         $" << setw(11) << budgetTithing << "    $";
   cout << setw(11) << actualTithing << endl;
   cout << "\tLiving          $" << setw(11) << budgetLiving << "    $";
   cout << setw(11) << actualLiving << endl;
   cout << "\tOther           $" << setw(11) << budgetOther << "    $";
   cout << setw(11) << actualOther << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << budgetDifference  << "    $";
   cout << setw(11) << actualDifference << endl;
   return;
}

/**********************************************************************
* Monthly budget on the screen.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   displayWelcomeMessage();

   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();

   display(income, budgetLiving, actualTax,
           actualTithing, actualLiving, actualOther);
   return 0;
}
