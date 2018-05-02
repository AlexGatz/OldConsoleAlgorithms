// RepeatDeleter.cpp : main project file.
/*

Created by: Alex J. Gatz
Date: 2/10/14

Description: Takes input from the user of type Char and places it into an array. If there are any
letters in the array that are repeated it will delete them and close in the remaining space.

*/

#include "stdafx.h"

void getInput(char a[], int& length);
//Uses a while loop to take input from the user and counts
// how many char's have been input.

void deleteRepeats(char a[], int& length);
//Steps through each letter and tests it against each other letter
// in a sort of cascade to find each double and then remove it.

void output(char a[], int length);
//Uses a while loop until the length has been reached to print
// only the used pieces of the array.

void newLine();
//Clears the stream.

const int maxSize = 50;
char letters[maxSize];
int length = 0;
//Globals
 
using namespace System;

int main(array<System::String ^> ^args)
{
	char done = 'y';
	while(done != 'n')
	{
		getInput(letters, length);
		deleteRepeats(letters, length);
		output(letters, length);

		newLine();
		cout << "\n\nWould you like to continue? (y/n)\n";
		cin >> done;
		cout << endl;
	}

    return 0;
}

void getInput(char a[], int& length)
{
	
	int i = 0, j = 0;
	char c = ' ';

	for(j = 0; j <= maxSize; j++)
	{
		a[j] = ' ';
	}
	//Array Initilization to a blank space.
	cout << "Please input a string of letters that you would like to have accessed.\n"
		<< "Press enter when you are done.\n";
	cout << "String: ";
	cin >> a;
	cout << endl;

	while(c != '\0')
	{
		c = a[i];
		i++;
	}

	length = i-1; //Because it is also counting the '\0' and array numbering starts at 0.
}

void deleteRepeats(char a[], int& length)
{
	int num = length;
    int start = 0;

    while(start != num)
    {
        char test = a[start];
        for(int i = start+1; i <= num;i++)
        {
            if(test==a[i])
            {
                for(int j = i;j<num;j++)
                    {
                    a[j] = a[j+1];
                    }
                num-=1;
				start-=1;
            }
        }
    start +=1;
    }
    length = num;
}

void output(char a[], int length)
{
	int i = 0;
	cout << "Here is your string with all of the doubles removed.\n";

	while(i < length)
	{
		cout << a[i] << " ";
		i++;
	}
}

void newLine()
{
	char symbol;
	do
	{
		cin.get(symbol);
	}while (symbol != '\n');
}


