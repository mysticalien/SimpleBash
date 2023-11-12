//
// Created by Celiac Signus on 11/2/23.
//

#include "cat.h"

void printSqueezeLines(int ch, int *is_flag_s, int flag_n, int flag_b,
                       int flag_e, int *count) {
  if (*is_flag_s == 0) {
    if (flag_n == 1 && flag_b == 0) {
      printf("%6d\t", (*count)++);
    }
    if (flag_e == 1) {
      printf("$");
    }
    printf("%c", ch);
  }
  *is_flag_s = 1;
}