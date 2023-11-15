#include "main.h"
/**
 * removeNewlineFromStr - removes trailing spaces from string
 * @string: input string
 * Return: an edited string
 */
char *removeNewlineFromStr(char *string)
{
	size_t  len = _strlen(string), i = 0, j = 0;

	for (i = 0 ; i < len; i++)
	{
		if (string[0] == '\n')
		{
			for (i = 0; i < (len - 1); i++)
				string[i] = string[i + 1];
			string[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (string[i] == '\n' && string[i + 1] == '\n')
		{
			for (j = i; j < (len - 1); j++)
			{
				string[j] = string[j + 1];
			}
			string[j] = '\0';
			len--;
			i--;
		}
		else if (string[i] == '\n' && string[i + 1] == '\0')
			string[i] = '\0';
	}
	return (string);
}