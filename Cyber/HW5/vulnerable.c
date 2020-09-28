#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	char buffer[100];
	strcpy(buffer, argv[1]);
	printf("Done!\n");
}
