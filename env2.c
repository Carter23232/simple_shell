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

int set_env_str(char ***env, char *var, char *value)
{
	int j = 0;
	d_ret g_var;
	char **new_env = NULL;

	if (var == NULL)
		return (0);

	g_var = _getenv(*env, var);
	if (g_var.buf != NULL)
	{
		free(g_var.buf);
		(*env)[g_var.val] = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 2));
		if ((*env)[g_var.val] != NULL)
		{
			_strcpy((*env)[g_var.val], var);
			_strcat((*env)[g_var.val], "=");
			_strcat((*env)[g_var.val], value);
		}
	}
	else
	{
		new_env = malloc(sizeof(char *) * (g_var.val + 2));
		if (new_env != NULL)
		{
			while ((*env)[j] != NULL)
			{
				new_env[j] = malloc(sizeof(char) * (_strlen((*env)[j]) + 1));
				if (new_env[j] != NULL)
					_strcpy(new_env[j], (*env)[j]);
				else
					free_str_arr(new_env);
				j++;
			}
		}
		new_env[j] = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 2));

		if (new_env[j] != NULL)
		{
			_strcpy(new_env[j], var);
			_strcat(new_env[j], "=");
			_strcat(new_env[j], value);
			j++;
		}
		new_env[j] = NULL;
		*env = new_env;
	}
	return (1);
}