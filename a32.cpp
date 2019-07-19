/***********************************************************************
* Program:
*    Assignment 32, Letter Count
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following prompts the user for a letter and a sentence and
*    counts the reoccurring letter in the sentence.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * counts the number of reoccurring letter in a sentence.
 *********************************************************************/
int countLetters(char text[], char letter)
{
   int count = 0;
   for (int i = 0; text[i]; i++)
   {
      if (text[i] == letter)
         count++;
   }
   return count;
}

/**********************************************************************
 * Prompts the user for a word and a sentence and calls the functions
 * and displays the number of times the word occurs.
 ***********************************************************************/
int main()
{
   char text[256];
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);
   int count = countLetters(text, letter);
   cout << "Number of \'" << letter << "\'s: "
        << count << endl;
   return 0;
}
