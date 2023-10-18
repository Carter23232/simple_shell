#include "main.h"
/**
 * Error_msg - sprints error messages to stderr
 * @i : argument counter
 */
void Error_msg(char *msg, char *msg2, char *msg3)
{
	if (msg == NULL)
		return;
	write(STDERR_FILENO, msg, _strlen(msg));

	if (msg2 == NULL)
		return;
	write(STDERR_FILENO, msg2, _strlen(msg2));

	if (msg3 == NULL)
		return;
	write(STDERR_FILENO, msg3, _strlen(msg3));

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
	if (is_space == (out.val - 1))
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
