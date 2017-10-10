/*
The data is given in the file assign-6-data.txt, which you can download from D2L.
The 1st line of this file contains a positive integer that indicates how many Names are to follow.
Based on this number you should dynamically allocate the memory required.
That is a Dynamic Array to hold the names.
As you read the names from the file, you will then allocate enough memory for each name.
As in previous assignments, you are NOT allowed to use the string class.
You must achieve all the objectives by using dynamically allocated memory and c-strings.
*/

#include <iostream>
#include <fstream>

using namespace std;

// Constants
unsigned const SIZE_OF_NAMES = 59;

// Function prototypes
void arrayMemoryAllocator(char **arr, unsigned arraySize);
void arrayNameLoader(char **arr, unsigned arraySize, ifstream &file);

void quickSort(char ** arr, int arraySize);
void quickSort(char ** arr, int first, int last);
int partition(char ** arr, int first, int last);

// Functions
void arrayMemoryAllocator(char **arr, unsigned arraySize) {
	for (int i = 0; i < arraySize; i++) {
		arr[i] = new char[SIZE_OF_NAMES];
	}
}

void arrayNameLoader(char **arr, unsigned arraySize, ifstream &file) {
	for (int i = 0; i < arraySize; i++) {
		file >> arr[i];
		cout << "arr[] content " << i << " " << arr[i] << endl;
	}
}

void quickSort(char ** arr, int arraySize) {
	quickSort(arr, 0, arraySize - 1);
}

void quickSort(char ** arr, int first, int last) {
	if (last > first) {
		int pivotIndex = partition(arr, first, last);
		quickSort(arr, first, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, last);
	}
}

// Partition the array list[first..last]
int partition(char ** arr, int first, int last) {
	char * pivot = arr[first]; // Choose the first element as the pivot
	cout << "pivot " << pivot << endl;
	int low = first + 1; // Index for forward search
	int high = last; // Index for backward search

	while (high > low) {
		// Search forward from left
		while (low <= high && strcmp (arr[low], pivot) < 0) {
			low++;
		}

		// Search backward from right
		while (low <= high && strcmp(arr[high], pivot) > 0) {
			high--;
		}

		// Swap two elements in the list
		if (high > low) {
			char * temp = arr[high];
			arr[high] = arr[low];
			arr[low] = temp;
		}
	}

	while (high > first && strcmp(arr[high], pivot) >= 0) {
		high--;
	}

	// Swap pivot with list[high]
	if (strcmp(arr[high], pivot) > 0) {
		arr[first] = arr[high];
		arr[high] = pivot;
		return high;
	}
	else {
		return first;
	}
}

int main() {
		
	unsigned numberOfNames;

	ifstream file;
	file.open("assign-6-data.txt");

	if (file.fail()) {
		cout << "ERROR openning input file" << endl;
		system("pause");
		exit(1);
	}

	file >> numberOfNames;
	
	char ** pNames = new char*[numberOfNames];

	arrayMemoryAllocator(pNames, numberOfNames);
	arrayNameLoader(pNames, numberOfNames, file);

	for (int i = 0; i < numberOfNames; i++) {
		cout << pNames[i] << endl;
	}

	quickSort(pNames, numberOfNames);
	quickSort(pNames, numberOfNames);
	quickSort(pNames, numberOfNames);

	cout << endl;

	for (int i = 0; i < numberOfNames; i++) {
		cout << pNames[i] << endl;
	}

	system("pause");
	return 0;
}


