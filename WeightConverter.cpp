// WeightConverter.cpp : main project file.


/*

Created by: Alex J. Gatz
Description: Takes weight in lbs and ounces and outputs the weight in kilograms and grams.

Note: I would like to use the method "truncate()" (rounds to the nearest 0) in place of 
"floor()" (always rounds down) for more accurate results but it is not identified in 
this version of visual stuidio due to the fact thatvisual studio 2010 uses c++ 99' 
instead of the more recent c++ 11'. 

*/



//See stdafx.h header file for the list of headers used.
#include "stdafx.h"

using namespace System;


//Function Initialization:

//Gets the information.
//Uses the globals "pounds" and "ounces" and assigns them to user input. 
void getInput(double& pounds, double& ounces);

//Converts to kilos.
//Takes "pounds" and "ounces" and returns their metric equivalents as "kilos" and "grams".
double convertToKilos(double& pounds, double& ounces);

//Displays the information to the screen.
//Takes "kilos" and "grams" and displays those values to the cmd.
void displayConversion(double kilos, double grams);


//Conversion Constants
const double poundToKilo = 2.2046;
const double kiloToGrams = 1000.00;
const double ouncesToPounds = 16.00;

//Globals
double kilos = 0.0, grams = 0.0;

int main(array<System::String ^> ^args)
{
	//Local Variables
	double pounds = 0.0, ounces = 0.0;
	char done = 'y';

	//Continue to loop the program until the user does not want to continue (enters n).
	while (done != 'n')
	{
	
		getInput(pounds, ounces);
		convertToKilos(pounds, ounces);
		displayConversion(kilos, grams);

		cout << "\n\nWould you like to continue? (y/n)\n";
		cin >> done;
		cout << endl;
	}

	return 0;
}

void getInput(double& pounds, double& ounces)
{
	//Ask user for input.
	cout << "Only input numbers!!!\n" 
		 << "\nWhat is the standard weight you would like convert to metric?\n"
		 << "Enter pounds:";
	cin >> pounds;
	cout << "Now ounces:";
	cin	>> ounces;
}

double convertToKilos(double& pounds, double& ounces)
{
	//Calculate the conversion.
	double convertedPounds = 0.0;

	//Converts the excess ounces into pounds
	convertedPounds = ounces/ouncesToPounds;
	//Combines the extra pounds with the pounds from user input
	pounds = convertedPounds + pounds;
	//Takes the floored value of the pounds converted to kilos
	//"Floored" meaning it dropped numbers after the decimal.
	kilos = floor(pounds/poundToKilo);
	//Again takes the floored value, but this time uses only the numbers after the decimal
	//by removing the floor value.
	grams = (pounds/poundToKilo - floor(pounds/poundToKilo)) * kiloToGrams;


	return kilos, grams;
}

void displayConversion(double kg, double g)
{
	//Properties
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Show the results.
	cout << "\nYour converted weight is: " << kg << "kg" << " and " << g << "g";
}