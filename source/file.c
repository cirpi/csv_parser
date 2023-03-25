#include "../headers/file.h"


File* load_file(string path) {
	File* file=calloc(1, sizeof(file));
	if (file == NULL) {
		file->status = ERROR; 
		return NULL;
	}
	file->ptr = fopen(path, "r");
	if (file->ptr == NULL) {
		file->status = CLOSE;
		return NULL;
	}
	file->status = OPEN;
	return file;
}

string header(File* file) {
	int max = 100;
	if (file->status == 1) {
		printf("file is not open.\n");
		return NULL;
	}
	if (file->status == 2) {
		printf("error in the file\n");
		return NULL;
	}
	string buffer = calloc(max, sizeof(char));
	long index = 0;
	char chr;
	long count = 0;

	while ((chr = fgetc(file->ptr)) != '\n') {
		++count;
		if (count >= max - 1 ){
			max += max;
			buffer = realloc(buffer, max);
		}
		buffer[index++] = chr;
	}
	printf("buffer: %s\n", buffer);
	return buffer;
}
