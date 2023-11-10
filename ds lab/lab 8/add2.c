#include <stdio.h>
#include <string.h>

// Function to add two long positive integers as strings
char* addLongIntegers(char* num1, char* num2) {
    int maxLen = (strlen(num1) > strlen(num2)) ? strlen(num1) : strlen(num2);
    int result[maxLen + 1];
    int carry = 0;

    int i, j, k = 0;
    for (i = strlen(num1) - 1, j = strlen(num2) - 1; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = sum % 10;
    }

    // Convert the result to a string
    char* resultStr = (char*)malloc(maxLen + 2);
    int idx = 0;
    for (int l = k - 1; l >= 0; l--) {
        resultStr[idx++] = result[l] + '0';
    }
    resultStr[idx] = '\0';

    return resultStr;
}

int main() {
    char num1[100], num2[100];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);

    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    char* result = addLongIntegers(num1, num2);
    printf("Sum: %s\n", result);

    free(result);

    return 0;
}
