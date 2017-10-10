/**
* Name: Rafael Teles Lazaro Lucchesi, Student #: 100273456
* Class: CPSC 1160
* Assignment #8
* Description:
*	Modify and Implement the Template Stack given (Stack.h) such that if the Stack gets full,
*	it doubles the size of its Dynamically Allocated Array, copies the data into the newly
*	allocated larger array, and releases the old array. Please note that the stack should be
*	intact and contain the element that was to be pushed onto the stack when it ran out of
*	memory.
*
* I pledge that I have completed the programming assignment independently.
* I have notcopied the code from a student or any other source.
* I have not given my code to any student.
*
* Rafael Lucchesi, Jul 02, 2017.
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <typeinfo>
using namespace std;

const int DEFAULT_SIZE = 100;

/*
 * Class Definition
 */
template< class T >
class Stack {
public:
	// default constructor (stack size 10)
	Stack(int = 10);

	// destructor
	// HERE is problem
	~Stack() {
		delete[] stackPtr;
	}

	bool push(const T&);
	bool pop(T&);

	// Return the capacity of the array
	int getSize() {
		return this->size;
	}

	// Return the current number of elements in the array
	int getCurrNumElements() {
		return this->top + 1;
	}

	// determine whether Stack is empty
	bool isEmpty() const {
		return top == -1;
	}

	// determine whether Stack is full
	bool isFull() const {
		return top == size - 1;
	}

private:
	int size;     // # of elements the stack can hold
	int top;      // location of the top element
	T *stackPtr;  // pointer to the stack
};

/*
 * Class Implementation
 */
// constructor
template< class T >
Stack< T >::Stack(int s) {
	size = s > 0 ? s : 10;
	top = -1;  // Stack initially empty
	stackPtr = new T[size]; // allocate memory for elements
}

template< class T >
bool Stack< T >::push(const T &pushValue) {
	// If full, double the size of the Stack
	if (isFull()) {
		// 5. Put a "cout statement" to flag when the memory is getting Doubled.
		cout << "-- > Memory is getting Doubled <--" << endl;

		T* newStackPtr = new T[2 * size];	// allocate memory for elements

											// copy contents of the old to the new stack
		for (int i = 0; i < this->size; i++) {
			newStackPtr[i] = this->stackPtr[i];
		}

		delete[] this->stackPtr;	// delete old array
		this->stackPtr = newStackPtr;	// update stackPtr's address
		this->size *= 2;	// update stackPtr's size
	}

	stackPtr[++top] = pushValue;
	return true;
}

template< class T >
bool Stack< T >::pop(T &popValue) {
	if (!isEmpty()) {
		popValue = stackPtr[top--];  // remove item from Stack
		return true;
	}
	return false;
}

/*
 * Function Prototype
 */

//template< class T >
//void stackLoader(Stack<T> &stack, int limit);

//Push elements onto the stack with a specified number of strings
template< class T >
void stackStringLoader(Stack<T> &stack, int limit);

//Push elements onto the stack with a specified number of doubles/integers
template< class T >
void stackNumLoader(Stack<T> &stack, int limit);

//Pops all elements from the stack, displaying each of them on cout
template< class T >
void stackPopAndDisplayer(Stack<T> &stack, int limit);

//Converts a decimal fraction f to a c-string cs.
void ftoa(double f, char* &cs);


/*
 * Function Implementation
 */

 /*
// Push elements onto the stack
// Reference: after talking to Bijan about this function, I was told it would not work and advised to work with
//	separate versions for strings and nums

template< class T >
void stackLoader(Stack<T> &stack, int limit) {
	srand(time(0));		// srand initialization
	T inputItem;
	char* cString;
	double randomDouble;

	for (int i = 0; i < limit; i++) {
		if (typeid(T) == typeid(string)) {
			randomDouble = rand() / 100.0;
			ftoa(randomDouble, cString);
			//inputItem = string(cString);
			cString = NULL;
		}
		else {
			inputItem = rand() / 100.0;
		}
		stack.push(inputItem);
		//inputItem = NULL;
	}
}
*/

//Push elements onto the stack with a specified number of strings
template< class T >
void stackStringLoader(Stack<T> &stack, int limit) {
	srand(time(0));		// srand initialization
	T inputItem;
	char* cString;
	double randomDouble;

	for (int i = 0; i < limit; i++) {
		randomDouble = rand() / 100.0;
		ftoa(randomDouble, cString);
		inputItem = string(cString);
		cString = NULL;
		stack.push(inputItem);
	}
}

