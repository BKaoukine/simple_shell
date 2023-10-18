#include "shell.h"

/**
 * command_finder - Find the full path of a command in a list of directories.
 * @directories: An array of directory paths.
 * @command: The command to search for.
 *
 * Return: The full path of the command if found, or the command if not found.
 *
 * This function iterates through the @directories array and constructs
 * the full path of the @command by concatenating it with each directory path.
 * It then checks if the resulting file exists and is executable.
 * If an executable file is found, the function returns its full path.
 * If the command is not found in any directory, it returns the command itself.
 */
char *command_finder(char **directories, char *command)
{
int i;
struct stat file_info;

for (i = 0; directories[i] != NULL; i++)
{
/* Calculate the length needed for the full path */
size_t dir_length = _strlen(directories[i]);
size_t command_length = _strlen(command);
/* +2 for '/' and '\0' */
size_t fullpath_length = dir_length + command_length + 2;
/* Allocate memory for the full path */
char *fullpath = malloc(fullpath_length);
if (fullpath != NULL)
{
/* Construct the full path by concatenating the directory and command */
_strcpy(fullpath, directories[i]);
if (dir_length > 0 && directories[i][dir_length - 1] != '/')
{
_strcat(fullpath, "/"); /* Add '/' separator if not already present */
}
_strcat(fullpath, command);
/* Check if the file exists and is executable */
if (stat(fullpath, &file_info) == 0 && file_info.st_mode & S_IXUSR)
{
return (fullpath); /* Return the full path */
}
else
{
free(fullpath); /* Free memory if the file doesn't exist or isn't executable */
}
}
}

return (command); /* Command not found in any directory */
}
