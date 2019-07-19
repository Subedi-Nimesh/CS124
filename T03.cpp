/***********************************************************************
* Program:
*    Test 3, Reverse List
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    The following program reads numbers from a file and prints
*    The list in a reverse order.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
int readFile(float money[]);
void display(float money[], int count);
   
/*********************************************************************
 * Prompts the user for the name of the file.
 *********************************************************************/
void getFileName(char fileName[])
{
   cout << "Enter the filename: ";
   cin >> fileName;
}

/*********************************************************************
 * reads the file and validates it.
 *********************************************************************/
int readFile(float money[])
{
   char fileName[256];
   getFileName(fileName);

   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "Error opening file " << fileName << endl;
      return -1;
   }
   
   int count;
   while (fin >> money[count])
      count++;
   fin.close();
   return count;
}

/**********************************************************************
 * Display the list in reverse order.
 *********************************************************************/
void display(float money[], int count)
{
   cout << "New order:" << endl;
   for (int i = count - 1; i >= 0 ; i--)
   {
      cout << money[i] << endl;
   }
   return;
}

/**********************************************************************
 * prompts the user for file name and reads the data then reverses it.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float money[100];
   int count;
   count = readFile(money);
   if (count != -1)
      display(money, count);
   return 0;  
}

