/**
  * Name: Rafael Teles Lazaro Lucchesi, Student #: 100273456
  * Class: CPSC 1160
  * Assignment #2
  * Description: 
  * 1. Write an Algorithm to implement Newton’s Method;
  * 2. Write a square root function;
  * 3. Write a C++ program that uses mySqrt and solves the quadratic equation;
  * 4. Your input is provided in a txt file (newton.txt);
  * 5. Put a Counter in the mySqrt function and each time that the function is called it should print to the Console the input values,
  *		the square root and the number of iterations that it performs to compute the square root.
  * 6. Print the two roots of the quadratic equation to the Console, if they exist. Otherwise print an appropriate message.
  *
  * I pledge that I have completed the programming assignment independently.
  * I have notcopied the code from a student or any other source.
  * I have not given my code to any student.
  *
  * Rafael Lucchesi, May 09, 2017.
  */

#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;

/*
 * Prototypes
 */
double mySqrt(double a, double precision);
// Calculates the Square root of a double input.
// precondition: define the precision of the square root output.

double bhaskara(double a, double b, double deltaSqrt);
// Solves the quadratic equation of the format ax^2 + bx + c = 0.
// precondition: a cannot be 0, deltaSqrt must be already computed to be used as input.
// postcondition: in order to produce both roots (when thats the case), the function
//	must be called twice (+ and - deltaSqrt).


void main() {
	// Variables
	double acc, a, b, c, delta;
	fstream input;

	// Open input file
	input.open("newton.txt");
	if (input.fail()) {
		cout << "ERROR openning file" << endl;
		system("pause");
		exit(1);
	}

	// Text file iteration
	while (!input.eof()) {
		input >> acc >> a >> b >> c;
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
		delta = b * b - (4 * a * c);
		
		// Decide the number of roots the functions has
		if (delta > 0) {
			cout << "Solution 1: " << bhaskara(a, b, mySqrt(delta, acc)) << endl;
			cout << "Solution 2: " << bhaskara(a, b, -mySqrt(delta, acc)) << endl;
		}
		else if (((b * b - (4 * a * c)) == 0)) {
			cout << "Solution is: " << bhaskara(a, b, mySqrt(delta, acc));
		}
		else {
			cout << "The equation does not have a real root" << endl;
		}
		cout << endl;
	}
	system("pause");
	exit(1);
}

/*
 * Calculates the Square root of a non-negative double.
 * precondition: define the precision of the square root output.
 */
double mySqrt(double a, double precision) {
	double xInitial = a / 2, xFinal, epsilon = 1;
	int count = 0;
	
	// implementation of Newton's method to find the square root
	while (epsilon > precision) {
		count++;
		xFinal = 0.5 * (xInitial + a / xInitial);
		epsilon = abs(xFinal - xInitial);
		xInitial = xFinal;
	}

	cout << "Input, precision: " << a << ", " << precision << ".\tIteration(s): " << count << ".\tSqrt: " << xFinal << endl;
	return xFinal;
}

/*
 * Solves the quadratic equation of the format ax^2 + bx + c = 0.
 * precondition: a cannot be 0, deltaSqrt (sqrt(b^2 - 4ac)) must be already computed
 *	to be used as input.
 * postcondition: in order to produce both roots (when thats the case), the function
 *  must be called twice (+ and - deltaSqrt).
*/
double bhaskara(double a, double b, double deltaSqrt) {
	return (-b + deltaSqrt) / (2 * a);
}