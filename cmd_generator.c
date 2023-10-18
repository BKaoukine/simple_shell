#include "shell.h"
/**
 * command_generator - Tokenize a user input string into an array of commands.
 * @user_input: The user's input string.
 *
 * Return: An array of command strings or NULL on failure.
 *
 * This function tokenizes the input @user_input using ' ' and '\t'
 * as delimiters and stores the extracted commands in an array of strings.
 *  It returns the array of commands.
 */
char **command_generator(char *user_input)
{
char *token, *tmp, **command;
int commandlenght = 0, i = 0;
if (!user_input)
return (NULL);/* If the input is NULL, return NULL */
/* Duplicate the user input to avoid modifying the original string */
tmp = _strdup(user_input);
/* Tokenize the input using space and tab as delimiters */
token = strtok(tmp, DELIM);
if (token == NULL)
{/* Free allocated memory and return NULL if there are no tokens */
free(user_input);
free(tmp);
return (NULL);
}
while (token != NULL)
{/* Count the number of tokens to determine the array size */
commandlenght++;
token = strtok(NULL, DELIM);
}
free(tmp);/* Free the temporary duplicated string */
/* Allocate memory for the array of command strings */
command = malloc(sizeof(char *) * (commandlenght + 1));
if (!command)
{/* Free user input and return NULL if memory allocation fails */
free(user_input);
return (NULL);
}
/* Tokenize the original user input again and populate the command array */
token = strtok(user_input, DELIM);
while (token)
{
for (i = 0; i < commandlenght; i++)
{
command[i] = token;/* Assign each token to the command array */
token = strtok(NULL, DELIM);
}
}
/* Set the last element of the command array to NULL to terminate it */
command[i] = NULL;
return (command);
}
