//
// Created by Celiac Signus on 11/2/23.
//

#ifndef C3_SIMPLEBASHUTILS_1_S21_GREP_H
#define C3_SIMPLEBASHUTILS_1_S21_GREP_H

#endif  // C3_SIMPLEBASHUTILS_1_S21_GREP_H

#include <ctype.h>
#include <getopt.h>
#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct options {
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
} opt;

void addPattern(char ***patterns, int *pattern_counter, char *new_pattern);
regex_t *compilePatterns(char **patterns, int pattern_counter, opt options);
void freePatterns(char ***patterns, int pattern_counter);
void freeRegList(regex_t **reg_list, int pattern_counter);
void parseOptions(int argc, char *argv[], opt *options, char ***patterns,
                  int *pattern_counter);
void printMatch(char *line, char **argv, int argc, int i, opt options,
                int *line_num, int new_opt);
void processFile(const char *filename, char **patterns, int pattern_counter,
                 opt options, char **argv, int argc, int new_opt, int i);
void processMatch(regex_t *reg_list, char *line, int k, int *line_num,
                  char **argv, int argc, int i, opt options, regmatch_t *match,
                  int *is_found, int new_opt);
void readPatternsFromFile(char *filename, char ***patterns,
                          int *pattern_counter, char **argv);
void searchMatches(FILE *current_file, regex_t *reg_list, int pattern_counter,
                   char **argv, int argc, int i, opt options, char *line,
                   int *count_line, int *line_num, int *is_found, int *for_l,
                   int new_opt);
