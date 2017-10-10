/**
* Name: Rafael Teles Lazaro Lucchesi, Student #: 100273456
* Class: CPSC 1160
* Assignment #7
* Description:
* 1. Design a class named LinearEquation for a 2x2 system of linear equations. The class contains:
*	Private data fields a, b, c, d, e, and f;
*	A constructor with the arguments a, b, c, d, e, and f;
*	Six get functions for a, b, c, d, e, and f;
*	A function named isSolvable() that returns true if ad - bc != 0;
*	Functions getX() and getY() that return the solution for the equation;
* 2. Write a program that reads four line segment endpoints from a file (coords.txt), and displays the intersection point if it exists.
*
* I pledge that I have completed the programming assignment independently.
* I have notcopied the code from a student or any other source.
* I have not given my code to any student.
*
* Rafael Lucchesi, Jun 27, 2017.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "LinearEquation.h"
using namespace std;

int main() {
	// Instanciate a LinearEquation object using a no-arg constructor
	LinearEquation myLE;
	
	// Arrays to hold Line1 and Line2 data
	double* line1 = new double[TOTALXYCOORDINATES + 1];
	double* line2 = new double[TOTALXYCOORDINATES + 1];
	
	// File Input
	fstream file;
	file.open("coords.txt");

	if (file.fail()) {
		cout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}

	while (!file.eof()) {
		// Load Array with Line1's x- and y-coordinates
		for (int i = 0; i < TOTALXYCOORDINATES; i++) {
			file >> line1[i];
		}
		// Load Array's last index with Line1's slope
		line1[TOTALXYCOORDINATES] = (line1[3] - line1[1]) / (line1[2] - line1[0]);

		// Load Array with Line2's x- and y-coordinates		
		for (int i = 0; i < TOTALXYCOORDINATES; i++) {
			file >> line2[i];
		}
		// Load Array's last index with Line2's slope
		line2[TOTALXYCOORDINATES] = (line2[3] - line2[1]) / (line2[2] - line2[0]);

		// Set myLinearEquation data fields
		myLE.setA(-line1[TOTALXYCOORDINATES]);
		myLE.setB(1);
		myLE.setC(-line2[TOTALXYCOORDINATES]);
		myLE.setD(1);
		myLE.setE(line1[1] - line1[TOTALXYCOORDINATES] * line1[0]);
		myLE.setF(line2[1] - line2[TOTALXYCOORDINATES] * line2[0]);

		// Display Output
		cout << "Line1 from (" << line1[0] << ", " << line1[1] << ") to (" << line1[2] << ", " << line1[3] << ") produced equation: " << myLE.getA() << "x + " << myLE.getB() << "y = " << myLE.getE() << endl;
		cout << "Line2 from (" << line2[0] << ", " << line2[1] << ") to (" << line2[2] << ", " << line2[3] << ") produced equation: " << myLE.getC() << "x + " << myLE.getD() << "y = " << myLE.getF() << endl;
		if (myLE.isSolvable()) {
			cout << "Both lines intercept at (" << myLE.getX() << ", " << myLE.getY() << ")." << endl;
		}
		else {
			cout << "The equation has no solution therefore the corresponding lines do not intersect." << endl;
		}
		cout << endl;
	}

	// Release memory
	delete[] line1;
	delete[] line2;

	system("pause");
	return 0;
}