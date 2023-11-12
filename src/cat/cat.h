//
// Created by Celiac Signus on 10/21/23.
//

//#ifndef C3_SIMPLEBASHUTILS_1_S21_CAT_H
//#define C3_SIMPLEBASHUTILS_1_S21_CAT_H
//
//#endif //C3_SIMPLEBASHUTILS_1_S21_CAT_H

#include <ctype.h>
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct options {
  int flag_b;
  int flag_e;
  int flag_n;
  int flag_s;
  int flag_t;
  int flag_v;
} opt;

void parseOptions(int argc, char *argv[], opt *options);
void printSpecialCharacter(int ch, int *is_flag_v);
void printSqueezeLines(int ch, int *is_flag_s, int flag_n, int flag_b,
                       int flag_e, int *count);
void processFile(FILE *file, opt options);