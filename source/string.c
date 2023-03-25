#include "../headers/string.h"



int count_chars(string src, char delimeter) {
	int count = 0;
	size_t size = strlen(src);
	for (size_t i = 0; i < size; ++i) {
		if (src[i] == delimeter) ++count;
	}
	return count;
}

string trim(string src) {
	size_t size = strlen(src);
	bool is_start = false, is_end = false;
	size_t start_index = 0, end_index = size - 1;
	// comment
	while (start_index < end_index) {
		if (is_start && is_end) {
			printf("true\n");
			break;
		}
		if (src[start_index] != ' ') {
			is_start = true;
		} else {
			start_index += 1;
		}
		if (src[end_index] != ' ') {
			is_end = true;
		} else {
			end_index -= 1;
		}
	}
	printf("index %lu %lu\n", start_index, end_index);
	if (start_index == end_index)  {
		printf("not a valid string for trimming.");
		return src;
	}
	string new_src = calloc(end_index+1-start_index, sizeof(char));
	strncpy(new_src, &src[start_index], end_index-1);
	printf("new_src: |%s|\n", new_src);
	return new_src;
}

string_array* split(string src, char delimeter) {
	int MAX = 100;
	int delimeter_count = count_chars(src, delimeter);
	int size = strlen(src);

	string* res = calloc(delimeter_count + 1, sizeof(char*));
	int res_index = 0;

	string buffer = calloc(MAX, sizeof(char));
	int buffer_index = 0;

	int start = 0, end = 0;

	for (end = 0; end < size; ++end) {
		if (src[end] == delimeter) {
			memmove(buffer, &src[start], end-start);
			res[res_index] = calloc(strlen(buffer) + 1, sizeof(char));
			memmove(res[res_index], buffer, strlen(buffer));
			memset(buffer, 0, MAX);
			res_index += 1;
			start = end+1;
			buffer_index = 0;
			MAX = 100;
		} else {
			if (buffer_index+1 > MAX) {
				MAX += MAX;
				buffer = realloc(buffer, MAX);
			}
			buffer[buffer_index++] = src[end];
		}
	}
	if (strlen(buffer) > 0) {
		res[res_index] = calloc(strlen(buffer) + 1, sizeof(char));
		memmove(res[res_index], buffer, strlen(buffer));
	}
	free(buffer);
	string_array* array = calloc(1, sizeof(string_array));
	array->size = delimeter_count + 1;
	array->array = res;
	return array;
}

string capitalise(string src) {
	size_t size = strlen(src);
	string res = calloc(size + 1, sizeof(char));
	size_t i;
	for (i = 0; i < size; ++i) {
		if (i == 0 && src[i] >= 'a' && src[i] <= 'z') {
			res[i] = (char) (src[i] - 32);
		} else {
			res[i] = src[i];
		}
	}
	res[i] = '\0';
	return res;
}

