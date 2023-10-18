#include "shell.h"

/**
 * execute_builtin - Execute a built-in shell command if it exists.
 * @command: The command to check and execute if it's a built-in.
 *
 * Description: This function checks if the given command is a built-in command
 * and, if it is, calls the associated function to execute it.
 *
 * Return: The exit status of the executed built-in command,
 * or -1 if not found.
 */
int execute_builtin(char *command)
{
int j = 0;
int (*builtin_func)(void) = NULL;

my_builtin_functions builtins[] = {
{"exit", exit_shell},
{"env", env_shell},
{NULL, NULL}
};

while (builtins[j].name != NULL)
{
if (_strcmp(command, builtins[j].name) == 0)
{
builtin_func = builtins[j].func;
break;
}
j++;
}

if (builtin_func)
return (builtin_func()); /* Call the built-in function */

return (-1); /* command not found */
}
