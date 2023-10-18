#include "main.h"
/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 * @argv: argument variable
 * @err_n: error counter
 * Return: A integer
 */
int _atoi(const char **s, char *argv, int *err_n)
{
	int index = 0, no = 0, min = 1, mx = 0;

	while (s[index])
	{
		if (s[1][index] == '-' || !(s[1][index] >= '0' && s[1][index] <= '9'))
		{
			(*err_n)++;
			Error_msg(argv, ": ", int_str(*err_n)),
			Error_msg(": ", (char *)s[0], ": Illegal number: "),
			Error_msg((char *)s[1], "\n", NULL);
			return (*err_n);
		}
		if (s[1][index] == 45)
		{
			min *= -1;
		}

		while (s[1][index] >= 48 && s[1][index] <= 57)
		{
			mx = 1;
			no = (no * 10) + (s[1][index] - '0');
			index++;
		}

		if (mx == 1)
		{
			break;
		}

		index++;
	}

	no *= min;
	return (no);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination value
  * @src: Source value
  *
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
* _strncmp - compares s1 and s2 with a given length
* @s1: lhs
* @s2 : rhs
* @n : length to compare
* Return: returns dif btn strings
*/
int _strncmp(const char *s1, int n, const char *s2)
{
	int i = 0, dif = 0, smallest_len;

	smallest_len = _strlen(s1) < _strlen(s2) ? _strlen(s1) : _strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (n > smallest_len)
		return (-1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			dif++;
		i++;
	}
	return (dif);
}

/**
  * int_str - convert int to string
  * @num: integer
  *
  * Return: the pointer to converted string
  */
char *int_str(int num)
{
	int size = 0, dup = num, size_d;
	char *str;

	if (num == 0)
		return ("0");
	while (num > 0)
	{
		size++;
		num = num / 10;
	}
	size_d = size;
	str = malloc(size * sizeof(char));
	while (dup > 0)
	{
		str[size - 1] = (dup % 10) + '0';
		size--;
		dup = dup / 10;
	}
	str[size_d] = '\0';
	return (str);
}

/**
 * _puts - prints a string to stdout
 * @str: the string to print
 */
int _puts(char *str)
{
	int total_out = 0;

	while (*str != '\0')
	{
		putchar(*str);
		str++, total_out++;
	}
	return (total_out);
}
