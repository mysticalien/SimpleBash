CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CAT = cat.c
PROCESS_FILES = parseOptions.c processFile.c printSqueezeLines.c printSpecialCharacter.c

all: cat

cat: $(CAT) $(PROCESS_FILES)
	$(CC) $(CFLAGS) $^ -o $@

test:
	chmod 777 tests.sh
	./tests.sh

leeks:
	leaks -atExit -- ./cat

clean:
	rm -rf cat

rebuild: clean all

.PHONY: all test leeks clean rebuild