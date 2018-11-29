#ifndef FUNCS_H
#define FUNCS_H

char ** parse_cmds(char *);
char ** parse_args(char *);
void execute(char **);
void redirect(char **);

//struct cmdlog{char *, }
#endif
