/*
Author: Rafael Lucchesi
Created on: 2017-06-08

 The data is given in the file assign-6-data.txt, which you can download from D2L.
The 1st line of this file contains a positive integer that indicates how many Names are to follow.
Based on this number you should dynamically allocate the memory required.
That is a Dynamic Array to hold the names.
As you read the names from the file, you will then allocate enough memory for each name.
As in previous assignments, you are NOT allowed to use the string class.
You must achieve all the objectives by using dynamically allocated memory and c-strings.
When sorting the c-strings, moving of the elements Must be done Efficiently. That is you may not use
“strcpy” to copy c-strings back and forth, rather Move the Pointers.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

/*
* Constants
*/
unsigned const SIZE_OF_NAMES = 59;

/*
* Prototypes
*/
void arrayNameLoader(char **arr, unsigned arraySize, ifstream &file);
//Loads the each array with the address of a linear array which then is fulfilled with a name from
//	the assign-6-data.txt 'file'
//preconditions: a char matrix with a defined number of rows and a file from which the names will
//	be pulled out of
//postconditions: the the matrix's positions will be fulfiled with one name at each index

void arrayNameUnloader(char **arr, unsigned arraySize);
//Deallocate the memory of each linear array used at each index from the char matrix
//preconditions: a a defined array size to iterate

int search(char **arr, unsigned arraySize, char* key);
//Helper function used to invoke the recursive binary search code
//preconditions: a char matrix, a defined array size, and the key which must be located
//postconditions: returns the key's array index or -1 (not found)

int recursiveBS(char ** arr, unsigned first, unsigned last, char* key);
//Recursive binary search code
//preconditions: a char matrix, a defined interval to be searched, and the key which must be located
//postconditions: returns the key's array index, -1 if not found, or calls itself again with a smaller
//	interval

void dispSearchOutput(int searchOutput, char* key);
//Function used to interpret and display the search's result
//preconditions: the recursive binary search output and the key which was searched for
//postconditions: the output is sent to cout

// Quicksort based on the file "Quicksort.cpp" made available by Bijan.
void quickSort(char ** arr, int arraySize);
void quickSort(char ** arr, int first, int last);
int partition(char ** arr, int first, int last);


/*
* Functions
*/

/*
 * Loads the each array with the address of a linear array which then is fulfilled with a name from the
 *	assign-6-data.txt 'file'
 * preconditions: a char matrix with a defined number of rows and a file from which the names will be
 *	pulled out of
 * postconditions: the the matrix's positions will be fulfiled with one name at each index
 */
void arrayNameLoader(char **arr, unsigned arraySize, ifstream &file) {
	char buffer[SIZE_OF_NAMES];
	int cSize = 0;
	for (int i = 0; i < arraySize; i++) {
		file >> buffer;
		cSize = strlen(buffer) + 1;
		arr[i] = new char[cSize];
		strcpy (arr[i], buffer);
	}
}

/*
 * Deallocate the memory of each linear array used at each index from the char matrix
 * preconditions: a a defined array size to iterate
 */
void arrayNameUnloader(char **arr, unsigned arraySize) {
	for (int i = 0; i < arraySize; i++) {
		delete arr[i];
	}
}

/*
 * Helper function used to invoke the recursive binary search code
 * preconditions: a char matrix, a defined array size, and the key which must be located
 * postconditions: returns the key's array index or -1 (not found)
 */
int search(char **arr, unsigned arraySize, char* key) {
	return recursiveBS(arr, 0, arraySize - 1, key);
}

/*
 * Recursive binary search code
 * preconditions: a char matrix, a defined interval to be searched, and the key which must be located
 * postconditions: returns the key's array index, -1 if not found, or calls itself again with a smaller
 *	interval
 */
int recursiveBS(char ** arr, unsigned first, unsigned last, char* key) {
	if (first > last) {
		return -1;
	}
	unsigned mid = (first + last) / 2;
	if (strcmp(key, arr[mid]) == 0) {
		return mid;
	}
	else if (strcmp(key, arr[mid]) < 0) {
		recursiveBS(arr, first, mid - 1, key);
	}
	else {
		recursiveBS(arr, mid + 1, last, key);
	}
}

/*
 * Function used to interpret and display the search's result
 * preconditions: the recursive binary search output and the key which was searched for
 * postconditions: the output is sent to cout
 */
void dispSearchOutput(int searchOutput, char* key) {
	if (searchOutput == -1) {
		cout << "There was no match for your search" << endl;
	}
	else {
		cout << key << " was found at index " << searchOutput << endl;
	}
	cout << endl;
}

/*
 * Helper function used to invoke the recursive quicksort code
 * preconditions: a char matrix and a defined array size
 */
void quickSort(char ** arr, int arraySize) {
	quickSort(arr, 0, arraySize - 1);
}

/*
 * Recursive quicksort invoker. This function holds the base case for the quicksort search code.
 *	When the last is greater than the first, the code stops to call itself.
 * preconditions: a char matrix and a defined interval to be processed
 * postconditions: returns the key's array index, -1 if not found, or calls itself again with a
 *	smaller interval
 */
void quickSort(char ** arr, int first, int last) {
	if (last > first) {
		int pivotIndex = partition(arr, first, last);
		quickSort(arr, first, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, last);
	}
}

/*
 * This function is invoked with a pre-defined range of the original array to work on.
 *	It defines a pivot and rearranges the array with entries < pivot to the left of the pivot and
 *	entries > pivot to the right.
 * preconditions: a char matrix and a defined interval to be processed
 * postconditions: returns the pivot's array index which was used throughout iterations
 */
int partition(char ** arr, int first, int last) {
	char * pivot = arr[first]; // Choose the first element as the pivot
	int low = first + 1; // Index for forward search
	int high = last; // Index for backward search

	while (high > low) {
		// Search forward from left
		while (low <= high && strcmp(arr[low], pivot) < 0) {
			low++;
		}

		// Search backward from right
		while (low <= high && strcmp(arr[high], pivot) > 0) {
			high--;
		}

		// Swap two elements in the list
		if (high > low && high >= first && low <= last) {
			char * temp = arr[high];
			arr[high] = arr[low];
			arr[low] = temp;
		}
	}

	while (high > first && strcmp(arr[high], pivot) >= 0) {
		high--;
	}

	// Swap pivot with list[high]
	if (strcmp(arr[high], pivot) < 0) {
		arr[first] = arr[high];
		arr[high] = pivot;
		return high;
	}
	else {
		return first;
	}
}

int main() {
	bool done = false;
	char userInput[SIZE_OF_NAMES];
	char ** pNames;
	unsigned numberOfNames;
	int searchOutput;

	// File Input
	ifstream file;
	file.open("assign-6-data.txt");

	if (file.fail()) {
		cout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}

	file >> numberOfNames;

	// Array of pointers declaration
	pNames = new char*[numberOfNames];

	arrayNameLoader(pNames, numberOfNames, file);
	
	quickSort(pNames, numberOfNames);
	
	cout << endl;

	for (int i = 0; i < numberOfNames; i++) {
		cout << pNames[i] << endl;
	}

	cout << endl;

	while (!done) {
		cout << "Would you like to search for a name? (type 0 to quit)" << endl;
		cin >> userInput;
		if (strcmp(userInput, "0") == 0) {
			done = true;
		}
		else {
			searchOutput = search(pNames, numberOfNames, userInput);
			dispSearchOutput(searchOutput, userInput);
		}
	}
	
	// Release memory
	arrayNameUnloader(pNames, numberOfNames);
	delete pNames;

	system("pause");
	return 0;
}


