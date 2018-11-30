#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
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

void execute(char *command){
  //printf("commands[%d]: %s\n", i, commands[i]);
  char * cmd_cpy = malloc(10*sizeof(char *));
  strcpy(cmd_cpy, command);
  char ** args = parse_args(cmd_cpy);
  if(!strcmp(args[0], "exit")){
    exit(0);
  }
  else{
    //printf("execute func\n");
    if (!strcmp(args[0], "cd")){
      int val = chdir(args[1]);
      //printf("chdir value: %d\n", val);
    }
    else{
      int child = fork();
      if(!child){
        //printf("child process\n");
        if(redirect(command) == -1){
          execvp(args[0], args);
        }
      }
      else{
        //printf("parent process\n");
        wait(NULL);
      }
    }
  }
}

int redirect(char *cmd){
  char *input = malloc(10*sizeof(char *));
  char *sign = malloc(100);
  char *file = malloc(100);
  printf("In redirect\n");
  printf("cmd: %s\n", cmd);
  printf("strstr cmd: %s\n", strstr(cmd,">"));
  printf("strchr cmd: %s\n", strchr(cmd,'>'));
  if (strchr(cmd, '>')){
    printf("Sign is >\n");
    sign = ">";
  }
  else if (strchr(cmd, '<')){
    printf("Sign is <\n");
    sign = "<";
  }
  else {
    return -1;
  }
  input = strsep(&cmd, sign);
  printf("input: %s\n", input);
  file = cmd;
  printf("file: %s\n", file);
  int filedesc = open(file, O_WRONLY | O_CREAT);
  char **args = malloc(10 * sizeof(char *));
  args = parse_args(input);
  execvp(args[0], args);
  char *output = malloc(100);
  fgets(output,100,stdout);
  printf("output: %s\n", output);
  write(filedesc, output, 100);
  close(filedesc);
  return 0;
}
