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
			That is there will not be more than one string on a line delimited by whitespace.
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

#pragma warning(disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;

/*
 * Class Declaration
 */
class MyString {
	friend ostream& operator<< (ostream&, const MyString&);		// Overload stream insertion
	friend istream& operator>> (istream&, MyString&);			// Overload stream extraction
	friend int sizeOfSmallest(int, int);						// Returns the smallest between two integers (String length)

public:
	MyString();										// No argument Constructor
	MyString(char*);								// Primitive type Constructor
	MyString(const MyString&);						// Copy Constructor
	~MyString();									// Destructor
	int length() const;								// Returns the size of the string

	MyString& operator= (const MyString&);			// Overload Assignment Operator 
	char operator[] (const int);					// Overload Subscript
	MyString& operator+ (const MyString&);			// Overload Addition
	MyString& operator+= (const MyString&);			// Overload Addition assignment
	bool operator== (const MyString&);				// Overload Equal to
	bool operator!= (const MyString&);				// Overload Not equal to
	bool operator< (const MyString&);				// Overload Less than
	bool operator<= (const MyString&);				// Overload Less than or equal to
	bool operator> (const MyString&);				// Overload Greater than
	bool operator>= (const MyString&);				// Overload Greater than or equal to

private:
	char* value;		// Actual cstring
	int size;			// cstring's size
};