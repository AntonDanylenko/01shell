# proj01Systems
by Anton Danylenko

#### Features:
* Shows current directory!
*	Forks and executes commands!
*  Exit and cd commands work!
*	Parses multiple commands on one line!
*	Redirects using >!
*  Ignores whitespace!
  
#### Attempted:
*  Was unable to redirect with <.
*  Was unable to get pipes working.
  
#### Bugs:
*  Attempting to use < will open the shell inside itself so exit has to be run.
*  Running two semicolons consecutively will result in a seg fault.
*  Running a single command with a semicolon after it will result in a seg fault.
  
#### Files and Functions:
funcs.c
  (Handles all helper functions.)
  
  * parse_cmds()
    * Takes in a line from the user.
    * Parses that line by semicolons and removes \n at the end.
    * Returns array of commands.
  
  * parse_args()
    * Takes in a single command (Ex: ls ..).
    * Parses that command by spaces into an array.
    * Returns that array.
    
  * execute()
    * Takes in a single command (Ex: ls ..).
    * Runs command as if it were run on the terminal.
    
  * redirect()
    * Takes in a single command (Ex: ls ..).
    * If the command includes > or < (Ex: ls .. > test.txt), executes command as a redirection.
    * Otherwise, returns -1 and lets command be executed normally in the execute func.
