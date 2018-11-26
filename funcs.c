#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char *** parse_args(char * line){
  char ** arr = malloc(7 * sizeof(char *));
  char *** commands = malloc(5 * sizeof(arr));
  int i = 0;
  while(line){
    int ii = 0;
    while(arr[ii] = strsep(&line, " ") && strcmp(arr[ii], ";")){
      ii++;
    }
    if(!ii){
      strcpy(arr[ii-1], strsep(&arr[ii-1], "'s'\n"));
    }
    arr[ii] = NULL;
    commands[i] = arr;
    i++;
  }
  return commands;
}
