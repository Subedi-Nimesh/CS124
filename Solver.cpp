/***********************************************************************
* Program:
*    Project 13, Sudoku solver
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following reads a file and displays a sudoku board.
************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
void interact();
void displayMenu();
bool editSquare(char board[9][9], char possible[]);
bool validateCoordinate(char letter, int number);
bool validatesValue(int value);
void computeValues(char board[9][9], int number, char letter, char possible[]);
void displayPossible(int number, char letter, char possible[]);
void saveAndExit(char board[9][9]);
void solveAndFinish(char board[9][9], char possible[]); 
int readFile(char board[][9]);
void displayBoard(char board[9][9]);

/************************************************************************
 * Prompts the user for their choice and calls the function accordingly. 
 ***********************************************************************/
void interact(char board[][9], char possible[])
{
   char choice;
   while (choice != 'q')
   {
      cout << "> ";
      cin >> choice;
      switch (tolower(choice))
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'd':
            displayBoard(board);
            break;
         case 'e':
            editSquare(board, possible);
            break;
         case 's':
            char letter;
            int number;
            cout << "What are the coordinates of the square: ";
            cin >> letter;
            cin >> number;
            computeValues(board, number, letter, possible);
            displayPossible(number, letter, possible);
            break;
         case 'q':
            saveAndExit(board);
            break;
         case 'f':
            solveAndFinish(board, possible);
            displayBoard(board);
            break;
         default:
            cout << "Invalid Options";
            break;
      }
      choice = tolower(choice);
   }
}

/**********************************************************************
 * Displays the options for the game.
 *********************************************************************/
void displayMenu()
{
   cout << "Options:" << endl;
   cout << "   ?  Show these instructions" << endl;
   cout << "   D  Display the board" << endl;
   cout << "   E  Edit one square" << endl;
   cout << "   S  Show the possible values for a square" << endl;
   cout << "   F  Finish the puzzle" << endl;
   cout << "   Q  Save and Quit" << endl;
   cout << endl;
}

/**********************************************************************
 * Displays the options for the game.
 *********************************************************************/
void solveAndFinish(char board[9][9], char possible[])
{
   for (int i = 0; i < 9; i++)
   {
      for(int j = 0; j < 9; j++)
      {
         cout << board[i][j] << endl;
         if (board[i][j] == '0')
         {
            for (int k = 0; k < 9; k++)
            {
               computeValues(board, i, j, possible);
               cout << possible[k];
               /*if (possible[k] != '0')
               {
                  board[i][j] = (char)k - 49;
                  break;
                  }*/
            }
            cout << endl;
         }
      }
   }
}

/**********************************************************************
 * Validates and edits squares in the array.
 *********************************************************************/
bool editSquare(char board[9][9], char possible[])
{
   char letter;
   int number;
   char value;
   cout << "What are the coordinates of the square: ";
   cin >> letter;
   cin >> number;

   bool validate = validateCoordinate(letter, number);
   if (validate == true)
   {
      if (board[number - 1][(int)tolower(letter) - 97] != '0')
      {
         cout << "ERROR: Square '" << (char)toupper(letter)
              << number << "' is filled\n";
         cout << endl;
         return false;
      }
      else
      {
         cout << "What is the value at '" << (char)toupper(letter)
              << number << "': ";
         cin >> value;
         bool validateValue = validatesValue(value);
         if (validateValue == false)
         {
            cout << "ERROR: Exceed value.\n";
            cout << endl;
            return false;  
         }
         else
         {
            computeValues(board, number, letter, possible);
            for (int i = 0; i < 9; i++)
            {
               if (value == possible[i])
               {
                  board[number - 1][(int)tolower(letter) - 97] = value;
                  cout << endl;
                  return true;
               }
            }
            cout << "ERROR: Value '" << value << "' in square '"
                 << (char)toupper(letter) << number << "' is invalid\n";
            cout << endl;
         }
      }
   }
   else
      return false;
   return true;
}

/**********************************************************************
 * Validates the value in the array.
 *********************************************************************/
bool validatesValue(int value)
{
   if ((value > 0) && (value < 10))
      return false;
   return true;
}

