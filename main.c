#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
  char *s = malloc(100);
  char *directory = malloc(100);
  while(1){
    getcwd(directory, 100);
    printf("%s: ", directory);
    fgets(s,100,stdin);
    char ** commands = parse_cmds(s);
    int i=0;
    while(commands[i]){
      execute(commands[i]);
      i++;
    }
  }
}
