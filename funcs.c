#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char ** parse_args(char * line){
  char ** arr = malloc(7 * sizeof(char *));
  int i = 0;
  while(line){
    arr[i] = strsep(&line, " ");
    i++;
  }
  if(i){
    strcpy(arr[i-1], strsep(&arr[i-1], "'s'\n"));
  }
  arr[i] = NULL;
  return arr;
}
