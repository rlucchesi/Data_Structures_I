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
 * I have notcopied the code from a student. The MyOstream class is based on a external code (link within the documentation of the class)
 * I have not given my code to any student.
 *
 * Rafael Lucchesi, Jul 25, 2017.
 */

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Node.h"
#include "Linkedlist.h"
#include "Hashtable.h"

using namespace std;

/*
 * myOstream class used to overload operator<< to display and log the test program
 */
class myOstream {
public: 
	myOstream() : myFstream("results_500.txt") {}; // name of the output file

	template<typename T>
	myOstream& operator<<(const T& source) {
		std::cout << source;					// Display output
		myFstream << source;					// Log output
		return *this;
	}
	
	// for manipulators like std::endl
	typedef std::ostream& (*stream_function)(std::ostream&);
	myOstream& operator<<(stream_function func) {
		func(std::cout);
		func(myFstream);
		return *this;
	}
	
private:
	std::ofstream myFstream;
} mout;

/*
 * Test Program
 */
int main() {
	// Variables
	string word, inputLine, strDisplay("");
	int displayCounter = 0, lineNumber = 0, sumOpCorrectWords = 0, sumOpMisspelledWords = 0;
	HashTable* myHashTable = new HashTable();
	
	// Dictionary File handler
	fstream dictionarySource;
	dictionarySource.open("words.rtf");
	if (dictionarySource.fail()) {
		mout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}

	// Text to be checked File handler
	ifstream textToBeChecked;
	textToBeChecked.open("gettysburg_address.txt");
	if (textToBeChecked.fail()) {
		mout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}


	/*
	* Load the Hashtable with rtf's content and build a string to use only one system call to output them (15/line)
	*/
	mout << "==== #4: Store/Display the HashTable with words.rtf's content ====" << endl << endl;
	while (!dictionarySource.eof()) {
		dictionarySource >> word;
		word = word.substr(0, word.length() - 4);			// Remove rtf's junk at the end of every word
		word = HashTable::removeExtraChars(word);			// Remove non-word characters
		strDisplay += word + " ";							// Building string (lines 122-127)
		displayCounter++;
		if (displayCounter > 14) {							// Display 15 words/line
			displayCounter = 0;
			strDisplay += "\r\n";
		}
		word = HashTable::normalize(word);					// store a normalized version in dba for later comparisions
		myHashTable->add(word);
	}
	mout << strDisplay << endl;								// display Word Database

	/*
	 * Display misspelled words and the corresponding line number.
	 * Build a string containing every correct/misspelled word along with the number of operations for each of them.
	 * The string will be displayed latter in the test program.
	 */
	mout << endl << "==== #2: Show any misspelled word and the corresponding line number ====" << endl;
	mout << "FORMAT --> Word : Line Number" << endl << endl;
	displayCounter = 0;
	strDisplay = "";								// reset string var to hold number of operations for every word
	while (!textToBeChecked.eof()) {
		int numVisitedNodes;						// holds the number of visited nodes for each word
		getline(textToBeChecked, inputLine);		// extracts one line of the source text
		lineNumber++;								// counts the line number
		istringstream myStream(inputLine);				// builds a stream out of the line previously extracted
		while (myStream) {
			myStream >> word;							// extract a single word from myStream
			if (word != "") {
				word = HashTable::removeExtraChars(word);		// Remove non-word characters

				numVisitedNodes = myHashTable->containsString(HashTable::normalize(word));		// containsString returns the number of visited Nodes for a research on a (normalized) word
				if (numVisitedNodes >= 0) {														// If the word is found, the return value is positive
					strDisplay += "([C] " + word + " : " + to_string(numVisitedNodes) + ") ";
					sumOpCorrectWords += numVisitedNodes;										// Sum number of operations to find correct words
					
				}
				else {																			// if word is not found
					int hash = HashTable::computeHash(word);											// get the array's index where it should be
					LinkedList* cell = myHashTable->indexToPointer(hash);
					strDisplay += "([M] " + word + " : " + to_string(cell->getNumCollisions()) + ") ";
					sumOpMisspelledWords += cell->getNumCollisions();									// Sum the number of Nodes searched (all of them)
					mout << word << " : " << lineNumber << endl;
				}

				displayCounter++;
				if (displayCounter > 6) {		// Display 7 words/line
					displayCounter = 0;
					strDisplay += "\n\r";
				}
			}
			word = "";
		}
	}

	/*
	 * Display the number of collisions for each cell of the HashTable when loading the database
	 */
	mout << endl << "==== #4: Show number of collisions for each cell of the HashTable when loading the database ====" << endl;
	mout << "FORMAT --> (Cell : Number of collisions)" << endl << endl;
	for (int i = 0; i < myHashTable->getHashSize(); i++) {
		LinkedList* cell = myHashTable->indexToPointer(i);
		mout << "(" << i << ":" << cell->getNumCollisions() << ") ";
		if (i % 15 == 0 && i != 0) {
			mout << endl;
		}
	}

	/*
	 * Display the string containing correct/misspelled word : number of operations, along with the average number of operations for each of them.
	 */
	mout << endl << endl << "==== #5: Show number of misspelled and correct words. Display the number of visited nodes (number of operations) for both types of words, along with the average number of operations ====" << endl;
	mout << endl << endl << "FORMAT --> ([CORRECT/MISSPELLED] Word : Number of operations)" << endl << endl;
	mout << strDisplay << endl << endl;
	mout << "Number of correct words: " << myHashTable->getNumCorrect() << endl;
	mout << "Number of misspelled words: " << myHashTable->getNumMisspelled() << endl;
	mout << "Average number of operations for correct words: " << sumOpCorrectWords / myHashTable->getNumCorrect() << endl;
	mout << "Average number of operations for misspelled words: " << sumOpMisspelledWords / myHashTable->getNumMisspelled() << endl;
	
	system("pause");
	return 0;
}