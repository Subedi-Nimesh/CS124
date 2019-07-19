/**********************************************************************
* Program:     
*    Test 1, Finals Preparation
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program prompts the user for his final score in
*    percentage points and then displays the message according to
*    his score.
**********************************************************************/
#include <iostream>
using namespace std;

float getScore();
void displayReady();
void displayNotReady();

/**********************************************************************
 * Displays if the user is ready for the finals or not.
 ***********************************************************************/
int main()
{
   float score = getScore();
   if (score < 85)
      displayNotReady();
   else
      displayReady();
   return 0;
}

/*********************************************************************
 * Prompts the user for score in percentage points.
 *********************************************************************/
float getScore()
{
   float score;
   cout << "What was your score on the practice final in percentage points? ";
   cin >> score;
   return score;
}

/*********************************************************************
 * Display the message that the user is ready.
 *********************************************************************/
void displayReady()
{
   cout << "\tYou are ready to take the test!\n";
}
   
/*********************************************************************
 * Display the message that the user is ready.
 *********************************************************************/
void displayNotReady()
{
   cout << "\tMore studying is required.\n";
}
