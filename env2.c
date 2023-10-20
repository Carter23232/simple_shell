#include "main.h"

/**
 * _env - get environment variable
 * @env_var: input string from getline
 * Return: number of varible read
 */

int _env(char **env_var)
{
	int i = 0, total_output = 0;

	if (env_var == NULL)
		return (0);
	while (env_var[i] != NULL)
	{
		total_output += _puts(env_var[i], "\n", NULL);
		i++;
	}
	return (total_output);
}
