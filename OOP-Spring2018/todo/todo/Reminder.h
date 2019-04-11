#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


/* -----------------  */

enum priority {
	LOW,
	MEDIUM,
	HIGH
};

enum category {
	WORK,
	HOME,
	SCHOOL
};

struct item {
	item() { };
	item(string newTask, category newC, priority newP) {
		task = newTask;
		c = newC;
		p = newP;
	}
	string task = "NULL";
	priority p = LOW;
	category c = HOME;
};

/* -----------------  */




class Handler {
		/* Constructor */
protected: Handler() {
	running = true;
}

		   /* Getters */
protected:	bool getRunningState() {
	return running;
}


			/* Setters */
protected: void changeRunningState() {
	running = !getRunningState();
}


			/* Print Functions */
public: void cspb() {
	clearScreen();
	printBanner();
}

public: void clearScreen() {
	cout << flush;
	system("CLS");
}

public: void printBanner() {
	cout << "\n";
	cout << "                |---\\   |------- |\\      /| | |\\      | |---\\   |------- |---\\   /---\\  " << endl;
	cout << "                |    |  |        | \\    / | | | \\     | |    \\  |        |    |  |      " << endl;
	cout << "                |    |  |        |  \\  /  | | |  \\    | |     | |        |    |  |      " << endl;
	cout << "                |---/   |---     |   \\/   | | |   \\   | |     | |---	 |---/   \\---\\  " << endl;
	cout << "                |   \\   |        |        | | |    \\  | |     | |        |   \\        | " << endl;
	cout << "                |    \\  |        |        | | |     \\ | |    /  |	 |    \\       | " << endl;
	cout << "                |     \\ |------- |        | | |      \\| |---/   |------- |     \\ \\---/  " << endl;

	cout << "\n\n";
}

protected: void printUserInput() {
	cout << " > ";
}


		   /* virtual functions */
		   /* each of these functions would be different 
		   for every individual handler and as such should 
		   remain pure virtual voids */
protected: virtual void run()							= 0;
protected: virtual void readFiles(string file)			= 0;
protected: virtual void writeFiles(string file)			= 0;
protected: virtual void printMenu()						= 0;
protected: virtual void printSelectedReminderOptions()	= 0;
protected: virtual ~Handler() { }

		   /* descendent variables */
protected: ifstream fin;
protected: ofstream fout;

		   // variables 
private: bool running = false;
};




/* -----------------  */

class Reminder : public Handler {
		/* Constructor */
public:	Reminder() {
	num_input = -9999;
	y_n_input = 'q';
	list.clear();
	doneList.clear();
}


		/* conversion functions */
public: string categoryToString(int index) {
	if (list.at(index)->c == 0) return "WORK";
	if (list.at(index)->c == 1) return "HOME";
	if (list.at(index)->c == 2) return "SCHOOL";
}

public: category stringToCategory(string cat) {
	if (cat == "WORK") return WORK;
	if (cat == "HOME") return HOME;
	if (cat == "SCHOOL") return SCHOOL;
}

public: string priorityToString(int index) {
	if (list.at(index)->p == 0) return "LOW";
	if (list.at(index)->p == 1) return "MEDIUM";
	if (list.at(index)->p == 2) return "HIGH";
}

public: priority stringToPriority(string pri) {
	if (pri == "LOW") return LOW;
	if (pri == "MEDIUM") return MEDIUM;
	if (pri == "HIGH") return HIGH;
}


