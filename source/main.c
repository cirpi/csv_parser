#include "../headers/string.h"
#include "../headers/file.h"

int main(int argc, char* argv[]) {
	File* file = load_file("/home/sirpi/C dev/csv_reader/demo.csv");
	printf("status: %d\n", file->status);
	string h = header(file);
	string_array* ar = split(h, ',');
	for (int i = 0; i < ar->size; ++i) {
		printf("i: %d, string: %s\n", i+1, ar->array[i]); 
	}
}
