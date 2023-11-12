//
// Created by Celiac Signus on 11/2/23.
//

#include "cat.h"

void processFile(FILE *file, opt options) {
  int ch;
  int new_line = 1;
  int count = 1;
  int is_flag_s = 0;
  while ((ch = fgetc(file)) != EOF) {
    int is_flag_v = 0;
    if (options.flag_s == 1 && new_line && ch == '\n') {
      printSqueezeLines(ch, &is_flag_s, options.flag_n, options.flag_b,
                        options.flag_e, &count);
    }

    if (options.flag_s == 1 && new_line && ch != '\n') {
      is_flag_s = 0;
    }

    if (options.flag_n == 1 && new_line && options.flag_b != 1) {
      if (is_flag_s != 1) {
        printf("%6d\t", count++);
      }
    }

    if (options.flag_b == 1 && new_line && ch != '\n') {
      printf("%6d\t", count++);
    }
    if (options.flag_e == 1 && ch == '\n') {
      if (is_flag_s != 1) {
        printf("$");
      }
    }
    if (options.flag_v == 1) {
      printSpecialCharacter(ch, &is_flag_v);
    }

    if (options.flag_t == 1 && ch == '\t') {
      printf("^");
      ch = 'I';
    }

    if (is_flag_s != 1 && (is_flag_v == 0)) {
      printf("%c", ch);
    }

    new_line = (ch == '\n') ? 1 : 0;
  }
}