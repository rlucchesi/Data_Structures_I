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

#include "Node.h"

// Initialize a LinkedList with one string as argument. If the pointer to the next node is note set, it is init. to NULL
Node::Node(const string& item, Node* ptrnext) {
	this->data = item;
	this->next = ptrnext;
}

// Modifier Method used to set the next pointer of the Node
void Node::setNext(Node* newNode) {
	this->next = newNode;
}

// Returns a Node pointer to the next Node
Node* Node::getNext() {
	return this->next;
}

// Returns the string (content) of the Node
string Node::getData() {
	return this->data;
}

// Returns the number of visited Nodes a new string had to go though before being used to create a new Node
int Node::getNumVisitedNodes() {
	return this->numVisitedNodes;
}

// Sets the number of visited Nodes
void Node::setNumVisitedNodes(int num) {
	//cout << "!!!! setNumVisitedNodes called with value " << num << endl;
	this->numVisitedNodes = num;
}