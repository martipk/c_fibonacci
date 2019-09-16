#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// METHOD 1: ONLY WORKS UP TO 94th Fibonacci number because of 
// unsigned long long int overflows at 18 446 744 073 709 551 615.

/* int main() {
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
*/

// METHOD 2: WORKS UP TO 1218th Fibnocci number

#define LENGTH 255
#define FIB_NUMBS 1218 // MAX is 1218

void populate(char* str){
	int i = LENGTH - 1;
	str[LENGTH] = '\0';
	while (i > -1) {
		str[i] = '0';
		i--;
	}
}

void summ(char* str1, char* str2, char* str3) {
	int i = LENGTH - 1;
	while (i > 0) {
		int a = str1[i] - '0';
		int b = str2[i] - '0';
		if (a + b + str3[i] - '0' < 10) {
			str3[i] = (a+b) + str3[i];
		} else {
			str3[i] = (a+b+ str3[i]-'0') % 10 + '0';
			str3[i-1] = 1 + '0';
		}
		i--;
	}
}

char* printclean(char* str, char* res) {
	int i = 0;
	int j = 0;
	while ((i < LENGTH) && (str[i] == '0')) {
		i++;
	}
	while (i < LENGTH) {
		res[j] = str[i];
		j++; i++;
	}
	res[j] = '\0';
	return res;
}

int main() {
	int i = 0;

	char* f1 = malloc(sizeof(char)*LENGTH);
	populate(f1);
	f1[LENGTH - 1] = '1';
	printf("1: 1\n");
	char* f2 = malloc(sizeof(char)*LENGTH);
	populate(f2);
	f2[LENGTH - 1] = '1';
	printf("2: 1\n");
	char* f;
	char* print = malloc(sizeof(char)*LENGTH);
	while (i < FIB_NUMBS - 2) {
		f = malloc(sizeof(char)*LENGTH);
		populate(f);
		summ(f1, f2, f);
		printf("%d: %s\n", i+3, printclean(f, print));
		free(f1);
		f1 = f2;
		f2 = f;
		i++;
	}
	return 0;
}
