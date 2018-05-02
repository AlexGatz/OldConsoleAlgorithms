// WindchillCalculator.cpp : main project file.
/*

Created By: Alex J. Gatz
Date: January 24th, 2014

Description:
	Asks user for the windspeed, temperature, and windchill index. Takes those values and calculates the windchill 
using the formula "W = 13.12 + 0.6215t - 11.37v^0.16 + 0.3965tv^0.016." 

*/

#include "stdafx.h"

using namespace System;


//Function Initialization:

//Asks for the user to input the windspeed and temperature in celcius. Prevents input for any temp greater than 10.
void getInput(double& windSpeed, double& tempC);

//Takes "windSpeed" and "tempC" and calculates the windchill index.
double calculateWindchill(double& windSpeed, double& tempC);

//Takes "windchill", "tempC", and "windspeed" than displays how each are related.
void displayInfo(double W, double temp, double speed);

//Global
double windchill = 0.0;

int main(array<System::String ^> ^args)
{
    //Local Variables
	double windSpeed = 0.0, tempC = 0.0;
	char done = 'y';

	//Continue to loop the program until the user does not want to continue (enters n).
	while (done != 'n')
	{
	
		getInput(windSpeed, tempC);
		calculateWindchill(windSpeed, tempC);
		displayInfo(windchill, tempC, windSpeed);

		cout << "\n\nWould you like to continue? (y/n)\n";
		cin >> done;
		cout << endl;
	}
    return 0;
}

void getInput(double& windSpeed, double& tempC)
{
	//Ask user for input.
	cout << "Only input numbers!!!\n" 
		 << "\nWhat is the temperature in degrees Celsius you would like to use?\n"
		 << "Enter temp: ";
	cin >> tempC;
	cout << endl;

	//Loop until the user inputs a number less than 10.
	while (tempC > 10)
	{
		cout << endl 
			<< "When the temperature is higher than 10, weird things happen that you shouldn't worry about... Try Again.\n\n"
			<< "Enter temp: ";
		cin >> tempC;
		cout << endl;
	}
	cout << "What was the wind speed when it was that temperature?\nInput as meters per second.\n"
		<< "Enter Wind Speed: ";
	cin	>> windSpeed;
	cout << endl;
}

double calculateWindchill(double& windSpeed, double& tempC)
{
	//Windchill Index formula.
	windchill = 13.12 + 0.6215 * tempC - 11.37 * pow(windSpeed, 0.16) + 0.3965 * tempC * pow(windSpeed, 0.016);

	return windchill;
}

void displayInfo(double W, double temp, double speed)
{
	//Properties
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Show the results.
	cout << "\nWith a temerature of " << temp << ", and a wind speed of "<< speed
		<< "\nthe Windchill Index is: " << W << " degrees Celcius" << endl;
}
