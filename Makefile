CC=gcc
FLAGS=-Wall -Wextra -pedantic -o
DEBUG=-g
OUT=out
SOURCE=source
HEADER=headers

$(OUT)/main.out: $(SOURCE)/main.c $(OUT)/string.o $(OUT)/file.o
	$(CC) $(DEBUG) $(FLAGS) $@  $^

$(OUT)/string.o: $(HEADER)/string.h $(SOURCE)/string.c
	$(CC) -c $(DEBUG) $(FLAGS) $@ $(SOURCE)/string.c

$(OUT)/file.o: $(HEADER)/file.h $(SOURCE)/file.c
	$(CC) -c $(DEBUG) $(FLAGS) $@ $(SOURCE)/file.c

clean:
	rm -rf out/*
run:
	./out/main.out
debug:
	gdb ./out/main.out
mem:
	valgrind --leak-check=full ./out/main.out
