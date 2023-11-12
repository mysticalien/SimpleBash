//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void freePatterns(char ***patterns, int pattern_counter) {
  if (*patterns != NULL) {
    for (int i = 0; i < pattern_counter; i++) {
      free((*patterns)[i]);
    }
    free(*patterns);
    *patterns = NULL;
  }
}
