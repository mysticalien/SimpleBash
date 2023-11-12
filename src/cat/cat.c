//
// Created by Celiac Signus on 10/18/23.
//

#include "cat.h"

int main(int argc, char *argv[]) {
  opt options = {0};

  parseOptions(argc, argv, &options);

  while (optind < argc) {
    char *fileName = argv[optind];

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
      printf("Ошибка открытия файла.\n");
    } else {
      processFile(file, options);
      fclose(file);
    }

    optind++;
  }

  return 0;
}