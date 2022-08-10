// ISA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



const int  TempSeaLevel = 15; /*the base Temperture - the temperture in sea level*/
const float TheTemperatureDropPerMeter = 0.00649; /*the Temperature Drop per meter- from 11000-20000*/
const float TheTemperatureDropPerMeterOver20 = -0.001;  /*the Temperature Drop per meter- from 20000-25000*/
/// <summary>
/// this function calculate Temperature by a given altitude by ISA model.
/// </summary>
/// <param name="altitude"></param>
/// <returns></returns>
int ISACalc(int altitude) {

		//error!
		if (altitude > 25000 || altitude < 0) {
			throw "invalid value";
	

		}
		//The temperature changes with a temperature drop of 6.49 degrees per 1000 meters on this level
		else if (altitude < 11000) {
			int Temperature  = TempSeaLevel - (int)(altitude * TheTemperatureDropPerMeter);
			cout << ","<< Temperature << endl;
			return Temperature;

		}
		//the Temperature is constant in this level and eqeal to -56.5
		else if (altitude <= 20000) {
			cout <<","<< -56 << endl;
			return -56;

		}
		//The temperature changes with a temperature drop of -1.00 degrees per 1000 meters on this level

		else {
			int Temperature = -56 - (int)((altitude-20000) * TheTemperatureDropPerMeterOver20);
			cout << "," << Temperature << endl;
			return Temperature;
	
		}

}
/// <summary>
/// the function get name of I/O file a
/// nd ecxute each line in the file on ISAcalc function,
///  then its Compares the result against the expected output
/// and print to the console the result.
/// </summary>
/// <param name="fileName"></param>
void testing(string fileName) {
	ifstream fileTesting;
	fileTesting.open(fileName, ios::in | ios::out);

	if (!fileTesting) {
		throw"error while open file!";

	}
	else {
		string temperature;
		string altitude;
		getline(fileTesting, temperature);
		cout << "altitude" << "," << "temperature input ," << "temperature function " << endl;
		// Use a while loop together with the getline() function to read the file line by line
		while (!fileTesting.eof()) {
			getline(fileTesting, temperature, ',');
			getline(fileTesting, altitude);

			cout << altitude << ", " << temperature ;
			try
			{
			// Output the text from the file
			if (ISACalc(atoi(altitude.c_str())) == atoi(temperature.c_str())) {
			
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;

			}
		
		}

		catch (const char* exeption)
		{
			cout << exeption << endl;
		}


		}

		// Close the file
		fileTesting.close();

	}
}


int main()
{	
		testing("Test_3.txt");
	
}