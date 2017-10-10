#pragma once
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

/*
 * LinearEquation Constant Variables
 */
const int TOTALXYCOORDINATES = 4;

/*
 * LinearEquation Class Definition
 */
class LinearEquation {
public:
	// Construct a Linear Equation object with 6 arguments
	LinearEquation(double argA, double argB, double argC, double argD, double argE, double argF);

	// Construct a default Linear Equation
	LinearEquation();

	// Return the value of instance variables a-f
	double getA();
	double getB();
	double getC();
	double getD();
	double getE();
	double getF();

	// Set the value of instance variables a-f
	void setA(double argA);
	void setB(double argB);
	void setC(double argC);
	void setD(double argD);
	void setE(double argE);
	void setF(double argF);

	// Return true if the lines within the Linear Equation ever touch each other
	bool isSolvable();

	// Return the x-coordinate of the point where the lines touch
	double getX();

	// Return the y-coordinate of the point where the lines touch
	double getY();

private:
	// variables to hold the contents of the Linear Equation System
	double a, b, c, d, e, f;
};