//
// Created by Celiac Signus on 11/11/23.
//
#include "grep.h"

void addPattern(char ***patterns, int *pattern_counter, char *new_pattern) {
  char **temp =
      (char **)realloc(*patterns, (*pattern_counter + 1) * sizeof(char *));
  if (temp) {
    *patterns = temp;
    (*patterns)[*pattern_counter] = (char *)malloc(strlen(new_pattern) + 1);
    if ((*patterns)[*pattern_counter]) {
      strncpy((*patterns)[*pattern_counter], new_pattern,
              strlen(new_pattern) + 1);
      (*pattern_counter)++;
    } else {
      printf("Error");
    }
  }
}
