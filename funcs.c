#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "funcs.h"

char ** parse_cmds(char * line){
  /*
  Takes in a line from the user.
  Parses that line by semicolons and removes \n at the end.
  Returns array of commands.
  */
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
  /*
  Takes in a single command (Ex: ls ..).
  Parses that command by spaces into an array.
  Returns that array.
  */
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
  /*
  Takes in a single command (Ex: ls ..).
  Runs command as if it were run on the terminal.
  */
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
  /*
  Takes in a single command (Ex: ls ..).
  If the command includes > or < (Ex: ls .. > test.txt), executes command as a redirection.
  Otherwise, returns -1 and lets command be executed normally in the execute func.
  */
  char *input = malloc(10*sizeof(char *));
  char *file = malloc(100);
  char **args = malloc(10 * sizeof(char *));
  FILE *fp;
  //printf("In redirect\n");
  //printf("cmd: %s\n", cmd);
  //printf("strstr cmd: %s\n", strstr(cmd,">"));
  //printf("strchr cmd: %s\n", strchr(cmd,'>'));
  if (strchr(cmd, '>')){
    //printf("Sign is >\n");
    input = strsep(&cmd, ">");
    //printf("input: %s\n", input);
    file = parse_args(cmd)[0];
    //printf("file: %s\n", file);
    args = parse_args(input);
    fp = freopen(file, "w", stdout);
    execvp(args[0], args);
    fclose(fp);
  }
  else if (strchr(cmd, '<')){
    printf("Sign is <\n");
    input = strsep(&cmd, "<");
    printf("input: %s\n", input);
    file = parse_args(cmd)[0];
    printf("file: %s\n", file);
    args = parse_args(input);
    //fp = open(STDIN_FILENO, O_RDWR);
    int argfile = open(file, O_RDONLY);
    char *buf = malloc(100);
    read(argfile, buf, 100);
    write(STDIN_FILENO, buf, 100);
    execvp(args[0], args);
    close(argfile);
    /*char *buffer = malloc(100);
    fread(buffer, sizeof(char), 100, stdin);
    printf("stdin: %s\n", buffer);*/
  }
  else if (strchr(cmd, '|')){
    printf("Sign is |\n");
    input = strsep(&cmd, "|");
    printf("input: %s\n", input);
    args = parse_args(input);
    //char ** args1 = malloc(10 * sizeof(char *));
    printf("cmd: %s\n", cmd);
    /*int p[2];
    pipe(p);
    p[0] = popen(input, "r");
    p
    pclose(fp);*/
  }
  else {
    return -1;
  }
  /*int i=0;
  while(args[i]){
    printf("args[%d]: %s\n", i, args[i]);
    i++;
  }*/
  /*char *output = malloc(100);
  fgets(output,100,stdout);
  printf("output: %s\n", output);
  write(filedesc, output, 100);
  close(filedesc);*/
  return 0;
}
