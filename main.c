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
    printf("Need more arguments.\n" );
  }
  return 0;
}
