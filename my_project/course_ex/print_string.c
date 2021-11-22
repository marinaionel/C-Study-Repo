#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 10

void string_(void) {
	char myS[MAX_STRING_LENGTH];
	strcpy(myS, "Ib");
	strcat(myS, " Havn");
	printf("\n");
	printf(myS);
}