/***********************************************************************
* Program:
*    Test 2, Compound Interest
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program calculates the compound interest of the
*    user entered investment, interest rate and year and add the
*    compound interest to the compound amount.
************************************************************************/

#include <iostream>
using namespace std;

float computeCompoundInterest(float investment, float interestRate, int years);
   
/*********************************************************************
 * Calculates the compound interest of the investment.
 *********************************************************************/
float computeCompoundInterest(float investment, float interestRate, int years)
{
   float compoundAmount = investment;
   float interestAmount = 0;
   for (int i = 0; i < years; i++)
   {
      interestAmount = compoundAmount * (interestRate / 100);
      compoundAmount += interestAmount;
   }
   return compoundAmount;
}

/*********************************************************************
 * Prompts the user for investment.
 *********************************************************************/
float getInvestment()
{
   float investment;
   cout << "How much are you investing? ";
   cin >> investment;
   return investment;
}

/*********************************************************************
 * Prompts the user for the interest rate.
 *********************************************************************/
float getInterestRate()
{
   float interestRate;
   cout << "What is the interest rate in percent? ";
   cin >> interestRate;
   return interestRate;
}

/*********************************************************************
 * Prompts the user for years of investment.
 *********************************************************************/
int getYears()
{
   int years;
   cout << "How long will this investment grow in years? ";
   cin >> years;
   return years;
}

/*********************************************************************
 * Display the compound amount of the investment.
 *********************************************************************/
void display(float compoundInterest, int years)
{
   cout << "At the end of " << years;
   cout << " years, you will have $" << compoundInterest << endl;
   return;
}

/**********************************************************************
 * prompts the user for investment, interest rate and years of investment
 * and calculates the compound amount.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float investment = getInvestment();
   float interestRate = getInterestRate();
   float years = getYears();
   float compoundInterest = computeCompoundInterest(investment,
                                                    interestRate, years);
   display(compoundInterest, years);
   return 0;
}

