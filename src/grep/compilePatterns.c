//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

regex_t *compilePatterns(char **patterns, int pattern_counter, opt options) {
  regex_t *reg_list = (regex_t *)malloc(pattern_counter * sizeof(regex_t));
  if (reg_list) {
    for (int j = 0; j < pattern_counter; j++) {
      regcomp(&reg_list[j], patterns[j],
              options.flag_i ? REG_ICASE | REG_EXTENDED : REG_EXTENDED);
    }
  } else {
    printf("Error");
  }
  return reg_list;
}
