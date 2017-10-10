#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int const TOTALXYCOORDINATES = 4;

class LinearEquation {
public:
	LinearEquation(double argA, double argB, double argC, double argD, double argE, double argF) {
		a = argA;
		b = argB;
		c = argC;
		d = argD;
		e = argE;
		f = argF;
	}
	
	double getA() {
		return a;
	}
	double getB() {
		return b;
	}
	double getC() {
		return c;
	}
	double getD() {
		return d;
	}
	double getE() {
		return e;
	}
	double getF() {
		return f;
	}

	bool isSolvable() {
		return (a*d - b*c != 0);
	}

	double getX() {
		if (isSolvable()) {
			return (e * d - b * f) / (a * d - b * c);
		}
	}
	double getY() {
		if (isSolvable()) {
			return (a * f - e * c) / (a * d - b * c);
		}
	}


private:
	double a, b, c, d, e, f;
};


int main() {
	fstream file;
	file.open("coords.txt");

	if (file.fail()) {
		cout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}

	while (!file.eof()) {
		double* line1 = new double[TOTALXYCOORDINATES + 1];
		for (int i = 0; i < TOTALXYCOORDINATES; i++) {
			file >> line1[i];
		}
		line1[TOTALXYCOORDINATES] = (line1[3] - line1[1]) / (line1[2] - line1[0]);
		cout << line1[TOTALXYCOORDINATES] << endl;

		double* line2 = new double[TOTALXYCOORDINATES + 1];
		for (int i = 0; i < TOTALXYCOORDINATES; i++) {
			file >> line2[i];
		}
		line2[TOTALXYCOORDINATES] = (line2[3] - line2[1]) / (line2[2] - line2[0]);
		cout << line2[TOTALXYCOORDINATES] << endl;

		LinearEquation myLE(-line1[TOTALXYCOORDINATES], 1, -line2[TOTALXYCOORDINATES], 1, line1[1] - line1[TOTALXYCOORDINATES] * line1[0], line2[1] - line2[TOTALXYCOORDINATES] * line2[0]);

		cout << "Line1 from (" << line1[0] << ", " << line1[1] << ") to (" << line1[2] << ", " << line1[3] << ")." << endl;
		cout << "Line2 from (" << line2[0] << ", " << line2[1] << ") to (" << line2[2] << ", " << line2[3] << ")." << endl;
		cout << "Both lines intercept at (" << myLE.getX() << ", " << myLE.getY() << ")." << endl;
		cout << endl;

		delete[] line1;
		delete[] line2;
		
	}

	system("pause");
	return 0;
}