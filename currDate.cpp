#pragma warning(disable:4996)
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

// Constants
const int DAYS_REGULAR_YEAR = 365;
const int DAYS_LEAP_YEAR = 366;


//Prototypes
void currDate(unsigned seconds, char month[], unsigned & day, unsigned &monthNum,
	unsigned & year, unsigned & hour, unsigned & min, unsigned & sec, bool isLeap);

void currSecond(unsigned currentTime, unsigned &second);
void currMinute(unsigned currentTime, unsigned &minute);
void currHour(unsigned currentTime, unsigned &hour);
void currDate(unsigned currentTime, bool &isLeap, unsigned &year, unsigned &monthNum, unsigned &day);

void monthNameGen(unsigned &monthNum, char monthName[]);
void isLeapYear(unsigned year, bool &isLeapYear);


// Functions
void currSecond(unsigned currentTime, unsigned &second) {
	second = currentTime % 60;
}

void currMinute(unsigned currentTime, unsigned &minute) {
	minute = (currentTime / 60) % 60;
}

void currHour(unsigned currentTime, unsigned &hour) {
	hour = (((currentTime / 60) / 60) % 24);
}

void currDate(unsigned currentTime, bool &isLeap, unsigned &year, unsigned &monthNum, unsigned &day) {
	int yearCounter = 1970, monthCounter, monthTotalDays;

	// convert to days
	int currDays = (((currentTime / 60) / 60) / 24);
	
	// Determines the year
	while (currDays > DAYS_REGULAR_YEAR) {
		isLeapYear(yearCounter, isLeap);
		if (isLeap) {
			currDays -= DAYS_LEAP_YEAR;
		}
		else {
			currDays -= DAYS_REGULAR_YEAR;
		}
		yearCounter++;
	}
	year = yearCounter;

	// Determines the Month
	isLeapYear(year, isLeap);

	

	for (monthCounter = 1; monthCounter <= 12 && currDays > 0; monthCounter++) {
		switch (monthCounter) {
			case 2:
				if (isLeap) {
					monthTotalDays = 29;
				}
				else {
					monthTotalDays = 28;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				monthTotalDays = 30;
				break;
			default:
				monthTotalDays = 31;
				break;
		}
		currDays -= monthTotalDays;
	}
	monthNum = monthCounter - 1;

	// Determine the Day
	day = monthTotalDays + currDays + 1;
}

void monthNameGen(unsigned &monthNum, char monthName[]) {
	switch (monthNum) {
	case 1:
		strcat(monthName, "January");
		break;
	case 2:
		strcat(monthName, "February");
		break;
	case 3:
		strcat(monthName, "March");
		break;
	case 4:
		strcat(monthName, "April");
		break;
	case 5:
		strcat(monthName, "May");
		break;
	case 6:
		strcat(monthName, "June");
		break;
	case 7:
		strcat(monthName, "July");
		break;
	case 8:
		strcat(monthName, "August");
		break;
	case 9:
		strcat(monthName, "September");
		break;
	case 10:
		strcat(monthName, "October");
		break;
	case 11:
		strcat(monthName, "November");
		break;
	case 12:
		strcat(monthName, "December");
		break;
	}
}

void isLeapYear(unsigned year, bool &isLeap) {
	isLeap = false;
	if (year % 4 == 0) {
		if (year % 100 != 0 || year % 400 == 0) {
			isLeap = true;
		}
	}
}

void currDate(unsigned seconds, char month[], unsigned & day, unsigned &monthNum, 
	unsigned & year, unsigned & hour, unsigned & min, unsigned & sec, bool isLeap) {
	// Calculations
	currSecond(seconds, sec);
	currMinute(seconds, min);
	currHour(seconds, hour);
	currDate(seconds, isLeap, year, monthNum, day);
	monthNameGen(monthNum, month);

	cout << "Current date and time is " << month << " " << day << ", " << year << " "
		<< hour << ":" << min << ":" << sec << " GMT" << endl;
}



int main() {
	// Returns the elapsed time in seconds with the correct timezone offset set to Vancouver (GMT -07:00);
	// https://www.epochconverter.com/timezones
	unsigned int uCurrentDate = time(0) - 25200;

	unsigned second, minute, hour, year, monthNum, day;
	bool isLeap = false;
	char monthName[10] = "";

	currDate(uCurrentDate, monthName, day, monthNum, year, hour, minute,
		second, isLeap);

	system("pause");
	return 0;
}