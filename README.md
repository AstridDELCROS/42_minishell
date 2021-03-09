## Minishell

NB : project done with @matboivin, I was in charge of the builtins implementation.

*Summary: The objective of this project is for you to create a simple shell. Yes, your own little bash or zsh. You will learn a lot about processes and file descriptors.*

The existence of shells is linked to the very existence of IT. At the time, all coders agreed that communicating with a computer using aligned 1/0 switches was seriously irritating. It was only logical that they came up with the ideato communicate with a computer using interactive lines of commands in a language somewhat close to english.

With Minishell, you’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.

|Program name|minishell|
|-|-|
|Makefile|yes|
|External functs|printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, termcap functions|
|Libft authorized|yes|
|Description|Write a shell.|

Your shell should:

- Not use more than one global variable, think about it and be ready to explain why you do it.
- Show a prompt when waiting for a new command.
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash.
- It must implement the builtins like in bash:
```
echo with option ’-n’
cd with only a relative or absolute path
pwd without any options
export without any options
unset without any options
env without any options and any arguments
exit without any options
```
- ;in the command should separate commands like in bash

Minishell As beautiful as a shell

- ’and"should work like in bash except for multiline commands
- Redirections< >“>>” should work like in bash except for file descriptor aggregation
- Pipes|should work like in bash except for multiline commands
- Environment variables ($followed by characters) should work like in bash
- $? should work like in bash
- ctrl-C,ctrl-Dandctrl-\should have the same result as in bash
- Use up and down arrows to navigate through the command using termcap (mandatory) history which we will then be able to edit (at least like we can for classic lines) if we feel like it (the line, not the history).