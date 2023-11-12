//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void freeRegList(regex_t **reg_list, int pattern_counter) {
  if (*reg_list != NULL) {
    for (int i = 0; i < pattern_counter; i++) {
      regfree(*reg_list + i);
    }
    free(*reg_list);
    *reg_list = NULL;
  }
}