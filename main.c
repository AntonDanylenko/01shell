#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  printf("Enter command:\n");
  fgets(s,100,stdin);
  char *** args = parse_args(s);
  int i=0;
  while(args[i]){
    int child = fork();
    if(!child){
      int status;
      wait(&status);
    }
    else{
      int ii=0;
      while(args[ii]){
        printf("Arg %d: %s\n", ii, args[ii]);
        ii++;
      }
      printf("Null arg: %s\n", args[ii]);
      execvp(args[0], args);
      i++;
    }
  }
  return 0;
}
