/*
 * Write a program that simulates the bean machine.
 * Your program should prompt the user to enter the number of balls and the number of slots (maximum 50) in the machine.
 * Simulate the falling of each ball by printing its path.
 * Display the final buildup of the balls in the slots in a histogram.
 */


#include <iostream>
#include <time.h>	// used as input for the srand function
#include <string>

using namespace std;

/*
 * Prototypes
 */
char ballPathGenerator();
//generates a char ('L' or 'R') to record the random path which the ball has taken
//postconditions: the function returns a char representing the path

int slotIndexer(string pathLog, int slotSize);
//generates a integer index which represents the slot in which the ball has been randomly placed
//precondiotions: a string with the 'L's and 'R's chars to be assessed, along with the size of slots to determine the number of trials the ball had been put through.
//postconditions: the function returns a int representing the index of the slot

string histogramDrawer(int slot[], int slotSize, int histoSize);
//generates a integer index which represents the slot in which the ball has been randomly placed
//precondiotions: a string with the 'L's and 'R's chars to be assessed, along with the size of slots to determine the number of trials the ball had been put through.
//postconditions: the function returns a int representing the index of the slot


/*
 * Constants
 */
int const SLOTS_MAXIMUM_SIZE = 50;


/*
 * Functions
 */

/*
 * Generates a char ('L' or 'R') to record the random path which the ball has taken
 * Postconditions: the function returns a char representing the path
 */
char ballPathGenerator() {
	int output = rand() % 2;
	if (output == 0) {
		return 'L';
	}
	else {
		return 'R';
	}
}

/*
 * Generates a integer index which represents the slot in which the ball has been randomly placed
 * Precondiotions: a string with the 'L's and 'R's chars to be assessed, along with the size of slots to determine the number of trials the ball had been put through.
 * Postconditions: the function returns a int representing the index of the slot
 */
int slotIndexer(string pathLog, int slotSize) {
	int output = 0;
	for (int i = 0; i < slotSize - 1; i++) {
		if (pathLog[i] == 'R') {
			output++;
		}
	}
	return output;
}

/*
 * Generates a integer index which represents the slot in which the ball has been randomly placed
 * Precondiotions: a string with the 'L's and 'R's chars to be assessed, along with the size of slots to determine the number of trials the ball had been put through.
 * Postconditions: the function returns a int representing the index of the slot
 */
string histogramDrawer(int slot[], int slotSize, int histoSize) {
	string output;
	for (int i = histoSize; i > 0; i--) {
		for (int j = 0; j < slotSize; j++) {
			if (slot[j] >= i) {
				output += "0";
			}
			else {
				output += " ";
			}
		}
		output += '\r';
		output += '\n';
	}
	return output;
}


int main() {
	// Variables
	int slot[SLOTS_MAXIMUM_SIZE] = { 0 };		// Slot array to store balls
	string ballPathLog;							// string to hold the path the ball takes
	int ballNum;								// Number of balls (user input)
	int slotSize;								// Number of slots (user input <= 50)
	int slotIndex;								// an integer representation of the ballpath
	int histogramRowNum = 0;					// number of rows to draw the histogram

	// srand initialization
	srand(time(0));

	// Get inputs
	cout << "Enter the number of balls to drop: ";
	cin >> ballNum;
	cout << "Enter the number of slots in the bean machine (maximum 50): ";
	cin >> slotSize;

	cout << endl;

	for (int i = 0; i < ballNum; i++) {		// number of balls
		ballPathLog = "";

		// produce ball path str
		for (int j = 0; j < slotSize - 1; j++) {
			ballPathLog += ballPathGenerator();
		}

		// an integer representation of the ballpath
		slotIndex = slotIndexer(ballPathLog, slotSize);

		cout << ballPathLog << endl;

		// slot being incremented
		slot[slotIndex]++;

		// if statement to determine the histogram's row number
		if (slot[slotIndex] > histogramRowNum) {
			histogramRowNum = slot[slotIndex];
		}
	}

	cout << endl;

	// Function call to draw the histogram
	cout << histogramDrawer(slot, slotSize, histogramRowNum);

	cout << endl;

	system("pause");
	return 0; 
}






/* Algorithm
1. ask user for number of balls and slots -- OK
2. random placement of # balls into slot[]
number of trials == slots[#] - 1;

3. determine the number of lines of the histogram when placing the balls (MAX(slots[#]) == histogramLineNum)
if slots[i] == histogramLineNum-i print 0 else print ' ';
<< endl;
while histogramLineNum-i >= 0;

*/