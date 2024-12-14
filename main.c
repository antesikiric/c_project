#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* integerToBinary(int number) {
    char* binary_number = (char*)malloc(33);
    if (binary_number == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    int index = 0;
    if (number == 0) {
        strcpy(binary_number, "0");
        return binary_number;
    }

    while (number > 0) {
        binary_number[index++] = (number % 2) + '0';
        number = number / 2;
    }
    binary_number[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char temp = binary_number[i];
        binary_number[i] = binary_number[index - 1 - i];
        binary_number[index - 1 - i] = temp;
    }
    return binary_number;
}

int main() {
    char* binary = integerToBinary(3);
    printf("Binary representation = %s\n", binary);
    free(binary);

    return 0;
}