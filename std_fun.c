#include "mystd_f.h"

/**
 * _strcmp - compares s1 and s2
 * @s1: lhs
 * @s2 : rhs
 *
 * Return: returns copied string
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, dif = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (_strlen(s1) != _strlen(s2))
		return (_strlen(s1) - _strlen(s2));
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			dif++;
		i++;
	}
	return (dif);
}
/**
 * _strcat - appends a char to a string of words
 * @dest: destination
 * @src : word to add
 * Return: returns modified string
 */
char *_strcat(char *dest, const char *src)
{
	int d_size = (int) _strlen(dest), s_size = (int) _strlen(src), i, j;

	for (i = d_size, j = 0; i < (d_size + s_size); j++, i++)
	{
		dest[i] = src[j];
	}
	dest[d_size + s_size] = '\0';
	return (dest);
}
/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (-1);
	while (s[len] != '\0')
		len++;
	return (len);
}
