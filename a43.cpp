/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program converts char to float and then converts feet
*    To meters using command line
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/************************************************************************
 * The main converts the char into float and then changes foot to meters.
 ************************************************************************/
int main(int argc, char ** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1); 
   float fMeters;
   float meters;
   for (int i = 1; i < argc; i++)
   {
      fMeters = atof(argv[i]);
      meters = fMeters * 0.3048;
      cout << fMeters << " feet is " << meters << " meters" << endl;
   }
   return 0;
}
