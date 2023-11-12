//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void readPatternsFromFile(char *filename, char ***patterns,
                          int *pattern_counter, char **argv) {
  FILE *file = fopen(filename, "r");

  if (file != NULL) {
    char file_line[4096];
    while (fgets(file_line, BUFFER_SIZE, file) != NULL) {
      if (strchr(file_line, '\n')) *strchr(file_line, '\n') = '\0';
      addPattern(patterns, pattern_counter, file_line);
    }
    fclose(file);
  } else {
    fprintf(stderr, "%s: %s: No such file or directory", argv[0], filename);
  }
}