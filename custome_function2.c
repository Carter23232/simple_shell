#include "main.h"
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
* @toggle: switch that determines if set or not
*/
void ext(int status, int *toggle)
{
	*toggle = 1;
	_exit(status);
}
