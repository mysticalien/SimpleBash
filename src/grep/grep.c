//
// Created by Celiac Signus on 10/18/23.
//

#include "grep.h"

int main(int argc, char *argv[]) {
  opt options = {0};
  int pattern_counter = 0;
  char **patterns = NULL;
  parseOptions(argc, argv, &options, &patterns, &pattern_counter);
  int num_arg = optind;
  int new_opt = optind;

  while (num_arg < argc) {
    if (!options.flag_e && argc != optind && !options.flag_f &&
        num_arg == optind) {
      addPattern(&patterns, &pattern_counter, argv[optind]);

      num_arg++;
      new_opt++;
    } else if (argc == optind) {
      printf("Error!");
    } else {
      for (int i = num_arg; i < argc; i++) {
        processFile(argv[i], patterns, pattern_counter, options, argv, argc,
                    new_opt, i);
        num_arg++;
      }
    }
  }

  freePatterns(&patterns, pattern_counter);
  return 0;
}