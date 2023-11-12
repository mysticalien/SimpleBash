//
// Created by Celiac Signus on 11/2/23.
//

#include "cat.h"

void printSpecialCharacter(int ch, int *is_flag_v) {
  if (ch >= 127 && ch < 160) {
    if (ch == 127) {
      printf("^?");
      *is_flag_v = 1;
    }
    if (ch > 127) {
      printf("M-^");
      putchar(ch - 64);
      *is_flag_v = 1;
    }
  }
  if (ch < 32 && ch != '\n' && ch != '\t') {
    printf("^");
    if (ch >= 0) {
      putchar(ch + 64);
    }
    if (ch < 0) {
      putchar(ch + 128);
    }
    *is_flag_v = 1;
  }
}