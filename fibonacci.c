#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// METHOD 1: ONLY WORKS UP TO 94th Fibonacci number because of 
// unsigned long long int overflows at 18 446 744 073 709 551 615.

int main() {
	int i = 0;
	unsigned long long int f1 = 0;
	unsigned long long int f2 = 1;
	unsigned long long int f;
	printf("1: %llu\n", f1);
	printf("2: %llu\n", f2);

	while (i < 98) {
		f = f1 + f2;
		printf("%d: %llu\n", i+3, f);
		f1 = f2;
		f2 = f;
		i++;
	}
	return 0;
}