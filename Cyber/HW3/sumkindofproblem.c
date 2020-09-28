/*
* Programmer: Sean Lowe
* Date: 03/12/2019
* Purpose: Independently testable solution to the Sum Kind of Problem kattis problem
*
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

int fP_num(int N) { return (N * (N + 1)) / 2; }
int fO_num(int N) { return (N * N); }
int fE_num(int N) { return N * (N + 1); } 

void actual_Test(int value, int exp1, int exp2, int exp3) {
    int result = 0; 
    // s1
    result = fP_num(value);
    assert(result == exp1);
    // s2
    result = fO_num(value);
    assert(result == exp2);
    // s3
    result = fE_num(value);
    assert(result == exp3);
    printf("All tests passed for %i . . .%s", value, "\n");
}

void test(int value) {
    switch (value) {
        case 2:
            actual_Test(value, 3, 4, 6);
            break;
        case 6:
            actual_Test(value, 21, 36, 42);
            break;
        case 7:
            actual_Test(value, 28, 49, 56);
            break;
        default:
            break;
    }
}

void solve() {
    int numDataSets = 0;
    int dummy = 0;
    int s1 = 0, s2 = 0, s3 = 0;
    scanf("%i", &numDataSets); // grab how many data sets we will have
    int sets[numDataSets];
    for (int i = 0; i < numDataSets; i++) {
        scanf("%i", &dummy); // thorw away line number
        scanf("%i", &sets[i]); // grab N for each data set
    }
    for (int i = 0; i < numDataSets; i++) {
        // calculate the sum of the first N pos #s (s1) n(n+1)/2
        s1 = fP_num(sets[i]);
        // s1 = (sets[i] * (sets[i] + 1)) / 2;
        // calculate the sum of the first N odd #s (s2) n^2
        s2 = fO_num(sets[i]);
        // s2 = (sets[i] * sets[i]);
        // calculate the sum of the first N even #s (s3) n*(n+1)
        s3 = fE_num(sets[i]);
        // s3 = sets[i] * (sets[i] + 1);

        printf("%i %i %i %i%s", i+1, s1, s2, s3, "\n");
    }
}


int main(int argc, char** argv) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) { 
        test(7);
        test(2);
        test(6);
    }
    else {
        solve();
    }
    return 0;
}