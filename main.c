#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
  /*if (argc > 1) {
    printf("argv[1]: %s\n", argv[1]);
    char *** args = parse_args(argv[2]);
    printf("args[0][0]: %s\n", args[0][0]);
    execvp(argv[1],args);
  }
  else {*/
  char *s = malloc(100);
  char *directory = malloc(100);
  getcwd(directory, 100);
  printf("%s: ", directory);
  fgets(s,100,stdin);
  char ** commands = parse_cmds(s);
  int i=0;
  while(args[i]){
    printf("args[%d]: %s\n", i, args[i]);
    i++;
  }
  /*int i=0;
  while(args){
    int child = fork();
    if(!child){
      int status;
      wait(&status);
    }
    else{
      int ii=0;
      while(args[i][ii]){
        printf("Arg %d: %s\n", ii, args[i][ii]);
        ii++;
      }
      printf("Null arg: %s\n", args[i][ii]);
      execvp(args[i][0], args[i]);
      i++;
    }
  }*/
  return 0;
}
