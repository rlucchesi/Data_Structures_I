/**
* Name: Rafael Teles Lazaro Lucchesi, Student #: 100273456
* Class: CPSC 1160
* Assignment #10
* Description:
*	Create a Dictionary as a Hash Table with Linked List to spell check a text document.
*	Read the words from words.rtf to create a Hash Table with linked lists and use it, as a dictionary, to spell check
*	gettysburg_address.txt.
*	Add and implement:
*		1.	Use the a specific hash function:

			#define HASH_WEIGHT  13
			#define LARGE_INT 1024*1024*1024
			unsigned hash = 0;

			for (int i = 0; i < s.length(); i++) {
				hash = HASH_WEIGHT * hash + s[i];
				if (hash >= LARGE_INT)
					hash %= SIZE;
			}

			return hash % SIZE; //size of  hash table array

*		2.	Show any misspelled word and the corresponding line number. Count Blank Lines.
*		3.	Run your program once with a Hash Table of size 1000, and another time 500.
*		4.	Count the number of Collisions for each cell of the Hash Table when loading the dictionary – words.rtf –
and store/display the data 20 per line (or some reasonable number).
*		5.	Count the number of words in the test file gettysburg_address.txt that are misspelled and the ones that are correct.
*			In each case, count the number of operations performed and store/display these numbers. Also, store/display the
*			average number of operations for a misspelled and correct word. Note that number of operations refers to number of
*			nodes visited in the linked list for each word.
*		6.	Output: All output must be displayed on the monitor and also saved in files results_500.txt, results_1000.txt that
correspond to the size of the Hash Table, respectively.
*
* I pledge that I have completed the programming assignment independently.
* I have notcopied the code from a student or any other source.
* I have not given my code to any student.
*
* Rafael Lucchesi, Jul 25, 2017.
*/

#include <string>
#include "hashtable.h"

#define HASH_WEIGHT 13
#define LARGE_INT 1024*1024*1024

using std::string;

// Initialize empty hash table
HashTable::HashTable() {
	for (int i = 0; i < SIZE; i++) {
		this->hashArray[i] = NULL;
		this->numCorrectWords = 0;
		this->numMisspelledWords = 0;
	}
}

// Destructor destroys hash table
HashTable::~HashTable() {
	for (int i = 0; i < SIZE; i++) {
		LinkedList *cell = indexToPointer(i);
		Node* next = cell->getHead();
		while (next != NULL) {
			Node* discard = next;
			next = next->getNext();
			delete discard;
		}
		cell = NULL;
	}
}


// Assignment Instruction #1: Use the function to Compute a hash value
int HashTable::computeHash(string s) {
	unsigned hash = 0;
	for (int i = 0; i < s.length(); i++) {
		hash = HASH_WEIGHT * hash + s[i];
		if (hash >= LARGE_INT)
			hash %= SIZE;
	}
	return hash % SIZE; //size of  hash table array
}

// Adds a new string to the HashTable
int HashTable::add(string input) {
	int hash = computeHash(input);		// get the array's index

										// checks if there exists a linkedlist in the index
	if (hashArray[hash] == NULL) {			// If there is no linkedlist, create a node,
		Node* myNode = new Node(input);					//	 a linkedlist and add to the array 
		LinkedList* myLinkedList = new LinkedList(*myNode);
		hashArray[hash] = myLinkedList;
	}
	else {									// If there exists a linked list
											//collisions[hash]++;
		Node* nodePtr = hashArray[hash]->searchData(input);		//  check for the existance of the input string
		if (nodePtr == NULL) {				// if the string was not found, add a Node containing the string to the linkedlist
			Node* myNode = new Node(input);
			hashArray[hash]->addLast(*myNode);
		}
	}
	return 0;
}

// Returns the number of operations performed to find a string, or -1 if not found
int HashTable::containsString(string target) {
	int hash = computeHash(target);		// get the array's index
	if (hashArray[hash] == NULL) {		// checks if there exists a linkedlist in the index
		this->numMisspelledWords++;
		return -1;
	}
	else {									// If there exists a linked list
		Node* nodePtr = hashArray[hash]->searchData(target);		//  search the item in the LinkedList
		if (nodePtr == NULL) {				// if not found return 1, or return 0 otherwise
			this->numMisspelledWords++;
			return -1;
			//return num collisions
		}
		else {
			this->numCorrectWords++;
			return nodePtr->getNumVisitedNodes();
		}
	}
}

// Remove non-word chars from a string
string HashTable::removeExtraChars(string input) {
	// ignore rtf configuration tokens
	if (input[0] < 'a' || input[0] > 'z') {
		if (input[0] < 'A' || input[0] > 'Z') {
			return "";
		}
	}
	string output = input;
	for (int i = 0; i < output.length(); i++) {
		if (output[i] < 'a' || output[i] > 'z') {
			if (output[i] < 'A' || output[i] > 'Z') {
				output = output.substr(0, i) + output.substr(i + 1);
				i--;
			}
		}
	}
	return output;
}

// Make chars lowercase for later comparisons
string HashTable::normalize(string input) {
	string output = input;
	transform(output.begin(), output.end(),
		output.begin(), ::tolower);
	return output;
}

// Takes a hash value as input and returns a pointer to the corresponding LinkedList
LinkedList* HashTable::indexToPointer(int index) {
	return hashArray[index];
}

// Returns the number of correct words searched after initializing the HashTable
int HashTable::getNumCorrect() {
	return this->numCorrectWords;
}

// Returns the number of misspelled words searched after initializing the HashTable
int HashTable::getNumMisspelled() {
	return this->numMisspelledWords;
}

// Method used to access the constant value SIZE
int HashTable::getHashSize() {
	return SIZE;
}