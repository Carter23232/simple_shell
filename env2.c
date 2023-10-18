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
		total_output += myprintf("%s\n", env_var[i]);
		i++;
	}
	return (total_output);
}
