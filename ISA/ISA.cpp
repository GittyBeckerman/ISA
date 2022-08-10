// ISA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int  TempSeaLevel = 15;
const float TheTemperatureDropPerMeter = 0.0065;
int ISACalc(int high) {
	try
	{

		if (high > 25000 || high < 0) {
			throw("error");
				return 0;

		}
		else if (high < 11000) {
			int h = TempSeaLevel - (int)(high * TheTemperatureDropPerMeter);
			return h;
		}
		else if (high < 20000) {
			return -56;
		}
		
	}





	catch (string exeption)
	{
		cout << exeption;
	}
}
void testing(string fileName) {
	ifstream fileTesting;
	fileTesting.open(fileName, ios::in | ios::out);
	cout << fileName;
	if (!fileTesting) {
		throw("error while open file!");
		cout << "gghfh";
	}
	else {
		string temperature;
		string altitude;
		getline(fileTesting, temperature);
		// Use a while loop together with the getline() function to read the file line by line
		while (!fileTesting.eof()) {
			getline(fileTesting, temperature, ',');
			getline(fileTesting, altitude);
			cout << temperature<<" " << altitude;
			
		/*	fileTesting >> temperature;
			fileTesting >> altitude;*/
			//cout << temperature << altitude;

			// Output the text from the file
			if (ISACalc(atoi(altitude.c_str())) == atoi(temperature.c_str())) {
				cout << "true" << endl; /*temperature
					<< altitude << endl;*/
			}
			else {
				cout << "false" << endl;
			}
		}

		//// Close the file
		//MyReadFile.close();

		//while (!fileTesting.eof()) {
		//        fileTesting >> line;
		//        cout << line << endl;
		//}
	}
}


int main()
{
	//cout << ISACalc(310);

	testing("Test_2.txt");
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
