#ifndef MAIN
#define MAIN
#define DELIM " \t\n"

/*Libraries*/
#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


/* Globale Variables & Structures*/
extern char **environ;

/**
 * struct builtin - structure that contain builtin fuctions
 * @name: name of the function.
 * @func: the function it self
 */
typedef struct builtin
{
char *name;
int (*func)(void);
} my_builtin_functions;





/*Functions Prototypes*/
char *read_user_input(void);
char *get_user_input(void);
char **command_generator(char *user_input);
char *_getenv(char *name);
int command_executer(char **command, char **argv);
char *command_finder(char **directories, char *command);
void remove_path(char *envir, const char *path);
char **directories_extractor(char *path);
int env_shell(void);
int exit_shell(void);
int execute_builtin(char *command);

int _strlen(const char *string);
char *_strdup(char *string);
int _strcmp(char *str1, char *str2);
int _strncmp(char *s1, char *s2, int n);
void _strcpy(char *dest, char *src);
void _strcat(char *dest, char *src);
char *_strstr(char *haystack, const char *needle);
int _atoi(char *s);


#endif /*End of MAIN*/
