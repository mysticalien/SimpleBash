//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void printMatch(char *line, char **argv, int argc, int i, opt options,
                int *line_num, int new_opt) {
  if (new_opt != (argc - 1) && !options.flag_h) {
    printf("%s:", argv[i]);
  }
  if (options.flag_n == 1) {
    printf("%d:%s\n", *line_num, line);
  } else {
    printf("%s\n", line);
  }
}
