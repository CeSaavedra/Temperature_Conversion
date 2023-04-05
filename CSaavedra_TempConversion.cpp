#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

//Prototypes
void convertCels(double celisus);
void displayTitle();

//Constants
const int MIN_TEMP = -39;
const int BASE_CASE = -40;
const double FAREN_ADDITION = 32.0;
const double FAREN_NUMERATOR = 9.0;
const double FAREN_DENOMINATOR = 5.0;
const double KELVIN_ADDITION = 273.15;
const int COUNTER_ADDITION = 1;
const int CELSIUS_SUBTRACTION = 5;
const int DECIMAL_PLACE = 1;
const int WIDTH = 10;

//Void function to convert celsisus using double value parameter
void convertCels(double celsius) {

	//Conversions
	double faren = (((FAREN_NUMERATOR/FAREN_DENOMINATOR) * celsius) + FAREN_ADDITION);
	double kelvin = celsius + KELVIN_ADDITION;

	//Ensures the header is only sent once
	static int counter = 0;
	if (counter == 0) {
		cout << fixed << "\n\n Temperature Conversion Chart\n -----------------------------\n\n" <<
			setw(WIDTH) << "Celsius" << setw(WIDTH) << "Farenheit" << setw(WIDTH) << "Kelvin\n";
	}

	//Displays formatted conversions
	cout << fixed << setprecision(DECIMAL_PLACE) << endl << setw(WIDTH) << celsius << setw(WIDTH) << faren << setw(WIDTH) << kelvin;

	//If celsius is less than -40 exit
	if (celsius < MIN_TEMP) {
		cout << "\n\nThank you for using the program!\n";

	//If celsius is greather than -40
	}else {
		//Recursively calls function with the celsius subtracted
		celsius -= CELSIUS_SUBTRACTION;
		//Ensures header is only sent once
		counter += COUNTER_ADDITION;
		//If celsius is greater than -40, use the function recursively
		if (!(celsius < MIN_TEMP)) {
			convertCels(celsius);
		}
	}
}
//Void display title function
void displayTitle() {
	cout << "\n\tWelcome to the Temperature Conversion Program\n\n";
}

//Main function
int main() {

	displayTitle();

	//Local variables
	double celsius = 0;
	bool validated = false;

	//Validation loop
	while (!validated) {
		//Prompt user for input
		cout << "Enter the starting temperature in degrees Celsius: ";
		cin >> celsius;

		//If input is valid then exit loop, else repeat loop until valid
		if (celsius < MIN_TEMP) {
			cout << "Error - Please enter a value greater than " << BASE_CASE << "!\n";
		
		}else {
			validated = true;
		}
	}
	
	//Use recursive function
	convertCels(celsius);
	cout << "\n\nThank you for using the program!\n";
}