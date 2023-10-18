#include "shell.h"

int _strlen(const char *string)
{
        int n = 0;

        while (string[n])
        {
                n++;
        }

        return (n);
}

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

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return (0);

}
void _strcat(char *dest, char *src)
{
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}
/**
 * _strstr - search a string for any of 1st bytes
 * @haystack: string to search
 * @needle: string with 1st character to look for
 *
 * Description: locate 1st occurrence in the string s or NULL if none
 *
 * Return: pointer to 1st byte in haystack that matches or NULL if none.
 */
char *_strstr(char *haystack,const char *needle)
{
/*Eterat throught the haystack*/
	for (; *haystack != '\0'; haystack++)
	{
/*Initialise two pointers to compare*/
		char *a = haystack;
		const char *b = needle;
/*Check if there's a match and move to next character*/
		while (*a == *b && *b != '\0')
		{
			a++;
			b++;
		}
/*if b reaches it's end and all characters where found return the haystack*/
		if (*b == '\0')
			return (haystack);
	}
/*if none was found return 0*/
	return (0);
}

void _strcpy(char *dest, char *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-') {
		sign = -1;

		i++;
	}

	for (; s[i] != '\0'; ++i)
		res = res * 10 + s[i] - '0';

	return sign * res;
}

int _strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
