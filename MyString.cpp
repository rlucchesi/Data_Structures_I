/**
* Name: Rafael Teles Lazaro Lucchesi, Student #: 100273456
* Class: CPSC 1160
* Assignment #9
* Description:
*	Implement a string class with overloaded operators, the class will be called MyString.
*	Add and implement:
*		1.	Copy constructor,
*		2.	Assignment , =, operator,
*		3.	Destructor, (the big three)
*		4.	Overload the operators (page 377, sec 10.2)
*			[], +, +=, <<, >>, ==, !=, <, <=, >, >=
*			For the >> operator assume that the string has MAX = 100 characters, each string is on a newline.
*			That is there will not be more than one string on a line delimited by whitespace.
*		5.	You will need the c-string functions and the <cstring> library. You cannot use the string object or include the <string> library.
*		6.	You can add helper methods/functions.
*		7.	For reference, see exercises 11.14, 11.15.
*
* I pledge that I have completed the programming assignment independently.
* I have notcopied the code from a student or any other source.
* I have not given my code to any student.
*
* Rafael Lucchesi, Jul 18, 2017.
*/

#include "MyString.h"

/*
 * Class Implementation
 */
// No argument Constructor
MyString::MyString() {
	this->value = new char[1];
	value[0] = '\0';
	this->size = 0;
}

// Primitive type Constructor
MyString::MyString(char* chars) {
	this->size = strlen(chars);
	this->value = new char[this->size + 1];
	strcpy(this->value, chars);
}

// Copy Constructor
MyString::MyString(const MyString& source) {
	this->size = source.size;
	this->value = new char[this->size + 1];
	strcpy(this->value, source.value);
}

// Destructor
MyString::~MyString() {
	delete this->value;
}

// Overload Assignment Operator 
MyString& MyString::operator= (const MyString& source) {
	if (this->operator!=(source)) {
		this->size = source.size;
		this->value = new char[this->size + 1];
		strcpy(this->value, source.value);
	}
	
	return *this;
}

// Overload Subscript
char MyString::operator[] (const int index) {
	if (index < this->size) {
		return this->value[index];
	}
	return NULL;
}

// Overload Addition
MyString& MyString::operator+(const MyString& source) {
	this->size += source.size;
	char* temp = new char[this->size + 1];
	strcpy(temp, this->value);
	strcat(temp, source.value);
	delete this->value;
	this->value = temp;

	return *this;
}

// Overload Addition assignment
MyString& MyString::operator+=(const MyString& source) {
	this->size += source.size;
	char* temp = new char[this->size];
	strcpy(temp, this->value);
	strcat(temp, source.value);
	delete this->value;
	this->value = temp;

	return *this;
}

// Overload Equal to
bool MyString::operator==(const MyString& source) {
	if (this->size != source.size) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->value[0] != source.value[0]) {
			return false;
		}
	}
	return true;
}

// Overload Not equal to
bool MyString::operator!=(const MyString& source){
	if (this->size == source.size) {
		for (int i = 0; i < this->size; i++) {
			if (this->value[i] != source.value[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		return true;
	}
}

// Overload Less than
bool MyString::operator<(const MyString& source) {
	int cmpRange = sizeOfSmallest(this->size, source.size);
	for (int i = 0; i < cmpRange; i++) {
		if (this->value[i] < source.value[i]) {
			return true;
		}
		else if (this->value[i] > source.value[i]) {
			return false;
		}
	}
	return false;
}

// Overload Less than or equal to
bool MyString::operator<=(const MyString& source) {
	int cmpRange = sizeOfSmallest(this->size, source.size);
	for (int i = 0; i < cmpRange; i++) {
		if (this->value[i] < source.value[i]) {
			return true;
		}
		else if (this->value[i] > source.value[i]) {
			return false;
		}
	}
	return true;
}

// Overload Greater than
bool MyString::operator>(const MyString& source) {
	int cmpRange = sizeOfSmallest(this->size, source.size);
	for (int i = 0; i < cmpRange; i++) {
		if (this->value[i] > source.value[i]) {
			return true;
		}
		else if (this->value[i] < source.value[i]) {
			return false;
		}
	}
	return false;
}

// Overload Greater than or equal to
bool MyString::operator>=(const MyString& source) {
	int cmpRange = sizeOfSmallest(this->size, source.size);
	for (int i = 0; i < cmpRange; i++) {
		if (this->value[i] > source.value[i]) {
			return true;
		}
		else if (this->value[i] < source.value[i]) {
			return false;
		}
	}
	return true;
}

// Overload stream insertion
ostream& operator<<(ostream& output, const MyString& source) {
	output << source.value;
	return output;
}

// Overload stream extraction
//	Assume that the string has MAX = 100 characters, each string is on a newline.
//	That is there will not be more than one string on a line delimited by whitespace.
istream& operator>>(istream& input, MyString& target) {
	char buffer[100];							// Buffer to allocate input
	input >> buffer;							// Get input into buffer cstring
	delete target.value;						// Delete any previous content

	target.size = strlen(buffer);
	target.value = new char[target.size + 1];	// allocate enough memory to hold input
	strcpy(target.value, buffer);
		
	return input;
}

// Returns the smallest between two integers (String length), to be used as range
//	for the string comparison
int sizeOfSmallest(int size1, int size2) {
	if (size1 > size2) {
		return size1;
	}
	return size2;
}

// Returns the size of the string
int MyString::length() const {
	return this->size;
}