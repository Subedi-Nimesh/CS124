/***********************************************************************
* Program:
*    Assignment 26, Handling Files
*    Brother Comeau, CS124
* Author:
*    Nimesh Subedi
* Summary: 
*    the following program reads a file and calculates average of the
*    sum of numbers in the file.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void display(float average);
void getFileName(char fileName[]);
float readFile(char fileName[]);

/*****************************************************************
 * The following Function reads the name of the file.
 ****************************************************************/
void getFileName(char fileName[])
{
   ofstream fout;
   cout << "Please enter the filename: ";
   cin >> fileName;
   fout.open(fileName);
}

/*****************************************************************
 * The following Function reads the data in the file.
 ****************************************************************/
float readFile(char fileName[])
{
   ifstream fin(fileName);
   if (fin.fail())
      return 0;
   float data;
   float sum = 0;
   int count = 0;
   while (fin >> data)
   {
      sum += data;
      count++;
   }
   fin.close();
   float average = sum / count;
   average = (average * 10 + 5) / 10;
   if (count != 10)
      return 0;
   return average;
}


/*****************************************************************
 * The following Function displays the average.
 ****************************************************************/
void display(int average)
{
   cout << "Average Grade: " << average << "%" << endl;
   return;
}

/*************************************************************************
 * prompts the user for name of the file and displays the average.
 ************************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   int average = readFile(fileName);
   if (average != 0)
      display(average);
   else
      cout << "Error reading file \"" << fileName << "\"" << endl;
   return 0;
}
