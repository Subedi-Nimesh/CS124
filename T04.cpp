/***********************************************************************
* Program:
*    Test 4, Count Letters and Digits
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program prompts the user for some text and then count
*    the numbers of text, symbols, digits and spaces. 
************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void getText(char text[]);
int countLetters(char text[]);
int countDigits(char text[]);
int countSymbols(char text[]);
int countSpaces(char text[]);
void display(int isLetters, int isDigits, int isSymbols, int isSpaces);

/*********************************************************************
 * Prompts the user for some text.
 *********************************************************************/
void getText(char text[])
{
   cout << "Please enter some text: ";
   cin.getline(text, 99);
}

/*********************************************************************
 * Counts the number of letters in the user input text.
 *********************************************************************/
int countLetters(char text[])
{
   int num = 0;
   for (int i = 0; text[i]; i++)
   {
      if (isalpha(text[i]))
         num++;
   }
   return num;
}

/*********************************************************************
 * Counts the number of Digits in the user input text.
 *********************************************************************/
int countDigits(char text[])
{
   int num = 0;
   for (int i = 0; text[i]; i++)
   {
      if (isdigit(text[i]))
         num++;
   }
   return num;
}

/*********************************************************************
 *  Counts the number of Symbols in the user input text.
 *********************************************************************/
int countSymbols(char text[])
{
   int num = 0;
   for (int i = 0; text[i]; i++)
   {
      if (ispunct(text[i]))
         num++;
   }
   return num;
}

/*********************************************************************
 *  Counts the number of Spaces in the user input text.
 *********************************************************************/
int countSpaces(char text[])
{
   int num = 0;
   for (int i = 0; text[i]; i++)
   {
      if (isspace(text[i]))
         num++;
   }
   return num;
}

/**********************************************************************
 * Display the list of numbers in a table format.
 *********************************************************************/
void display(int isLetters, int isDigits, int isSymbols, int isSpaces)
{
   cout << "\tLetters: " << isLetters << endl;
   cout << "\tDigits:  " << isDigits << endl;
   cout << "\tSymbols: " << isSymbols << endl;
   cout << "\tSpaces:  " << isSpaces << endl;
   return;
}

/**********************************************************************
 * Prompts the user for some text and counts the Letters, Digits,
 * Symbols and Spaces.
 ***********************************************************************/
int main(int argc, char **argv)
{
   char text[256];
   int isLetters;
   int isDigits;
   int isSymbols;
   int isSpaces;
   
   if (argc - 1 == 0)
   {
      getText(text);
      isLetters = countLetters(text);
      isDigits = countDigits(text);
      isSymbols = countSymbols(text);
      isSpaces = countSpaces(text);
   }
   else
   {
      for (int i = 0; argv[i]; i++)
      {
         isLetters = countLetters(argv[i]);
         isDigits = countDigits(argv[i]);
         isSymbols = countSymbols(argv[i]);
         isSpaces = countSpaces(argv[i]);
      }
   }
   display(isLetters, isDigits, isSymbols, isSpaces);
   return 0;  
}

