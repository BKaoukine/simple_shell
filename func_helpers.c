#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @string: The input string to determine the length of.
 *
 * Return: The length of the input string.
 */
int _strlen(const char *string)
{
int n = 0;

while (string[n])
{
n++;
}

return (n);
}

/**
* _strdup - Duplicate a string, allocating memory for the new copy.
* @string: The string to duplicate.
*
* Return: A new dynamically allocated string containing
* a copy of the input string.
*/
char *_strdup(char *string)
{
char *string2;
int m, i;

m = _strlen(string);

string2 = malloc(sizeof(char) * (m + 1));

if (string2 == NULL)
{
return (NULL);
}

for (i = 0; string[i]; i++)
{
string2[i] = string[i];
}

string2[i] = '\0';

return (string2);
}

/**
* _strcmp - Compare two strings lexicographically.
* @str1: The first string to compare.
* @str2: The second string to compare.
*
* Return: An integer less than, equal to, or greater than zero, depending on
* whether str1 is less than, equal to, or greater than str2.
*/
int _strcmp(char *str1, char *str2)
{
int i = 0;

while (str1[i])
{
if (str1[i] != str2[i])
return (str1[i] - str2[i]);
i++;
}
return (0);
}

/**
* _strcat - Concatenate two strings, appending the content of the second string
* to the end of the first string.
* @dest: The destination string to which the content is appended.
* @src: The source string whose content is appended to the destination.
*/
void _strcat(char *dest, char *src)
{
while (*dest != '\0')
{
dest++;
}

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}

*dest = '\0';
}
