#include "shell.h"

/**
 * env_shell - Implementation of the 'env' built-in command.
 *
 * This function iterates through the environment variables and prints them.
 *
 * Return: Always returns 0 to indicate success.
 */
int env_shell(void)
{
char **env;
for (env = environ; *env; env++)
{
        write(STDOUT_FILENO, *env, _strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
}
return (0);
}

/**
 * exit_shell - Implementation of the 'exit' built-in command.
 *
 * This function exits the shell with a status code of EXIT_SUCCESS.
 *
 * Return: This function does not return.
 */
int exit_shell(void)
{
int exit_code;
exit_code = EXIT_SUCCESS;
exit(exit_code);
/* This function does not return.*/
}
