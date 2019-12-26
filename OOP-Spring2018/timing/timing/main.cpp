#include <iostream>
#include <ctime>
using namespace std;


int main(int argc, char *argv[]) {
	const int maxRow = 4000;
	const int maxCol = 500;


	int array[maxRow][maxCol];
	double elapsed_secs = 0;


	/* the wrong way */

	clock_t begin = clock();
	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			array[j][i] = (i + j) + 100;
		}
	}
	clock_t end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "The wrong way took " << elapsed_secs << " seconds." << endl << endl;
	
	/* the correct way */

	begin = clock();
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			array[i][j] = (i + j) + 100;
		}
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "The right way took " << elapsed_secs << " seconds." << endl << endl;

	return 0;
}