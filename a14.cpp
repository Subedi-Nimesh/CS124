/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The function in the program will return value to the
*    main().
************************************************************************/
#include <iostream>
using namespace std;

/**********************************************************************
* Creates a function called questionPeter and returns null.
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother";
   cout << " sin against me, and I forgive him?\n";
   cout << "Till seven times?\n";
   return;
}

/**********************************************************************
* Creates a function called responseLord and returns Lord's response.
**********************************************************************/
int responseLord()
{
   return 7 * 70;
}

/**********************************************************************
* Displays Peter's question and Lord's response by calling a function.
**********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";
   return 0;
}
