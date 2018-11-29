#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "funcs.h"

char ** parse_cmds(char * line){
  char ** arr = malloc(10 * sizeof(char *));
  int i = 0;
  while(line){
    arr[i] = strsep(&line, ";");
    //printf("arr[%d]: %s\n", i, arr[i]);
    i++;
  }
  strcpy(arr[i-1], strsep(&arr[i-1], "\n"));
  //printf("arr[%d]: %s\n", i-1, arr[i-1]);
  return arr;
}

char ** parse_args(char *cmd){
  char ** arr = malloc(10 * sizeof(char *));
  int i = 0;
  while(cmd){
    char *temp = strsep(&cmd, " ");
    if(strcmp(temp,"") ){
      arr[i] = temp;
      //printf("arr[%d]: %s\n", i, arr[i]);
      i++;
    }

  }
  return arr;
}

void execute(char **args){
  printf("execute func\n");
  if (!strcmp(args[0], "cd")){
    int val = chdir(args[1]);
    printf("chdir value: %d\n", val);
  }
  else if(!strcmp(args[0], "exit")){

  }
  else{
    int child = fork();
    if(!child){
      //printf("child process\n");
      execvp(args[0], args);
    }
    else{
      //printf("parent process\n");
      wait(NULL);
    }
  }
}
