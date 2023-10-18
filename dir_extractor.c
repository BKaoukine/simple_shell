#include "shell.h"
/**
 * remove_path - Remove a specific path from an environment variable.
 * @envir: The environment variable containing paths.
 * @path: The path to be removed.
 */
void remove_path(char *envir, const char *path) {
    char *match;
    int len = strlen(path);
    while ((match = _strstr(envir, path)) != NULL) {
        *match = '\0';
        _strcat(envir, match + len);
    }
}
/**
 * directories_extractor - Extract directories from a colon-separated path.
 * @path: The colon-separated path.
 *
 * Return: An array of directory strings or NULL on failure.
 */
char **directories_extractor(char *path)
{
char *token, *tmp, **command;
int commandlenght = 0, i = 0;

if (!path)
return (NULL);

tmp = _strdup(path);
token = strtok(tmp, ":");
if (token == NULL)
{
free(path);
free(tmp);
return (NULL);
}
while (token != NULL)
{
commandlenght++;
token = strtok(NULL, ":");
}
free(tmp);
command = malloc(sizeof(char *) * (commandlenght + 1));
if (!command)
{
free(path);
return (NULL);
}
tmp = _strdup(path);
token = strtok(tmp, ":");
while (token)
{
command[i] = _strdup(token); /* Allocate memory for each directory */
token = strtok(NULL, ":");
i++;
}
command[i] = NULL, free(tmp);
return (command);
}
