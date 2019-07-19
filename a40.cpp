/***********************************************************************
* Program:
*    Assignment 40, Tic-Tac-Toe
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following reads a file and displays the file in a 2D format.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Reads the name of the file.
 *********************************************************************/
void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
}

/**********************************************************************
 * Reads the file.
 *********************************************************************/
int readFile(char board[][3])
{
   char fileName[256];
   getFileName(fileName);
   
   ifstream fin(fileName);

   if (fin.fail())
      return -1;
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         fin >> board[i][j];
      }
   }
      
   fin.close();
   return 0;  
}

/**********************************************************************
 * Displays the board in 2D format.
 *********************************************************************/
void display (const char (&board)[3][3])
{
   char newFileName[256];
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board[i][j] == 'X')
            cout << " X ";
         else if (board[i][j] == 'O')
            cout << " O ";
         else
            cout << "   ";
         if (j != 2)
            cout << "|";
      }
      if (i != 2)
         cout << "\n---+---+---\n";
   }
   cout << endl;
   
   cout << "Enter destination filename: ";
   cin >> newFileName;
   
   ofstream fout(newFileName);
   if (fout.fail())
      cout << "Error" << endl;
   else
   {
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            fout << board[i][j];
         }
      }
      fout.close();
      cout << "File written" << endl;
   }
   return;
}

/**********************************************************************
 * Reads a file and displays the file in a 2D format.
 ***********************************************************************/
int main()
{
   char board[3][3];
   int count = readFile(board);
   if (count != -1)
      display(board);
   return 0;
}
