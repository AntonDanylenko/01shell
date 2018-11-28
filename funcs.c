#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char *** parse_args(char * line){
  char ** arr = malloc(10 * sizeof(char *));
  char *** commands = malloc(100 * sizeof(char *));
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
      printf("arr[0]: %s\n", arr[0]);
      commands[ii][iii] = 0;
      strsep(&arr[ii], " ");
      printf("iii 2: %d\n", iii);
      printf("arr[0]: %s\n", arr[0]);
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
