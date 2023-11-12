//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void searchMatches(FILE *current_file, regex_t *reg_list, int pattern_counter,
                   char **argv, int argc, int i, opt options, char *line,
                   int *count_line, int *line_num, int *is_found, int *for_l,
                   int new_opt) {
  while (fgets(line, BUFFER_SIZE, current_file) != NULL) {
    *is_found = 0;
    if (strchr(line, '\n')) *(strchr(line, '\n')) = '\0';
    regmatch_t match;

    for (int k = 0; k < pattern_counter; k++) {
      processMatch(reg_list, line, k, line_num, argv, argc, i, options, &match,
                   is_found, new_opt);
    }

    if (!options.flag_o && options.flag_v == 1 && !options.flag_c &&
        !options.flag_l && !*is_found) {
      printMatch(line, argv, argc, i, options, line_num, new_opt);
    }

    if (!options.flag_o && !options.flag_c && !options.flag_l && *is_found &&
        !options.flag_v) {
      printMatch(line, argv, argc, i, options, line_num, new_opt);
    }

    if ((*is_found && options.flag_l && !options.flag_v) ||
        (!*is_found && options.flag_l && options.flag_v)) {
      *for_l = 1;
    }

    if (options.flag_o && options.flag_v && !*is_found && !options.flag_l &&
        !options.flag_c) {
      printMatch(line, argv, argc, i, options, line_num, new_opt);
    }

    if (*is_found && !options.flag_v && options.flag_c) {
      (*count_line)++;
    } else if (!*is_found && options.flag_v && options.flag_c) {
      (*count_line)++;
    }

    (*line_num)++;
  }
}
