CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GREP = grep.c
PROCESS_FILES = addPattern.c compilePatterns.c freePatterns.c freeRegList.c parseOptions.c printMatch.c processFile.c processMatch.c readPatternsFromFile.c searchMatches.c

all: grep

grep: $(GREP) $(PROCESS_FILES)
	$(CC) $(CFLAGS) $^ -o $@

test:
	chmod 777 tests.sh
	./tests.sh

leeks:
	leaks -atExit -- ./grep

clean:
	rm -f grep

rebuild: clean all

.PHONY: all test leeks clean rebuild