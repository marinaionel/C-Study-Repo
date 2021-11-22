//
// Created by Marina Ionel on 26/02/2020.
//

#include "counting_duplicates.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//reverse string
//https://stackoverflow.com/a/784455
void reverse_string(char *str) {
    if (str == 0) {
        return;
    }

    if (*str == 0) {
        return;
    }

    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }
}


bool is_palindrome(const char *str_in) {
    int size = strlen(str_in);
    to_lowercase(str_in);
    char *t;
    t = malloc(size + 1);
    strcpy(t, str_in);
    reverse_string(t);
    bool r = (strcmp(t, str_in) ? false : true);
    free(t);
    return r;
}