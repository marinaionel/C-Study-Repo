//
// Created by Marina Ionel on 01/03/2020.
//

#include "external_variables_and_scope.h"
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */


/* print longest input line; specialized version */

int external_variables_and_scope_run() {
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = external_variables_and_scope_get_line()) > 0)
        if (len > max) {
            max = len;
            external_variables_and_scope_copy();
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline: specialized version */
int external_variables_and_scope_get_line(void) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1
                && (c = getchar()) != EOF && c != '\n';
    ++i)
    line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */
void external_variables_and_scope_copy(void) {
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
