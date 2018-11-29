#ifndef FUNCS_H
#define FUNCS_H

char ** parse_cmds(char *);
char ** parse_args(char *);
void execute(char *);
int redirect(char *);

#endif
