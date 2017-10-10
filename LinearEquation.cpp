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

#include "LinearEquation.h"

/*
 * LinearEquation implementation
*/

// Construct a Linear Equation object with 6 arguments
LinearEquation::LinearEquation(double argA, double argB, double argC, double argD, double argE, double argF) {
	a = argA;
	b = argB;
	c = argC;
	d = argD;
	e = argE;
	f = argF;
}

// Construct a default Linear Equation
LinearEquation::LinearEquation() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
}

// Return the value of the instance variables a
double LinearEquation::getA() {
	return a;
}

// Set the value of the instance variables a
void LinearEquation::setA(double argA) {
	a = argA;
}

// Return the value of the instance variables b
double LinearEquation::getB() {
	return b;
}

// Set the value of the instance variables b
void LinearEquation::setB(double argB) {
	b = argB;
}

// Return the value of the instance variables c
double LinearEquation::getC() {
	return c;
}

// Set the value of the instance variables c
void LinearEquation::setC(double argC) {
	c = argC;
}

// Return the value of the instance variables d
double LinearEquation::getD() {
	return d;
}

// Set the value of the instance variables d
void LinearEquation::setD(double argD) {
	d = argD;
}

// Return the value of the instance variables e
double LinearEquation::getE() {
	return e;
}

// Set the value of the instance variables e
void LinearEquation::setE(double argE) {
	e = argE;
}

// Return the value of the instance variables f
double LinearEquation::getF() {
	return f;
}

// Set the value of the instance variables f
void LinearEquation::setF(double argF) {
	f = argF;
}

// Return true if the lines within the Linear Equation ever touch each other
bool LinearEquation::isSolvable() {
	return (a * d - b * c != 0);
}

// Return the x-coordinate of the point where the lines touch
double LinearEquation::getX() {
	return (e * d - b * f) / (a * d - b * c);
}

// Return the y-coordinate of the point where the lines touch
double LinearEquation::getY() {
	return (a * f - e * c) / (a * d - b * c);
}