//Push elements onto the stack with a specified number of doubles/integers
template< class T >
void stackNumLoader(Stack<T> &stack, int limit) {
	srand(time(0));		// srand initialization
	T inputItem;

	for (int i = 0; i < limit; i++) {
		inputItem = rand() / 100.0;
		stack.push(inputItem);
	}
}


//Pops all elements from the stack, displaying each of them on cout
template< class T >
void stackPopAndDisplayer(Stack<T> &stack, int limit) {			// Type of &stack should be Stack<T> ***********************************************
	T stackOutput;
	cout << endl << "Display --> [index: value] for " << limit << " values" << endl;
	for (int i = 0; i < limit; i++) {
		stack.pop(stackOutput);
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
		cout << "[" << i << ": " << stackOutput << "] ";
	}
	cout << endl;
	cout << endl;
}

//Converts a decimal fraction f to a c-string cs.
//Note that you can assume f has 2 decimal places.
void ftoa(double f, char* &cs) {
	f *= 100;	// assuming 2 decimal places
	int numOfDigits = 0;
	int nullIndex;

	int digitsOnly = (int)f;

	// Determine the number of digits to determine the size of the c-string
	while (digitsOnly) {
		numOfDigits++;
		digitsOnly /= 10;
	}
			
	cs = new char[numOfDigits + 1];		// Add 1 for the NULL char
	cs[numOfDigits] = NULL;				// Place the NULL char
	digitsOnly = (int)f;

	// Add the 'A' ASCI value to each digit in order to build random c-strings
	while (numOfDigits) {
		cs[--numOfDigits] = (char)(digitsOnly % 10 + 97);
		digitsOnly /= 10;
	}
}


/*
 * Stack Tester
 */
int main() {
	/*
	 * Integer Stack
	 */

	cout << "=*=*=*=*=*=*=*=*=*=*=*=* Integer Stack =*=*=*=*=*=*=*=*=*=*=*=*" << endl;

	// 1. Create a Stack of default size
	Stack<int> myIntStack(DEFAULT_SIZE);

	// 2. Push 100 integer elements onto the stack
	stackNumLoader(myIntStack, DEFAULT_SIZE);

	// 3. Display all the elements on the stack by popping until the stack is empty
	stackPopAndDisplayer(myIntStack, myIntStack.getCurrNumElements());

	// 4. This time push 250 pseudo random integer elements onto the stack
	stackNumLoader(myIntStack, 250);

	// 6. Display all the elements by popping the stack until it is empty
	stackPopAndDisplayer(myIntStack, myIntStack.getCurrNumElements());


	/*
	 * Double Stack
	 */

	cout << "=*=*=*=*=*=*=*=*=*=*=*=* Double Stack =*=*=*=*=*=*=*=*=*=*=*=*" << endl;
	
	// 1. Create a Stack of default size
	Stack<double> myDoubleStack(DEFAULT_SIZE);

	// 2. Push 100 integer elements onto the stack
	stackNumLoader(myDoubleStack, DEFAULT_SIZE);

	// 3. Display all the elements on the stack by popping until the stack is empty
	stackPopAndDisplayer(myDoubleStack, myDoubleStack.getCurrNumElements());

	// 4. This time push 250 pseudo random integer elements onto the stack
	stackNumLoader(myDoubleStack, 250);

	// 6. Display all the elements by popping the stack until it is empty
	stackPopAndDisplayer(myDoubleStack, myDoubleStack.getCurrNumElements());


	/*
	 * String Stack
	 */

	cout << "=*=*=*=*=*=*=*=*=*=*=*=* String Stack =*=*=*=*=*=*=*=*=*=*=*=*" << endl;

	// 1. Create a Stack of default size
	Stack<string> myStringStack(DEFAULT_SIZE);

	// 2. Push 100 integer elements onto the stack
	stackStringLoader(myStringStack, DEFAULT_SIZE);

	// 3. Display all the elements on the stack by popping until the stack is empty
	stackPopAndDisplayer(myStringStack, myStringStack.getCurrNumElements());

	// 4. This time push 250 pseudo random integer elements onto the stack
	stackStringLoader(myStringStack, 250);

	// 6. Display all the elements by popping the stack until it is empty
	stackPopAndDisplayer(myStringStack, myStringStack.getCurrNumElements());

	system("pause");
	return 0;
}