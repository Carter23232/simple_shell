#include "main.h"

/**
 * _strcmp - compares s1 and s2
 * @s1: lhs
 * @s2 : rhs
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
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * free_ifnf - free given addresses if not freed
 * @format: argument container
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
