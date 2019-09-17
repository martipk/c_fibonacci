#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 	ONLY WORKS UP TO 93th Fibonacci number because the "unsigned 
	long long int" overflows at 18 446 744 073 709 551 615.

	usage: 
	 			gcc weak_fibonacci.c -o wfib
			./wfib MODE NUMBER"

	where MODE is either "only" or "upto"
	where NUMBER is the fibonacci number you want. (max is 94)
*/

int main(int argc, char *argv[]) {

	// error check command line
	int print;
	if (argc != 3) {
		fprintf(stderr, "Usage:\n\t Incorrect amount of arguments. Try ./wfib upto 14\n");
		return 1;
	} 
	char* mode = argv[1];
	if (strncmp(mode, "upto", strlen(mode)) == 0) {
		print = 1;
	} else if (strncmp(mode,"only", strlen(mode)) == 0) {
		print = 0;
	} else {
		fprintf(stderr, "Usage:\n\t Incorrect mode argument. Try ./wfib \"upto\" 14 or ./wfib \"only\" 14\n");
		return 1;
	}
	char *trash;
	int number = strtol(argv[2], &trash, 10);
	if ((strlen(trash) != 0)) {
		fprintf(stderr, "Usage:\n\t Argument not a number.\n");
		return 1;
	}
	if (number <= 0){
		fprintf(stderr, "Usage:\n\t Number can't be negative or null.\n");
		return 1;
	}/* else if (number > 93) {
		fprintf(stderr, "Usage:\n\t That number cannot be reached with this code, try ./wfib upto 94.\n");
		return 1;
	}*/
	number++;

	int i = 0;
	unsigned long long int f1 = 0;
	unsigned long long int f2 = 1;
	unsigned long long int f;
	if ((print == 1) && (number > 1)) {
		printf("0: %llu\n", f1);
		printf("1: %llu\n", f2);
	} else {
		if ((strncmp(mode, "upto", strlen(mode)) == 0) || (number == 1)) {
			printf("1: %llu\n", f1);
		}
	}

	while (i < number - 2) {
		f = f1 + f2;
		if (print == 1) {
			printf("%d: %llu\n", i+2, f);
		}
		f1 = f2;
		f2 = f;
		i++;
	}
	if ((print == 0) && (number > 1)) {
		printf("%d: %llu\n", i+1, f2);
	}
	return 0;
}
