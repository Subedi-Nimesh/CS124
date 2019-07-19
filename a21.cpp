/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    the following program is just the function of a program
*    meant to show the connection between them.
************************************************************************/
#include <iostream>
using namespace std;

float promptDevalue();
float promptInsurance();
float promptParking();
float promptMileage();
float promptGas();
float promptRepairs();
float promptTires();
void display(float costPeriodic, float costUsage);

/****************************************************************
 * the following function calls other required functions
 ***************************************************************/
float getPeriodicCost()
{
   float costPeriodic;
   promptDevalue();
   promptInsurance();
   promptParking();
   return costPeriodic;
}
float promptDevalue()
{
   float cost;
   return cost;
}
float promptInsurance()
{
   float cost;
   return cost;
}
float promptParking()
{
   float cost;
   return cost;
}

/****************************************************************
 * the following function calls other required functions
 ***************************************************************/
float getUsageCost()
{
   float costUsage;
   promptMileage();
   promptGas();
   promptRepairs();
   promptTires();
   return costUsage;
}
float promptMileage()
{
   float mileage;
   return mileage;
}

float promptGas()
{
   float cost;
   return cost;
}

float promptRepairs()
{
   float cost;
   return cost;
}

float promptTires()
{
   float cost;
   return cost;
}

void display(float costPeriodic, float costUsage)
{
   cout << "Success\n";
}


/**********************************************************************
 * the main calls the other functions
 ***********************************************************************/
int main()
{
   float costPeriodic = getPeriodicCost();
   float costUsage = getUsageCost();
   display(costPeriodic, costUsage);
   return 0;
}
