#include <fstream>
#include "MyString.h"


void test_copy_and_destructor(MyString S) {
	cout << "#3 - test: copy constructor and destructor calls: " << endl;
	MyString temp = S;
	cout << "#4 - temp inside function test_copy_and_destructor: " << temp << endl;
}

int main() {
	// Begin of Comments
	
	MyString st1("abc abc");
	MyString st2("9fgth");

	cout << "#1 - Copy constructor , << operator" << endl;		// #1

	MyString  st3(st1);

	cout << "#2 - st3: " << st3 << endl;						// #2

	test_copy_and_destructor(st2);								// #3, 4

	MyString  st4;

	cout << "#5 - operator + " << endl;							// #5

	st4 = st3 + st2;

	cout << "#6 - st4: " << st4 << endl;						// #6

	cout << "#7 - st1 + st2: " << (st1 + st2) << endl;			// #7

	cout << "#8 - operators  [ ] " << endl;						// #8

	cout << "#9 ";
	for (int i = 0; i < st2.length(); i++)						// #9
	cout << st2[i] << " ";

	cout << endl;

	cout << "#10 - operators  += , ==, != " << endl;			// #10

	st2 += st1;

	if (st3 == st1)												// #11
	cout << "#11 - st3 and st1 are identical " << endl;
	else cout << "#11 - st3 and st1 are not identical " << endl;

	if (st2 != st1)												// #12
	cout << "#12 - st2 and st1 are not identical " << endl;
	else cout << "#12 - st2 and st1 are identical " << endl;

	cout << "#13 - operators  < , <=, >, >= " << endl;			// #13

	if (st2 < st1)												// #14 	MyString st1("abc abc"); MyString st2("9fgth");
	cout << "#14 - st2 < st1 " << endl;
	else cout << "#14 - st2 is not less than st1 " << endl;

	if (st1 <= st2)												// #15
	cout << "#15 - st1 <= st2 " << endl;
	else cout << "#15 - st1 is not less than or equal to st2 " << endl;

	if (st1 > st2)												// #16
	cout << "#16 - st1 > st2 " << endl;
	else cout << "#16 - not (st1 >  st2) " << endl;

	if (st1 >= st2)												// #17
	cout << "#17 - st1 >= st2 " << endl;
	else cout << "#17 - not (st1 >=  st2) " << endl;

	cout << "#18 - operator >> " << endl;						// #18

	//Open the data file
	ifstream  input("A9_input.txt");
	if (input.fail()) {
		cout << "unable to open input file A9_input.txt, Exiting..... " << endl;
		system("pause");
		return 0;
	}
	MyString temp1;
	MyString temp2("aaa");
	input >> temp1;
	input >> temp2;
	cout << "#19 - first element of input file: " << temp1 << endl;
	cout << "#20 - second element of input file: " << temp2 << endl;
	input.close();

	cout << "MyString says farewell....." << endl;
		
	// End Of Comments
	
	system("pause");
	return 0;
}