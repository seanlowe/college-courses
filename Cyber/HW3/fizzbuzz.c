/*
* Programmer: Sean Lowe
* Date: 03/12/2019
* Purpose: Independently testable solution to the FizzBuzz kattis problem
*
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

void test(int n1, int n2, int n3) {
	int n3_extra = n3;
	// for some reason, n3 turns to 0 on my last test (5, 4, 22) 
	// sometime before the end of this function.. a little workaround here.
	int *arr[n3];
	switch (n1) {
		case 1:
			loop(2, 4, 6, 1, &arr);
			assert(arr[3] == 4);
			assert(arr[4] == 3);
		case 3:
			loop(3, 5, 11, 1, &arr);
			assert(arr[6] == 1);
			assert(arr[10] == 2);
			break;
		case 5:
			loop(5, 4, 22, 1, &arr);
			assert(arr[18] == 4);
			assert(arr[20] == 3);
			break;
		default:
			break;
	}
	printf("All tests passed for sequence %i %i %i . . . %s", n1, n2, n3_extra, "\n");
}

void loop(int num1, int num2, int num3, int testVar, int *arr[]) {
	// make sure testVar is 0 if calling from solve and 1 if calling from test
	// strings in c suck so output a number to the arr for each option
	// 1 for Fizz
	// 2 for Buzz
	// 3 for FizzBuzz
	// 4 for regular number (nothing)
	for (int i = 1; i <= num3; i++) {
		if (i % num1 == 0 && i % num2 == 0) {
			testVar ? arr[i] = 3 : printf("FizzBuzz\n");
		} else if (i % num1 == 0) {
			testVar ? arr[i] = 1 : printf("Fizz\n");
		} else if (i % num2 == 0) {
			testVar ? arr[i] = 2 : printf("Buzz\n");
		} else {
			testVar ? arr[i] = 4 : printf("%i%s", i, "\n");
		}
	}
}


void solve() {
	int num1, num2, num3; num1 = num2 = num3 = 0;
	scanf("%i", &num1);
	scanf("%i", &num2);
	scanf("%i", &num3);
	loop(num1, num2, num3, 0, NULL);
}


int main(int argc, char** argv) {
	if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {
		test(2, 4, 6);
		test(3, 5, 11);
		test(5, 4, 22);
	} else {
		solve();
	}
	return 0;
}