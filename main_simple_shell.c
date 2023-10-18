#include "shell.h"

/**
 * main - Entry point of the shell program
 * @ac: The number of command-line arguments (unused)
 * @argv: An array of strings containing command-line arguments (unused)
 * Return: Always 0
 */
int main(int ac, char **argv)
{
char *user_input = NULL;
char **command = NULL;
(void)ac;  /* Unused argument */
(void)argv; /* Unused argument */

while (1)
{
user_input = read_user_input();
/* Generate a command from user input */
command = command_generator(user_input);
if (command)
{
if (_strcmp(command[0], "exit") == 0)
{
exit(0);
}
else
{
command_executer(command, argv); /* Execute the generated command */

}
}
else
{
continue; /* Skip to the next iteration if command generation fails */
}

free(user_input); /* Free memory allocated for user input */
}

return (0);
}
