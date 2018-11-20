#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char ** parse_args(char * line){
  char ** arr = malloc(6 * sizeof(char *));
  int i;
  for (i = 0; i < 6; i++) {
    arr[i] = strsep(&line, " ");
  }
  return arr;
}
