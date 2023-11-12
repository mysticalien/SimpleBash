//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void processMatch(regex_t *reg_list, char *line, int k, int *line_num,
                  char **argv, int argc, int i, opt options, regmatch_t *match,
                  int *is_found, int new_opt) {
  if (regexec(reg_list + k, line, 1, match, 0) == 0) {
    *is_found = 1;
    if (options.flag_o && !options.flag_c) {
      int offset = 0;
      while (regexec(reg_list + k, line + offset, 1, match, 0) == 0) {
        if (!options.flag_l && !options.flag_s && !options.flag_v) {
          if (new_opt != (argc - 1) && options.flag_h != 1 && (offset == 0)) {
            printf("%s:", argv[i]);
          }
          if (options.flag_n && (offset == 0)) {
            printf("%d:", *line_num);
          }

          printf("%.*s\n", (int)(match->rm_eo - match->rm_so),
                 (line + offset + match->rm_so));
        }

        offset += match->rm_eo;
      }
    }
  }
}