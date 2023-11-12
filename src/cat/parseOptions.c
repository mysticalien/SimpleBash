//
// Created by Celiac Signus on 11/2/23.
//

#include "cat.h"

static struct option long_options[] = {{"number-nonblank", no_argument, 0, 'b'},
                                       {"number", no_argument, 0, 'n'},
                                       {"squeeze-blank", no_argument, 0, 's'},
                                       {0, 0, 0, 0}};

void parseOptions(int argc, char *argv[], opt *options) {
  int opt;
  while ((opt = getopt_long(argc, argv, "+nbsetTvE", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'n':
        options->flag_n = 1;
        break;
      case 'b':
        options->flag_b = 1;
        options->flag_n = 0;
        break;
      case 's':
        options->flag_s = 1;
        break;
      case 'e':
        options->flag_e = 1;
        options->flag_v = 1;
        break;
      case 't':
        options->flag_t = 1;
        options->flag_v = 1;
        break;
      case 'v':
        options->flag_v = 1;
        break;
      case 'T':
        options->flag_t = 1;
        break;
      case 'E':
        options->flag_e = 1;
        break;
      default:
        printf("cat: wrong option!");
        break;
    }
  }
}