/**********************************************************************
 * Validates Coordinates in the array.
 *********************************************************************/
bool validateCoordinate(char letter, int number)
{
   if (((int)tolower(letter) < 97 ) || ((int)tolower(letter) > 105))
      return false;
   if ((number < 1) || (number > 9))
      return false;
   return true;
}

/**********************************************************************
 * Computes the possible values in the game.
 *********************************************************************/
void computeValues(char board[9][9], int number, char letter, char possible[])
{
   char num = '1';
   int count = 0;
   while (num <= '9')
   {
      possible[count] = num;
      num += 1;
      count++;
   }
   
   int i = number - 1;
   int j;

   for (j = 0; j < 9; j++)
   {
      for (int k = 0; k < 9; k++)
      {
         if (board[i][j] == possible[k])
         {
            possible[k] = '0';
         }
      }
   }

   j = (int)tolower(letter) - 97;
   for (i = 0; i < 9; i++)
   {
      for (int k = 0; k < 9; k++)
      {
         if (board[i][j] == possible[k])
         {
            possible[k] = '0';
         }
      }
   }
 
   i = (((int)tolower(letter) - 97) / 3) * 3;
   j = ((number - 1) / 3) * 3;

   int tempi = i + 3;
   int tempj = j + 3;
   
   for (i; i < tempi; i++)
   {
      for (j = ((number - 1) / 3) * 3; j < tempj; j++)
      {
         for (int k = 0; k < 9; k++)
         {
            if (board[j][i] == possible[k])
            {
               possible[k] = '0';
            }
         }
      }
   }
}

/**********************************************************************
 * Displays the possible value in the coordinates.
 *********************************************************************/
void displayPossible(int number, char letter, char possible[])
{
   bool firstChar = true;
   cout << "The possible values for '" << (char)toupper(letter)
        << number << "' are: ";
   
   for (int i = 0; i < 9; i++)
   {
      if (possible[i] != '0')
      {
         if (firstChar == true)
         {
            cout << possible[i];
            firstChar = false;
         }
         else
            cout << ", " << possible[i];
      }
   }
   cout << endl;
   cout << endl;
}

/**********************************************************************
 * Saves the array in a file and exit.
 *********************************************************************/
void saveAndExit(char board[9][9])
{
   char newFileName[256];
   cout << "What file would you like to write your board to: ";
   cin >> newFileName;
   
   ofstream fout(newFileName);
   if (fout.fail())
      cout << "Error" << endl;
   else
   {
      for (int i = 0; i < 9; i++)
      {
         for (int j = 0; j < 9; j++)
         {
            fout << board[i][j];
         }
      }
      fout.close();
      cout << "Board written successfully\n";
   }
   
}

/**********************************************************************
 * Reads the name of the file.
 *********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
}

/**********************************************************************
 * Reads the file.
 *********************************************************************/
int readFile(char board[][9])
{
   char fileName[256];
   getFileName(fileName);
   
   ifstream fin(fileName);

   if (fin.fail())
      return -1;

   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
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
void displayBoard(char board[9][9])
{
   cout << "   A B C D E F G H I" << endl;
   for (int i = 0; i < 9; i++)
   {
      cout << i + 1 << "  ";
      for (int j = 0; j < 9; j++)
      {
         if (j != 8)
         {
            if ((j == 2) || (j == 5))
            {
               if (board[i][j] == '0')
                  cout << " |";
               else
                  cout << board[i][j] << "|";
            }
            else
            {
               if (board[i][j] == '0')
                  cout << "  ";
               else
                  cout << board[i][j] << " ";
            }
         }
         else
         {
            if (board[i][j] == '0')
               cout << " ";
            else
               cout << board[i][j];
         }
      }
      if ((i == 2) || (i == 5))
         cout << "\n   -----+-----+-----";
      cout << endl;
   }
   cout << endl;
   return;
}

/**********************************************************************
 * Reads a file and displays the file in a 2D format.
 ***********************************************************************/
int main()
{
   char board[9][9];
   char possible[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   readFile(board);
   displayMenu();
   displayBoard(board);
   interact(board, possible);
   return 0;
}
