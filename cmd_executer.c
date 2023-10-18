#include "shell.h"

/**
 * command_executer - Execute a command with error handling.
 * @command: An array of command arguments.
 * @argv: An array of program arguments.
 *
 * Return: The exit status of the executed command.
 *
 * This function forks a child process to execute the given @command. It prints
 * the command being executed and checks if the execution succeeds. If the
 * command is not found in the current directory, it searches for it in the
 * directories listed in the "PATH" environment variable.
 */
int command_executer(char **command, char **argv)
{
pid_t child_processor;
int exit_status, j = 0;
char **directories, *fullpath;
char *path_value = _getenv("PATH");
int (*builtin_func)(void) = NULL;

my_builtin_functions builtins[] = {
{"exit", exit_shell},
{"env", env_shell},
{NULL, NULL}
};
if (!path_value)
{
fprintf(stderr, "PATH environment variable not found\n");
return (1);
}
child_processor = fork();
if (child_processor == 0)
{
directories = directories_extractor(path_value);
fullpath = command_finder(directories, command[0]);
if (fullpath)
{
command[0] = fullpath;
if (execve(fullpath, command, environ) == -1)
{
while (builtins[j].name != NULL)
{
if (_strcmp(command[0], builtins[j].name) == 0)
{
builtin_func = builtins[j].func;
break;
}
j++;
}

if (builtin_func)
{
return (builtin_func()); /* Call the built-in function */
}

perror(argv[0]);
free(command);
exit(100);
}
}
/* fprintf(stderr, "%s: command not found\n", command[0]); */
perror(command[0]);
free(command);
exit(127);
}
else if (child_processor < 0)
{
perror("Fork failed");
exit(1);
}
else
{/* Wait for the child process to finish */
waitpid(child_processor, &exit_status, 0);
free(command);
}
return (WEXITSTATUS(exit_status));
}
