#pragma once
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
*		4.	Count the number of Collisions for each cell of the Hash Table when loading the dictionary � words.rtf �
and store/display the data 20 per line (or some reasonable number).
*		5.	Count the number of words in the test file gettysburg_address.txt that are misspelled and the ones that are correct.
*			In each case, count the number of operations performed and store/display these numbers. Also, store/display the
*			average number of operations for a misspelled and correct word. Note that number of operations refers to number of
*			nodes visited in the linked list for each word.
*		6.	Output: All output must be displayed on the monitor and also saved in files results_500.txt, results_1000.txt that
correspond to the size of the Hash Table, respectively.
*
* I pledge that I have completed the programming assignment independently.
* I have notcopied the code from a student. The MyOstream class is based on a external code (link within the documentation of the class)
* I have not given my code to any student.
*
* Rafael Lucchesi, Jul 25, 2017.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
	// Initialize a LinkedList with one Node as argument
	LinkedList(Node&);

	// Adds a Node to the first position of the LinkedList
	int addFirst(Node&);
	
	// Adds a Node to the last position of the LinkedList
	int addLast(Node&);

	// Returns a Node pointer to the first Node of the LinkedList
	Node* getHead();
	
	// Returns a Node pointer to the last Node of the LinkedList
	Node* getTail();

	// Returns the size of the LinkedList
	int getSize();
	
	// Returns the number of Collisions since the LinkedList's init.
	int getNumCollisions();

	// Searches for a string within the LinkedList, returning a pointer to the Node or NULL if not found
	Node* searchData(string);

private:
	Node* head;
	Node* tail;
	int size;
	int numCollisions;
};

#endif // LINKEDLIST_H 