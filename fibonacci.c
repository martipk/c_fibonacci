#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// incrase string length to be able to store more fibonacci numbers

#define LENGTH 20900 // rule of thumb, LENGTH should be around 22% of FIB_NUMBS for efficiency any less will overflow
#define FIB_NUMBS 100000
#define PRINT_INTERVAL 10000 // if this is too low, and the FIB_NUMBS is high, your ram will get filled up really quickly 
							 // since the terminal output is saved to ram

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
	printf("\n 1: 1\n\n");
	char* f2 = malloc(sizeof(char)*LENGTH);
	populate(f2);
	f2[LENGTH - 1] = '1';
	printf(" 2: 1\n\n");
	char* f;
	char* print = malloc(sizeof(char)*LENGTH);
	while (i < FIB_NUMBS - 2) {
		f = malloc(sizeof(char)*LENGTH);
		populate(f);
		summ(f1, f2, f);
		if (((i+3) % PRINT_INTERVAL) == 0) {
			printf(" %d: %s\n\n", i+3, printclean(f, print));
		}
		free(f1);
		f1 = f2;
		f2 = f;
		i++;
	}
	return 0;
}
