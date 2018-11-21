#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("argv[1]: %s\n", argv[1]);
    char ** args = parse_args(argv[2]);
    printf("args[0]: %s\n", args[0]);
    execvp(argv[1],args);
  }
  else {
    char *s = malloc(100);
    printf("Enter command:\n");
    fgets(s,100,stdin);
    char ** args = parse_args(s);
    int x=0;
    while(args[x]){
      printf("Arg %d: %s\n", x, args[x]);
      x++;
    }
    printf("Null arg: %s\n", args[x]);
    execvp(args[0], args);
  }
  return 0;
}
