#include "main.h"
/**
 * _atoi - Convert a string to an integer.
 * @info: input command
 * @argv: argument variable
 * Return: A integer
 */
int _atoi(info *info, char argv[])
{
	int index = 0, no = 0, min = 1, mx = 0;

	while (info->arr[index])
	{
		if  (info->arr[1][index] == '-')
		{
			(info->num_E)++;
			_E_puts(argv, ": ", int_str(info->num_E));
			_E_puts(": ", (char *)info->arr[0], ": Illegal number: ");
			_E_puts((char *)info->arr[1], "\n", NULL);
			return (2);
		}
		if (!(info->arr[1][index] >= '0' && info->arr[1][index] <= '9'))
		{
			(info->num_E)++;
			_E_puts(argv, ": ", int_str(info->num_E));
			_E_puts(": ", (char *)info->arr[0], ": numeric argument required: ");
			_E_puts((char *)info->arr[1], "\n", NULL);
			return (2);
		}
		if (info->arr[1][index] == 45)
		{
			min *= -1;
		}

		while (info->arr[1][index] >= 48 && info->arr[1][index] <= 57)
		{
			mx = 1;
			no = (no * 10) + (info->arr[1][index] - '0');
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
  * _puts - a simplified custom _put
  * @msg1: msg1
  * @msg2: msg2
  * @msg3: msg3
  * Return: number of output strings
  */
int _puts(char *msg1, char *msg2, char *msg3)
{
	int i = 0, j = 0, k = 0, total_output = 0;

	if (msg1 == NULL)
		return (0);

	while (msg1[i] != '\0')
	{
		write(STDOUT_FILENO, &msg1[i], 1);
		i++, total_output++;
	}
	if (msg2 == NULL)
		return (0);

	while (msg2[j] != '\0')
	{
		write(STDOUT_FILENO, &msg2[j], 1);
		j++, total_output++;
	}
	if (msg3 == NULL)
		return (0);

	while (msg3[k] != '\0')
	{
		write(STDOUT_FILENO, &msg3[k], 1);
		k++, total_output++;
	}

	return (total_output);
}
