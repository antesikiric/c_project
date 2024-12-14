#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// korisnik unese prirodni broj a ja g pretvaram u binary s time da je zapis binarnog duljine 8
// pri spremanju koristi array


char* integerToBinary(int number) {
    int binary_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int reminder = 0;
    int i = 7;

    while (number > 0 && i >= 0) {
		reminder = number % 2;
		binary_array[i] = reminder;
		number = number / 2;
		i--;
    }
	char* binary_number = (char*)malloc(9 * sizeof(char));
	if (binary_number == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}
	for (int j = 0; j < 8; j++) {
		binary_number[j] = binary_array[j] + '0';
	}
	binary_number[8] = '\0';
	return binary_number;
}

int binaryToInteger(char* binary) {
	int number = 0;
	for (int i = 0; i < 8; i++) {
		number += (binary[i] - '0') * pow(2, 7 - i);
	}
	return number;
}

char* bitwiseAnd(int number1, int number2) {
	char* binary_1 = integerToBinary(number1);
	char* binary_2 = integerToBinary(number2);

	if (strlen(binary_1) != strlen(binary_2)) {
		fprintf(stderr, "Error: Binary strings must have the same length\n");
		exit(1);
	}
	int length = strlen(binary_1);
	char* result = (char*)malloc((length + 1) * sizeof(char));
	if (result == NULL) {
		perror("Memory alloction failed");
		exit(1);
	}

	for (int i = 0; i < length; i++) {
		if (binary_1[i] == '1' && binary_2[i] == '1') {
			result[i] = '1';
		} else {
			result[i] = '0';
		}
	}
	free(binary_1);
	free(binary_2);
	result[length] = '\0';
	return result;
}


char* bitwiseOr(int number_1, int number_2) {
	char* binary_1 = integerToBinary(number_1);
	char* binary_2 = integerToBinary(number_2);

	if (strlen(binary_1) != strlen(binary_2)) {
		fprintf(stderr, "Error: Binary strings must have the same length\n");
		exit(1);
	}
	int length = strlen(binary_1);
	char* result = (char*)malloc((length + 1) * sizeof(char));
	if (result == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}
	for (int i = 0; i < length; i++) {
		if (binary_1[i] == '1' || binary_2[i] == '1') {
			result[i] = '1';
		}
		else {
			result[i] = '0';
		}
	}
	free(binary_1);
	free(binary_2);
	result[length] = '\0';
	return result;
}

char* bitwiseXOR(int number_1, int number_2) {
	
}


int main() {
	int number_1, number_2;
	printf("Enter two integers: ");
	scanf("%d %d", &number_1, &number_2);

	char* resultAnd = bitwiseAnd(number_1, number_2);
	printf("bitwise AND for %d and %d is: %s", number_1, number_2, resultAnd);
	printf("\nResult as integer: %d", binaryToInteger(resultAnd));
	free(resultAnd);

	printf("\n-----------------------------------------------------------------\n");
	char* resultOr = bitwiseOr(number_1, number_2);
	printf("bitwise OR for %d and %d is: %s", number_1, number_2, resultOr);
	printf("\nResult as integer: %d", binaryToInteger(resultOr));
	free(resultOr);

	return 0;
}