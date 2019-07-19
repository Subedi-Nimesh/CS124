/***********************************************************************
* Program:
*    Project 09, Mad lib
*    Brother Comeau, CS 124
* Author:
*    Nimesh Subedi
* Summary:
* The following program prompts the user for question from the
* mad lib file.
************************************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void getFileName(char fileName[]);
int readFile(char story[][32]);
void askQuestions(char ask[]);

/************************************************************************
 * Reads the name of the file given by the user.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/************************************************************************
 * Reads the contents inside the file.
 ***********************************************************************/
int readFile(char story[][32])
{
   char fileName[256];
   getFileName(fileName);
   
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Couldn't find file" << endl;
      return -1;
   }
   
   
   int countWords = 0;
   while (fin >> story[countWords])
   {
      if (story[countWords][0] == '<' && isalpha(story[countWords][1]))
         askQuestions(story[countWords]);
 
      countWords++;
   }
   fin.close();
   return countWords;
   
}

/************************************************************************
 * Changes the words in the mad lib program to questions to be
 * asked to the user.
 ***********************************************************************/
void askQuestions(char ask[])
{
   if (ask[0] != '<')
      return;
   
   cout << "\t" << (char)toupper(ask[1]);
   int i = 2;
   while (ask[i] != '>')
   {
      if (ask[i] == '_')
         cout << " ";
      else
      {
         cout << (char)tolower(ask[i]);
      }
      i++;
   }

   cout << ": ";

   
   cin.ignore();
   cin.getline(ask, 32);

   return;
}

/************************************************************************
 * Reads the story and then prompts the questions and at last displays
 * the thank you message.
 ***********************************************************************/
int main()
{
   char story[256][32];
   readFile(story);   
   cout << "Thank you for playing." << endl;
   return 0;
}
