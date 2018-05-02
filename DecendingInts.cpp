// DecendingInts.cpp : main project file.
/*

Created by: Alex J. Gatz
Date: February 6th, 2014
Description: Takes input from either the user or a file (as integer values), and
places them into decending order. 

*/

#include "stdafx.h"

void getInput(int a[], int& printLength);
//Asks user to either input a file name or integer values seperately. 
//If they choose to use a file, sends to openFile to ensure proper opening.

void openFile(string fileName);
//Takes in the file name and tests that is was opened properly.

void decendInts(int a[], int length);
//Sorts the array by comparing each values and placing it in the proper order. 
// while decrimenting the length being used. 
//Returns the array in its proper order, and outputs the adjusted length. 

void countInts(int a[], int& printLength);
//Counts how many of each integer there are.
//Modifies the array histo[] which holds the data for each of the integers.
//Each time a number is copied over, a counter is incresed to determine the frequency 
// of that number in the original data list. 

void deleteRepeats(int a[], int hist[], int length);
//Removes the values that there are multiples of and only leaves one of each.

void outputToScreen(int a[], int hist[], int length);
//Steps through and outputs each value in the array in histogram table. 
//The table will include the numbers that were input and the frequency of eacy number. 
//The stepingis determined by the adjusted length value. 

void newLine();
//Clears the stream by writing over everything in it. 

//Globals:
const int arrayLength = 50;
int values[arrayLength];
int histo[arrayLength];
int printLength = 0; 
ifstream fileIn;


int main(array<System::String ^> ^args)
{    
	char done = 'y';
	while(done != 'n')
	{
		getInput(values, printLength);
		decendInts(values, printLength);
		deleteRepeats(values, histo, printLength);
		outputToScreen(values, histo, printLength);

		newLine();
		cout << "\n\nWould you like to continue? (y/n)\n";
		cin >> done;
		cout << endl;
	}
    return 0;
}

void getInput(int a[], int& printLength)
{
	int i = 0, next = 0;

	string ans = "", fileName = "";
	cout << "This program is meant to take a list of numbers.\n"
		<< "\nIt will take the list, remove the duplicate values,"
		<< " count each of the duplicatedvalues, and will print "
		<< "a histogram of the numbers in decending order"
		<< " with the \nfrequency of each value.\n"
		<< endl;

	cout << "Would you like to input the list via a file, or type the information?\n";
	cin >> ans;
	cout << endl;
	newLine();
	if(ans == "file") //Needs to be converted to upper or lower? Perhaps just use "f" or "F".
	{
		/*cout << "Please type the exact path of the file you would like to open.\n"
			<< "(Note: Case sensitive.)\n";
		cin >> fileName; 
		openFile(fileName);

		do
		{
			fileIn >> a[printLength];
			printLength++;
		}while(a[printLength] != '\0');*/	
	}
	else
	{
		cout << "Please type the values in a list enter a \n";
		
		do
		{
			cin >> a[printLength];
			printLength++;
		}while(a[printLength] != '\0');		
	}
	cout << endl << endl;
}

void newLine()
{
	char symbol;
	do
	{
		cin.get(symbol);
	}while (symbol != '\n');
}

void openFile(string file)
{
	fileIn.open(file);
	while(fileIn.fail())
	{
		cout << "File could not be opened properly, please try again.\n"
			<< "Please type the exact path of the file you would like to open."
			<< "(Note: Case sensitive.)\n";
		cin >> file;
		fileIn.open(file);
	}
}

void decendInts(int a[], int length)
{
	int i, j, temp;

	for(i=1; i < length; i++)
	{
		j=i;
		while(j > 0 && a[j - 1] < a[j])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}
}

void countInts(int a[], int& printLength)
{
	int n = 0, i = 0;

	while(n != '\0')
	{
		n = a[i];
		i++;
	}
	printLength = i;
}

void deleteRepeats(int a[], int hist[], int length)
{
	int num = length;
    int start = 0;

    while(start != num)
    {
        int test = a[start];
        for(int i = start+1; i <= num;i++)
        {
            if(test == a[i])
            {
                for(int j = i; j<num; j++)
                    {
                    a[j] = a[j+1];
                    }
                num--;
				start--;
				hist[start]++;
            }
        }
    start ++;
    }
    length = num;
}

void outputToScreen(int a[], int hist[], int printableValues)
{
	cout << "Here is a nice table of the data you input!! Thanks :D\n" << endl;

	cout << "Entries" << setw(12) << "Frequency\n";

	for(int i = 0; i < printableValues; i++)
	{
		cout << a[i] << setw(5) << "|" << setw(5) << hist[i] << endl;
	}
}