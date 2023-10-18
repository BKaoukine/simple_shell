#include "shell.h"

/**
 * _getenv - Retrieve the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Description: This function searches the environment variables to find
 * a match with the given name and returns its value. If the variable is not
 * found, it returns NULL.
 *
 * Return: A pointer to the value of the environment
 * variable, or NULL if not found.
 */
char *_getenv(char *name)
{
char **env;

for (env = environ; *env != NULL; env++)
{
char *variable = *env;
if (_strncmp(variable, name, _strlen(name)) == 0 &&
variable[strlen(name)] == '=')
{
/* Found the variable, return the value */
return (variable + _strlen(name) + 1);
}
}

/* Variable not found */
return (NULL);
}
