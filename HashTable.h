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

#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <algorithm>				// transform() used in HashTable::normalize
#include "LinkedList.h"

using std::string;
const int SIZE = 500;  // Maximum size of the hash table array

class HashTable {
public:
	// Compute a hash value
	static int computeHash(string s);
	
	// Remove non-word chars from a string
	static string removeExtraChars(string input);
	
	// Make chars lowercase for later comparisons
	static string normalize(string input);

	// Initialize empty hash table
	HashTable();

	// Destructor destroys hash table
	~HashTable();

	// Returns the number of operations performed to find a string, or -1 if not found
	int containsString(string target);

	// Adds a new string to the HashTable
	int add(string);

	// Takes a hash value as input and returns a pointer to the corresponding LinkedList
	LinkedList* indexToPointer(int);

	// Returns the number of correct words searched after initializing the HashTable
	int getNumCorrect();
	
	// Returns the number of misspelled words searched after initializing the HashTable
	int getNumMisspelled();
	
	// Method used to access the constant value SIZE
	int getHashSize();

private:
	LinkedList* hashArray[SIZE];      // The actual hash table
	int numCorrectWords;
	int numMisspelledWords;
}; // HashTable

#endif // HASHTABLE_H