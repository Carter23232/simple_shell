#include "main.h"
/**
 * Error_msg - sprints error messages to stderr
 * @msg: error msg
 */
void Error_msg(const char *msg)
{
	write(STDERR_FILENO, msg, _strlen(msg));
}
/**
 * free_str_arr - free memory of array of strings
 * @arr: the array
 *
 */
void free_str_arr(char **arr)
{
	int i = 0;

	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
	}
	free(arr);
}

/**
 * copy_arr_str - copies array of string
 * @src: source
 * Return: array of strings
 */


