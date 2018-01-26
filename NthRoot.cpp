#include <iostream>
#include <stdlib.h>

using namespace std;

//Calculate a power
float pow (float base, int exponent) {
	int i = 0;
	float power = 1;
	
	while (i < exponent) {
		power *= base;
		i++;
	}
	
	return power;
}

//Take the absolute value
float abs (float num) {
	if (num < 0) {
		num *= -1;
	}
	
	return num;
}

int main (const int argc, const char* const argv[]) {
	const int MAX_ITERATIONS = 1000;
	
	//Validate input
	if (argc < 4) {
		cerr << "Error: Unable to compute Nth root because not enough arguments were provided." << endl;
	} else {
		if (argc > 4) {
			cerr << "Warning: Expecting three command-line arguments; ignoring extraneous arguments." << endl;
		}
		
		float number = atof(argv[1]);
		int root = atoi(argv[2]);
		float precision = atof(argv[3]);
		
		//Validate input
		if (number < 0 && root % 2 == 0) {
			cerr << "Error: Unable to compute Nth root because the even root of a negative number was requested." << endl;
		} else if (root < 2) {
			cerr << "Error: Unable to compute Nth root because the requested root is less than 2." << endl;
		} else if (precision < 0) {
			cerr << "Error: Unable to compute Nth root because the requested precision is negative." << endl;
		} else {
			float guessRoot = number / 2.0;
			int iterations = 0;
			float guessPrecision = abs((number - pow(guessRoot, root)) / number);
			
			while (guessPrecision > precision && iterations < MAX_ITERATIONS) {
				guessRoot = (((root - 1) * guessRoot) + (number / pow(guessRoot, root - 1))) / root;
				
				guessPrecision = abs((number - pow(guessRoot, root)) / number);
				
				iterations++;
			}
			
			cout << "Root(" << number << "," << root << ") = " << guessRoot << endl;
			cout << "(with precision " << abs(guessPrecision) << ")" << endl;
		}
	}
	
	return 0;
}