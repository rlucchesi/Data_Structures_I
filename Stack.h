#pragma once

const int DEFAULT_SIZE = 100;

template< class T >
class Stack {
public:
	Stack(int = 10);  // default constructor (stack size 10)
					  // destructor
	~Stack() {
		delete[] stackPtr;
	}
	bool push(const T&);
	bool pop(T&);
	// determine whether Stack is empty
	bool isEmpty() const {
		return top == -1;
	}
	// determine whether Stack is full
	bool isFull() const {
		return top == size - 1;
	}
private:
	int size;     // # of elements in the stack
	int top;      // location of the top element
	T *stackPtr;  // pointer to the stack
};
// constructor
template< class T >
Stack< T >::Stack(int s) {
	size = s > 0 ? s : 10;
	top = -1;  // Stack initially empty
	stackPtr = new T[size]; // allocate memory for elements
}
template< class T >
bool Stack< T >::push(const T &pushValue) {
	if (!isFull()) {
		stackPtr[++top] = pushValue;
		return true;
	}
	return false;
}
template< class T >
bool Stack< T >::pop(T &popValue) {
	if (!isEmpty()) {
		popValue = stackPtr[top--];  // remove item from Stack
		return true;
	}
	return false;
}
