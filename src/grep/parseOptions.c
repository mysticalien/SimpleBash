//
// Created by Celiac Signus on 11/11/23.
//
#include "grep.h"

void parseOptions(int argc, char *argv[], opt *options, char ***patterns,
                  int *pattern_counter) {
  int opt;
  while ((opt = getopt_long(argc, argv, "e:f:ivclnhso", 0, NULL)) != -1) {
    switch (opt) {
      case 'e':
        options->flag_e = 1;
        addPattern(patterns, pattern_counter, optarg);
        break;
      case 'f':
        options->flag_f = 1;
        readPatternsFromFile(optarg, patterns, pattern_counter, argv);
        break;
      case 'i':
        options->flag_i = 1;
        break;
      case 'v':
        options->flag_v = 1;
        break;
      case 'c':
        options->flag_c = 1;
        break;
      case 'l':
        options->flag_l = 1;
        break;
      case 'n':
        options->flag_n = 1;
        break;
      case 'h':
        options->flag_h = 1;
        break;
      case 's':
        options->flag_s = 1;
        break;
      case 'o':
        options->flag_o = 1;
        break;
      default:
        printf(
            "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B "
            "num] [-C[num]]\n"
            "        [-e pattern] [-f file] [--binary-files=value] "
            "[--color=when]\n"
            "        [--context[=num]] [--directories=action] [--label] "
            "[--line-buffered]\n"
            "        [--null] [pattern] [file ...]");
        break;
    }
  }
}