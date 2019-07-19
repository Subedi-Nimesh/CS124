/***********************************************************************
* Program:
*    Assignment 41, Memory Allocation
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following reads a text and allocates memory.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Reads a text and allocates memory.
 ***********************************************************************/
int main()
{
   int numOfChar;
   cout << "Number of characters: ";
   cin >> numOfChar;
   int totalNumOfChar = numOfChar + 1;
   if (numOfChar > 0)
   {
      char text[numOfChar];
      cout << "Enter Text: ";
      cin.ignore();
      cin.getline(text, totalNumOfChar);
     
      cout << "Text: " << text << endl;
   }
   else
      cout << "Allocation failure!" << endl;
   return 0;
}
