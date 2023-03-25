#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char* string;
typedef struct {
	int size;
	string* array;
} string_array;



int count_chars(string src, char delimeter);
string trim(string src);
string_array* split(string src, char delimeter);
string capitalise(string src);
#endif
