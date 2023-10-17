#include "main.h"

int _env (char **env_var)
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