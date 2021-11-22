#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void to_lowercase(char *str) {
    int sizeOfArray = strlen(str);
    for (int i = 0; i < sizeOfArray; i++) {
        str[i] = tolower(str[i]);
    }
}

int countOccurrences(char *arr, char theElement) {
    size_t sizeOfArray = strlen(arr);
    int result = 0;
    for (int i = 0; i < sizeOfArray; i++)
        if (theElement == arr[i])
            result++;
    return result;
}

void sortArray(char *string) {
    char temp;

    int i, j;
    int n = strlen(string);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (string[i] > string[j]) {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}

int duplicate_count(const char *text) {
    int ascii_letters[123] = {0}, arraySize = strlen(text), result = 0;
    char *pTmp;

    pTmp = malloc(arraySize + 1);
    strcpy(pTmp, text);
    to_lowercase(pTmp);

    for (int i = 0; i < arraySize; i++) {
        ascii_letters[(int) pTmp[i]]++;
    }

    for (int j = 0; j < 123; j++) {
        if (ascii_letters[j] > 1)
            result++;
    }

    free(pTmp);
    return result;
}

// SMART SOLUTION
//size_t duplicate_count(const char* text) {
//    int freq[128] = {0}, dups = 0;
//    while (*text) dups += ++freq[tolower(*text++)] == 2;
//    return dups;
//}