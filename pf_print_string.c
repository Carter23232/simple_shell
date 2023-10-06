#include "printf.h"

/**
 * print_string - Prints a string
 * @some_text: the  string pointer
 *
 * Return: the size of the string
 */

int print_string(char *some_text)
{
	int strlen = 0;

	if (some_text == NULL)
	{
		strlen += write(1, "(null)", 6);
		return (strlen);

	}

	while (*(some_text + strlen))
	{
		write(1, some_text + strlen, 1);
		strlen++;
	}

	return (strlen);
}
