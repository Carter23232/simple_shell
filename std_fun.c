#include "main.h"

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
	int total_size = 0, i, d = 0, s = 0;
	char *new_str;

	if (dest == NULL && src == NULL)
		return (NULL);

	total_size = (int) (_strlen(dest) + _strlen(src));
	new_str = malloc(sizeof(char) * (total_size + 1));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < total_size;)
	{
		while (dest[d] != '\0')
		{
			new_str[i] = dest[d];
			i++, d++;
		}
		while (src[s] != '\0')
		{
			new_str[i] = src[s];
			i++, s++;
		}
	}
	new_str[total_size] = '\0';
	return (new_str);
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

/**
 * free_ifnf - free given addresses if not freed
 * @format: argument container
 *
 */
void free_ifnf(const char *format, ...)
{
	va_list add;
	int i = 0;
	char *ptr_str = NULL;
	char **ptr_arr = NULL;

	va_start(add, format);
	if (format ==  NULL)
		return;
	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case 's':
				ptr_str = va_arg(add, char *);
				if (ptr_str != NULL)
					free(ptr_str);
				break;
			case 'a':
				ptr_arr = va_arg(add, char **);
				if (ptr_arr != NULL)
					free_str_arr(ptr_arr);
				break;
		}
		i++;
	}
	va_end(add);
}
