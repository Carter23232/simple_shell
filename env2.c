#include "main.h"

/**
 * _env - get environment variable
 * @info: component of command input
 * Return: number of varible read
 */

int _env(info info[])
{
	int i = 0, total_output = 0;

	if (info->env_dup == NULL)
		return (0);
	while (info->env_dup[i] != NULL)
	{
		total_output += _puts(info->env_dup[i], "\n", NULL);
		i++;
	}
	return (i);
}

/**
 * set_env_str - sets env var with given string
 * @info: component of command input
 * @var: var
 * @value: key
 * Return: 1 if set o/w 0
 */
int set_env_str(info *info, char *var, char *value)
{
	int j = 0;
	d_ret g_var;
	char **new_env = NULL;

	if (var == NULL)
		return (0);

	g_var = _getenv(info, var);
	if (g_var.buf != NULL)
	{
		free(g_var.buf);
		(info->env_dup)[g_var.val] = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 2));
		if ((info->env_dup)[g_var.val] != NULL)
		{
			_strcpy((info->env_dup)[g_var.val], var);
			_strcat((info->env_dup)[g_var.val], "=");
			_strcat((info->env_dup)[g_var.val], value);
		}
	}
	else
	{
		new_env = malloc(sizeof(char *) * (g_var.val + 2));
		if (new_env != NULL)
		{
			while ((info->env_dup)[j] != NULL)
			{
				new_env[j] = malloc(sizeof(char) * (_strlen((info->env_dup)[j]) + 1));
				if (new_env[j] != NULL)
					_strcpy(new_env[j], (info->env_dup)[j]);
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
		info->env_dup = new_env;
	}
	return (1);
}

/**
 * pwd - print current working directory
 * @info: input cmd
 * Return: 1 if successful o/w 0
 */
int pwd(info info[])
{
	char *var = _getenv(info, "PWD").buf;
	if (var != NULL)
	{
		_puts(var, "\n", NULL);
		free(var);
		return (1);
	}
	return (0);
}
