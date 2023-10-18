#include "shell.h"

/**
 * read_user_input - Read a line of input from the user.
 *
 * Return: A pointer to the user's input string, or NULL on failure.
 */
char *read_user_input(void)
{
char *user_input = get_user_input(); /* Get user input from the shell */

if (user_input == NULL)
{
if (isatty(STDIN_FILENO))
{
/* Print "exit" and exit if input is NULL */
write(STDOUT_FILENO, "\nexit\n", 6);
exit(98);
}
else
{
    /* Exit if input is NULL in non-interactive mode */
exit(0);
}
}
return (user_input);
}

/**
 * get_user_input - Read a line of input from the user.
 *
 * Return: A pointer to the user's input string, or NULL on failure.
 */
char *get_user_input(void)
{
char *line = NULL;

ssize_t getlinevalue;
size_t lenghtofline = 0;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2); /* Print shell prompt */

getlinevalue = getline(&line, &lenghtofline, stdin); /* Read user input */

if (getlinevalue == -1)
{
free(line); /* Free memory allocated for the line */
return (NULL);
}

return (line);
}
