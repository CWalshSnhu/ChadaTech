/*
	Caitlyn Walsh
	9/15/2023
*/

#define _CRT_SECURE_NO_WARNINGS // This is here so the project can compile properly

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


class Clock { // A clock class to handle time calculations and printing.
private:
	int hours; // Hours
	int minutes; // Minutes
	int seconds; // Seconds
	bool is24hrs; // If true, sets the clock to have 24 hours instead of 12. Must be defined.
public:
	// Constructor to create a new Clock using local time.
	Clock(bool is24) {
		time_t now = time(0);
		tm* ltm = localtime(&now);

		this->hours = ltm->tm_hour;
		this->minutes = ltm->tm_min;
		this->seconds = ltm->tm_sec;
		this->is24hrs = is24;
	}

	// Constructor to create a new clock with a preset time.
	Clock(int h, int m, int s, bool is24) {
		this->hours = h;
		this->minutes = m;
		this->seconds = s;
		this->is24hrs = is24;
	}

	// Adds hours to the clock
	void addHours(int h) {
		this->hours += h;
		if (is24hrs && this->hours > 24) {
			this->hours -= 24;
		}
		else if (this->hours > 12) {
			this->hours -= 12;
		}
	}

	// Adds minutes to the clock.
	void addMinutes(int m) {
		this->minutes += m;
		if (this->minutes >= 60) {
			int i = this->minutes / 60;
			this->minutes -= 60 * i;
			this->addHours(i);
		}
	}

	// Adds seconds to the clock.
	void addSeconds(int s) {
		this->seconds += s;
		if (s >= 60) {
			int i = this->seconds / 60;
			this->seconds -= 60 * i;
			this->addMinutes(i);
		}
	}

	// Displays the clock's time in a printed format.
	void displayTime() {
		cout.fill('0');
		cout << setw(2);
		if (is24hrs) {
			cout << this->hours << ":" << setw(2) << this->minutes << ":" << setw(2) << this->seconds << " " << flush;
		}
		else {
			cout << ((this->hours == 0 || this->hours == 12) ? 12 : this->hours % 12) << ":" << setw(2) << this->seconds << " " << (this->hours > 12 ? "PM" : "AM") << flush;
		}
	}
};


// Displays Two instances of Clocks, usually one for 12 hours and 1 for 24 hours.
void displayClocks(Clock C12, Clock C24) {
	cout << "**************************" << "     " << "**************************\n";
	cout << "*      12-Hour Clock     *" << "     " << "*      24-Hour Clock     *\n";
	cout << "*      "; C12.displayTime();
	cout << "         *     *        ";
	C24.displayTime(); cout << "      *\n";
	cout << "**************************" << "     " << "**************************\n";
}

// Displays the menu.
void displayMenu() { 
	cout << "\n\t\t*************************" << endl;  
	cout << "\t\t" << "* 1 - Add One Hour\t*" << endl;
	cout << "\t\t" << "* 2 - Add One Minute\t*" << endl;
	cout << "\t\t" << "* 3 - Add One Second\t*" << endl;
	cout << "\t\t" << "* 4 - Exit Program\t*" << endl;
	cout << "\t\t" << "*************************" << endl;
}

// The main function.
int main() {
	Clock C12 = new Clock(false); // A new 12 Hour Clock instance.
	Clock C24 = new Clock(true); // A new 24 Hour Clock instance.

	int userInput = 0; // User input initializes at 0.

	while (userInput != 4) {
		displayClocks(C12, C24); // Displays the two clocks.
		displayMenu(); // Displays the menu.

		cin >> userInput; // Gets input from user.

		switch (userInput) {
		case 1:
			C12.addHours(1); // Adds 1 hour to both clocks
			C24.addHours(1);
			system("CLS"); // clears the old output
			break;
		case 2:
			C12.addMinutes(1); // Adds 1 Minute to both clocks
			C24.addMinutes(1);
			system("CLS");	// clears the old output
			break;
		case 3:
			C12.addSeconds(1); // Adds 1 Second to both clocks
			C24.addSeconds(1);
			system("CLS"); // clears the old output
			break;
		case 4:
			cout << "Exiting..." << endl; // Exits the program
			return 0;
		default:
			system("CLS"); // clears the old output
			break;
		}
	}
}