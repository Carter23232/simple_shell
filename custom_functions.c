#include "main.h"
/**
  * _E_puts - a simplified custom Error writer
  * @msg1: msg1
  * @msg2: msg2
  * @msg3: msg3
  * Return: number of output strings
  */
void _E_puts(char *msg1, char *msg2, char *msg3)
{
	int i = 0, j = 0, k = 0;

	if (msg1 == NULL)
		return;

	while (msg1[i] != '\0')
	{
		write(STDERR_FILENO, &msg1[i], 1);
		i++;
	}
	if (msg2 == NULL)
		return;

	while (msg2[j] != '\0')
	{
		write(STDERR_FILENO, &msg2[j], 1);
		j++;
	}
	if (msg3 == NULL)
		return;

	while (msg3[k] != '\0')
	{
		write(STDERR_FILENO, &msg3[k], 1);
		k++;
	}
}

/**
 * free_str_arr - free memory of array of strings
 * @arr: the array
 *
 */

void free_str_arr(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/**
 * trailing_space - handle empty parameters
 * @out: input stream
 * Return: 1 if succeed and 0 otherwise
 */

int trailing_space(d_ret out)
{
	size_t i = 0;
	int is_space  = 0;

	while (out.buf[i] != '\0')
	{
		if (out.buf[i] == ' ')
		{
			is_space++;
		}
		i++;
	}
	if (is_space == _strlen(out.buf))
		return (1);
	return (0);
}

/**
* ext - terminates all processes and exit shell
* @status: exit status.
*/

void ext(int status)
{
	_exit(status);
}
