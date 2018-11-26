#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char *** parse_args(char * line){
  char ** arr = malloc(10 * sizeof(char *));
  char *** commands = malloc(10 * sizeof(char *));
  int i = 0;
  while(line){
    arr[i] = strsep(&line, ";");
    printf("arr[%d]: %s\n", i, arr[i]);
    i++;
  }
  if(i){
    strcpy(arr[i-1], strsep(&arr[i-1], "\n"));
  }
  printf("arr[%d]: %s\n", i-1, arr[i-1]);
  printf("end i: %d\n", i);
  int ii = 0;
  while(i-ii){
    int iii = 0;
    while (arr[ii]){
      printf("ii: %d\n", ii);
      printf("iii: %d\n", iii);
      commands[ii][iii] = strsep(&arr[ii], " ");
      printf("iii 2: %d\n", iii);
      iii++;
    }
    printf("ii: %d\n", ii);
    ii++;
  }
  printf("end loop");
  /*while(line){
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
  }*/
  return commands;
}
