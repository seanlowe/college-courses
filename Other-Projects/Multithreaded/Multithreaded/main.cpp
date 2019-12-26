#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;
string s1, s2, complete;
mutex complete_mutex;

void combine(string &complete, string &s2) {
	cout << "Thread 2: Adding Part 2 to the final string." << endl;
	lock_guard<mutex> lock(complete_mutex);
	complete += s2;
}

void func() {
	combine(complete, s2);
}

int main() {
	for (int i = 0; i < 51; i++) {
		if (i < 25) {
			s1 = s1 + to_string(i) + " ";
		}
		else {
			s2 = s2 + to_string(i) + " ";
		}
	}
	cout << "Thread 1: Adding Part 1 to the final string. " << endl;

	// debug print statements
	//cout << s1 << endl << endl;
	//cout << s2 << endl;

	thread t1(func);

	complete += s1;

	t1.join();
	cout << "Threads have been rejoined." << endl << endl;
	cout << complete << endl;
	system("pause");
	return 0;
}