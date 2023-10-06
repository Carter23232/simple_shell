#include "printf.h"

/**
 * check_number - Print the digits of an integer and handle special cases
 * @n: The integer needs to be checked and printed
 *
 * Return: Nothing
 */

void check_number(int n)
{
	int i;
	int digits[12];
	int num_len = 0;

	if (n == INT_MIN)
	{
		print_char('-');
		print_char('2');
		n = 147483648;
	}
	else if (n < 0)
	{
		print_char('-');
		n = -n;
	}
	if (n == 0)
	{
		digits[num_len++] = 0;
	}
	else
	{
		while (n > 0)
		{
			digits[num_len++] = n % 10;
			n /= 10;
		}
	}
	for (i = num_len - 1; i >= 0; i--)
	{
		print_char(digits[i] + '0');
	}
}
