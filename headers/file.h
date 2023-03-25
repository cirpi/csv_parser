#ifndef FILE_H
#define FILE_H

#include "include.h"

typedef enum {OPEN,CLOSE,ERROR} Status;

typedef struct {
	Status status;
	FILE* ptr;
} File;

File* load_file(string path);
string header(File* file);
#endif //FILE_H
