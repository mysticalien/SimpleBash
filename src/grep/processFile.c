//
// Created by Celiac Signus on 11/11/23.
//

#include "grep.h"

void processFile(const char *filename, char **patterns, int pattern_counter,
                 opt options, char **argv, int argc, int new_opt, int i) {
  int count_line = 0;
  int line_num = 1;
  int is_found = 0;
  int for_l = 0;
  char *line = malloc(BUFFER_SIZE);
  FILE *current_file = fopen(filename, "r");
  if (current_file == NULL) {
    if (options.flag_s != 1) {
      fprintf(stderr, "grep: %s: No such file or directory", filename);
    }
  } else {
    regex_t *reg_list = compilePatterns(patterns, pattern_counter, options);

    searchMatches(current_file, reg_list, pattern_counter, argv, argc, i,
                  options, line, &count_line, &line_num, &is_found, &for_l,
                  new_opt);

    if (options.flag_c == 1) {
      if (new_opt != (argc - 1) && options.flag_h != 1) {
        printf("%s:", argv[i]);
      }
      if (options.flag_l && (count_line > 0)) {
        count_line = 1;
      }
      printf("%d\n", count_line);
    }
    if (options.flag_l == 1 && for_l) {
      printf("%s\n", argv[i]);
    }
    fclose(current_file);
    freeRegList(&reg_list, pattern_counter);
  }
  if (line != NULL) {
    free(line);
  }
}