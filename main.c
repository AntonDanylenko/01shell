#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
  char *s = malloc(100);
  char *directory = malloc(100);
  getcwd(directory, 100);
  printf("%s: ", directory);
  fgets(s,100,stdin);
  char ** commands = parse_cmds(s);
  int i=0;
  while(commands[i]){
    //printf("commands[%d]: %s\n", i, commands[i]);
    char ** args = parse_args(commands[i]);
    if(!strcmp(args[0], "exit")){
      return 0;
    }
    else{
      execute(args);
    }
    /*int child = fork();
    //printf("child: %d\n", child);
    if(!child){
      //printf("child process\n");
      execute(args);
      exit(0);
    }
    else{
      //printf("parent process\n");
      wait(NULL);
    }*/
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
