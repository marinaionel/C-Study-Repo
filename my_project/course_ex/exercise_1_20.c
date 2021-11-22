//
// Created by Marina Ionel on 01/03/2020.
//

#include <stdio.h>

//Write a program detab that replaces tabs in the input with the proper number
//of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
//Should n be a variable or a symbolic parameter?

//1 tab = 4 spaces

#define TABINC 4

int detab() {
    int nb = 0, position = 1;
    char character;
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            nb = TABINC - ((position - 1) % TABINC);
            while (nb > 0) {
                putchar('_');
                ++position;
                --nb;
            }
        } else if (character == '\n') {
            putchar(character);
            position = 1;
        } else {
            putchar(character);
            ++position;
        }
    }
    return 0;
}
