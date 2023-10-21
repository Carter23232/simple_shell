#include "main.h"

/**
 * set_env - set environment variable
 * @info: input command from getline
 * Return: 1 if changed o/w 0
 */


int set_env(info info[])
{
	int ac = 0, i = 0, j = 0;
	d_ret g_var;
	char **new_env = NULL;

	if (info->arr == NULL)
		return (0);

	while (info->arr[i] != NULL)
		ac++, i++;

	if (ac != 3)
	{
		_E_puts("Usage: setenv VARIABLE VALUE\n", NULL, NULL);
		return (0);
	}

	g_var = _getenv(info->env_dup, info->arr[1]);

	if (g_var.buf != NULL)
	{
		free(g_var.buf);
		(info->env_dup)[g_var.val] = malloc(sizeof(char) * (_strlen(info->arr[1]) + _strlen(info->arr[2]) + 2));
		if ((info->env_dup)[g_var.val] != NULL)
		{
			_strcpy((info->env_dup)[g_var.val], info->arr[1]);
			_strcat((info->env_dup)[g_var.val], "=");
			_strcat((info->env_dup)[g_var.val], info->arr[2]);
		}
		info->env_edited = 1;
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
		new_env[j] = malloc(sizeof(char) * (_strlen(info->arr[1]) + _strlen(info->arr[2]) + 2));

		if (new_env[j] != NULL)
		{
			_strcpy(new_env[j], info->arr[1]);
			_strcat(new_env[j], "=");
			_strcat(new_env[j], info->arr[2]);
			j++;
		}
		new_env[j] = NULL;
		info->env_dup = new_env;
		info->env_edited = 1;
	}
	return (1);
}

/**
 * unset_env - unset environment variable
 * @info: input command from getline
 * Return: 1 if changed o/w 0
 */

int unset_env(info *info)
{
	int ac = 0, i = 0;
	d_ret g_var;

	if (info->arr == NULL)
		return (0);
	while (info->arr[i] != NULL)
		ac++, i++;
	if (ac != 2)
	{
		_E_puts("Usage: unsetenv VARIABLE\n", NULL, NULL);
		return (0);
	}
	g_var = _getenv(info->env_dup, info->arr[1]);
	if (g_var.buf != NULL)
	{
		free((info->env_dup)[g_var.val]);
		(info->env_dup)[g_var.val] = malloc(sizeof(char) * (_strlen(info->arr[1]) + 2));
		if ((info->env_dup)[g_var.val] != NULL)
		{
			_strcpy((info->env_dup)[g_var.val], info->arr[1]);
			_strcat((info->env_dup)[g_var.val], "=");
		}
		info->env_edited = 1;
	}
	free(g_var.buf);
	return (1);
}

/**
 * change_d - changes directory
 * @info: input command from getline
 * Return: 1 if changed o/w 0
 */

int change_d(info info[])
{
	char *buff, *env;
	size_t buf_size = 1024;
	int d_changed = -1;

	if (info->arr == NULL || info->arr[0] == NULL)
	{
		_E_puts("Usage: cd [DIRECTORY]\n", NULL, NULL);
		return (0);
	}

	if (info->arr[1] == NULL)
	{
		info->prv_dir = _getenv(info->env_dup, "PWD").buf;
		d_changed = chdir(env = _getenv(info->env_dup, "HOME").buf);
		free(env);
	}

	else if (_strcmp(info->arr[1], "-") == 0)
	{
		d_changed = chdir(info->prv_dir);
		_puts(info->prv_dir, "\n", NULL);
	}

	else
	{
		d_changed = chdir(info->arr[1]);
		info->prv_dir = _getenv(info->env_dup, "PWD").buf;
	}

	if (d_changed != 0)
	{
		_E_puts((char *)info->arr[1], ": do not exist.\n", NULL);
		return (0);
	}
	else
	{
		buff = malloc(sizeof(char) * buf_size);
		if (buff != NULL)
		{
			set_env_str(info, "PWD", getcwd(buff, buf_size));
			free(buff);
		}
	}
	return (1);
}

/**
 * _getenv - get environment variable
 * @str: variable to search
 * @env: environment variable
 * Return: value of variable
 */

d_ret _getenv(char *env[], char *str)
{
	d_ret env_ret;
	int len_val = 0, i = 0, j, e = 0, size, found = 0;

	env_ret.buf = NULL;

	if (env == NULL)
		return (env_ret);
	size = _strlen(str);
	while (env[i] != NULL)
	{
		if (_strncmp(str, size, env[i]) == 0)
		{
			j = size + 1;
			while (env[i][j] != '\0')
				len_val++, j++;
			found = 1;
			break;
		}
		i++;
	}
	if (found)
	{
		j = size + 1;
		env_ret.buf = malloc((len_val + 1) * sizeof(char));
		if (env_ret.buf == NULL)
			return (env_ret);
		while (env[i][j] != '\0' && e < len_val)
		{
			env_ret.buf[e] = env[i][j];
			j++, e++;
		}
		env_ret.buf[len_val] = '\0';
	}

	env_ret.val = i;
	return (env_ret);
}

/**
 * copy_env_var - makes a copy of environmental variable
 * @info: input cmd
 * @env: reference to environmental variables
 */

void copy_env_var(info *info, char **env)
{
	int num_element = 0, i = 0;

	if (env == NULL)
		return;
	while (env[num_element] != NULL)
		num_element++;

	info->env_dup = malloc(sizeof(char *) * (num_element + 1));

	if (info->env_dup != NULL)
	{
		while (env[i] != NULL)
		{
			info->env_dup[i] = malloc(sizeof(char) * _strlen(env[i]) + 1);
			if (info->env_dup[i] != NULL)
				_strcpy(info->env_dup[i], env[i]);
			i++;
		}
		info->env_full = 1;
	}
	info->env_dup[i] = NULL;
}
