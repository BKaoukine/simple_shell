
#include "shell.h"
/**
* _strstr - Search a string for any of 1st bytes.
* @haystack: String to search.
* @needle: String with 1st character to look for.
*
* Description: Locate the first occurrence in the string
* haystack or NULL if none.
*
* Return: Pointer to the first byte in haystack that matches or NULL if none.
*/
char *_strstr(char *haystack, const char *needle)
{
/* Iterate through the haystack */
for (; *haystack != '\0'; haystack++)
{
/* Initialize two pointers to compare */
char *a = haystack;
const char *b = needle;

/* Check if there's a match and move to the next character */
while (*a == *b && *b != '\0')
{
a++;
b++;
}

/* If b reaches its end and all characters were found, return the haystack */
if (*b == '\0')
return (haystack);
}

/* If none was found, return 0 */
return (0);
}

/**
* _strcpy - Copy a string from source to destination.
* @dest: The destination string to copy to.
* @src: The source string to copy from.
*/
void _strcpy(char *dest, char *src)
{
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
}

/**
* _atoi - Convert a string to an integer.
* @s: The string to be converted.
*
* Return: The integer converted from the string.
*/
int _atoi(char *s)
{
int res = 0;
int sign = 1;
int i = 0;

if (s[0] == '-')
{
sign = -1;
i++;
}

for (; s[i] != '\0'; ++i)
res = res * 10 + s[i] - '0';

return (sign *res);
}

/**
* _strncmp - Compare two strings lexicographically up to a specified length.
* @s1: The first string to compare.
* @s2: The second string to compare.
* @n: The maximum number of characters to compare.
*
* Return: An integer less than, equal to, or greater than zero, depending on
* whether s1 is less than, equal to, or greater than s2, up to the first n
* characters.
*/
int _strncmp(char *s1, char *s2, int n)
{
int i = 0;

while (s1[i] && s2[i] && i < n)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
}
return (0);
}