		/* view / running functions */
public: void showReminders(int depth = 0) {
	string tempP, tempC;
	if (depth == 0) {
		cout << "---------------------------------------------" << endl;
		cout << "Your Uncompleted Reminders: " << endl << endl;
	}
	if (!list.empty()) {
		for (int i = 0; i < list.size(); i++) {
			tempP = priorityToString(i);
			tempC = categoryToString(i);
			cout << i + 1 << ". \"" + list.at(i)->task + "\" exists in category " + tempC + " with priority: " + tempP << endl;
		}
		cout << endl;
		cout << "Choose an option." << endl;
		cout << "1. Edit a Reminder" << endl;
		cout << "2. Add a Reminder" << endl;
		cout << "3. View Completed Reminders" << endl;
		cout << "4. Back" << endl;
		printUserInput(); cin >> num_input;
		switch (num_input) {
		case 1:
			printSelectedReminderOptions();
			break;
		case 2:
			addNewReminder();
			break;
		case 3:
			viewCompleted();
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	else { // empty list
		if (depth == 0) cout << "You currently have no reminders. Would you like to set one? (Y/N)" << endl;
		printUserInput(); cin >> y_n_input;
		switch (y_n_input) {
		case 'y':
		case 'Y':
			addNewReminder();
			break;
		case 'n':
		case 'N':
			break;
		default:
			cout << "I'm sorry. I didn't catch that. Could you try again?" << endl;
			showReminders(1);
		}
	}
	//if (depth == 0) system("pause");
}

public: void addNewReminder() {
	string temp;
	item * t = new item();
	// task
	cout << "Enter a short description of the task." << endl;
	printUserInput(); cin.ignore();  getline(cin, temp);
	t->task = temp;

	// priority
	cout << "Choose a priority for your task." << endl;
	cout << "1. LOW\n2. MEDIUM\n3. HIGH\n";
	printUserInput(); cin >> num_input;
	switch (num_input) {
	case 1:
		t->p = LOW;
		break;
	case 2:
		t->p = MEDIUM;
		break;
	case 3:
		t->p = HIGH;
		break;
	default:
		t->p = LOW;
		break;
	}

	// category
	cout << "Choose a category for your task." << endl;
	cout << "1. WORK\n2. HOME\n3. SCHOOL\n";
	printUserInput(); cin >> num_input;
	switch (num_input) {
	case 1:
		t->c = WORK;
		break;
	case 2:
		t->c = HOME;
		break;
	case 3:
		t->c = SCHOOL;
		break;
	default:
		break;
	}

	// add to the list
	list.push_back(t);
}

public: void emptyLists() {
	list.clear();
	doneList.clear();
	return;
}

public: void viewCompleted() {
	cin.ignore();
	cspb();
	string tempP, tempC;
	cout << "---------------------------------------------" << endl;
	cout << "Your Completed Reminders: (press [Enter] to go back.)" << endl << endl;
	for (int i = 0; i < doneList.size(); i++) {
		tempP = priorityToString(i);
		tempC = categoryToString(i);
		cout << i + 1 << ". \"" + doneList.at(i)->task + "\" existed in category " + tempC + " with priority: " + tempP << endl;
	}
	printUserInput(); cin.ignore();
	return;
}

public: void readFiles(string file) {
	// make sure the files are in the same folder or it won't read....
	queue<char> q;
	char x = 's';
	string temp, enum1, enum2;
	if (file == filename) {		// reminders.txt
		fin.open(file, ifstream::in);
		if (!fin.is_open()) {	// error checking
			cout << "I couldn't read in the file." << endl;
			system("pause");
			return;
		}
		while (!fin.eof()) {
			fin.get(x);
			if (x == '|') {
				temp = "";
				int size = q.size();	// pop() decrements this so we need the full size before we start looping through it
				for (int i = 0; i < size; i++) {
					temp += q.front();	// grab the first char in the queue
					q.pop();			// remove that so we can grab the next char
				}
				q.empty();				// make sure the queue is empty for next go through
				fin >> enum1 >> enum2; fin.ignore();
				item * t = new item(temp, stringToCategory(enum1), stringToPriority(enum2));
				list.push_back(t);
			}
			else {
				q.push(x);
			}
		}
		fin.close();
	} else {					// completed.txt
		fin.open(file, ifstream::in);
		if (!fin.is_open()) {	// error checking
			cout << "I couldn't read in the file." << endl;
			system("pause");
			return;
		}
		while (!fin.eof()) {
			fin.get(x);
			if (x == '|') {
				temp = "";
				int size = q.size();
				for (int i = 0; i < size; i++) {
					temp += q.front();
					q.pop();
				}
				q.empty();
				fin >> enum1 >> enum2; fin.ignore();
				item * t = new item(temp, stringToCategory(enum1), stringToPriority(enum2));
				doneList.push_back(t);
			}
			else {
				q.push(x);
			}
		}
		fin.close();
	}
}

public: void writeFiles(string file) {
	// so you don't overwrite file ---> fout.open(filename, ios:app)
	if (file == filename) {		// reminders.txt
		fout.open("reminders.txt");
		
		for (int i = 0; i < list.size(); i++) {
			if (list.at(i)->task == "") continue;
			fout << list.at(i)->task;
			fout << "|";
			fout << categoryToString(list.at(i)->c);
			fout << " ";
			fout << priorityToString(list.at(i)->p);
			fout << "\n";
			
		}

		fout.close();
	} else {					// completed.txt
		fout.open("completed.txt");
		
		for (int i = 0; i < doneList.size(); i++) {
			if (doneList.at(i)->task == "") continue;
			fout << doneList.at(i)->task;
			fout << "|";
			fout << categoryToString(doneList.at(i)->c);
			fout << " ";
			fout << priorityToString(doneList.at(i)->p);
			fout << "\n";
		}

		fout.close();
	}
}

		/* Reminder Edit Fuctions */
public: string changeDescription() {
	string temp;
	cout << "Enter a short description of the task." << endl;
	printUserInput(); cin.ignore();  getline(cin, temp);
	return temp;
}

public: priority changePriority(int depth = 0) {
	if (depth == 0) {
		cout << "What priority would you like to switch it to?" << endl;
		cout << "1. LOW" << endl;
		cout << "2. MEDIUM" << endl;
		cout << "3. HIGH" << endl;
	}
	printUserInput(); cin >> num_input;
	switch (num_input) {
	case 1:
		return LOW;
	case 2:
		return MEDIUM;
	case 3:
		return HIGH;
	default:
		cout << "I didn't catch that. Try again?" << endl;
		changePriority(1);
		break;
	}
}

public: category changeCategory(int depth = 0) {
	if (depth == 0) {
		cout << "What category would you like to switch it to?" << endl;
		cout << "1. WORK" << endl;
		cout << "2. HOME" << endl;
		cout << "3. SCHOOL" << endl;
	}
	printUserInput(); cin >> num_input;
	switch (num_input) {
	case 1:
		return WORK;
	case 2:
		return HOME;
	case 3:
		return SCHOOL;
	default:
		cout << "I didn't catch that. Try again?" << endl;
		changeCategory(1);
		break;
	}
}

public: bool markCompleted() {
	return true;
}


		/* Print Functions */
public: void printMenu() {
	cout << "Choose an option: " << endl;
	cout << "1. View My Reminders" << endl;
	cout << "2. Add New Reminder" << endl;
	cout << "3. Quit The App" << endl;
	printUserInput();
}

public: void printSelectedReminderOptions() {
	int indexchoice;
	string tempP, tempC;
	cout << "Choose a reminder to edit: ";
	printUserInput(); cin >> indexchoice;
	cout << endl;
	try {
		if (list.at(indexchoice - 1)) {
			cout << "Choose an option: " << endl;
			cout << "1. Edit Task Description" << endl;
			cout << "2. Edit Task Priority" << endl;
			cout << "3. Edit Task Category" << endl;
			cout << "4. Mark Completed" << endl;
			printUserInput(); cin >> num_input;
			if (num_input == 4) {
				item * temp = list.at(indexchoice - 1);
				list.erase(list.begin() + indexchoice - 1);
				doneList.push_back(temp);
				num_input = -99;
			}
			switch (num_input) {
			case 1:
				list.at(indexchoice - 1)->task = changeDescription();
				break;
			case 2:
				list.at(indexchoice - 1)->p = changePriority();
				break;
			case 3:
				list.at(indexchoice - 1)->c = changeCategory();
				break;
			default:
				break;
			}
		}
	}
	catch (out_of_range) {
		cout << "Uh-oh! You gave us a scare there. That number doesn't have a reminder attached to it." << endl;
		cout << "We're going to send you back to the main menu for a moment while we gather our wits." << endl << endl;
		system("pause");
	}
}


		/* Main Run Function */
public: void run() {
	readFiles(filename);
	readFiles(filename2);

	while (getRunningState()) {
		cspb();

		// give options to see what the user wants to do
		printMenu();
		cin >> num_input;		// capture user input

		switch (num_input) {	// do something based on what user wants.
		case 1:				// view reminders
			cspb();
			showReminders();
			break;
		case 2:				// add reminder
			cspb();
			addNewReminder();
			break;
		case 3:				// quit
			changeRunningState();
			break;
		default:
			break;
		}
	}
	writeFiles(filename);
	writeFiles(filename2);
	emptyLists();
}

		/* variables */
private: char y_n_input;
private: int num_input;
private: string filename = "reminders.txt";
private: string filename2 = "completed.txt";
private: vector<item *> list;
private: vector<item *> doneList;
};