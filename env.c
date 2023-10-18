#include "main.h"
/**
 * set_env - set environment variable
 * @arr: input string from getline
 * @env: pointer to env variable
 *Return: return 1 if succesful or 0 o/w
 */

int set_env(char ***env, char **arr)
{
	int ac = 0, i = 0, j = 0;
	d_ret g_var;
	char **new_env = NULL;

	if (arr == NULL)
		return (0);

	while (arr[i] != NULL)
		ac++, i++;

	if (ac != 3)
	{
		Error_msg(1, "Usage: setenv VARIABLE VALUE\n");
		return (0);
	}

	g_var = _getenv(*env, arr[1]);

	if (g_var.buf != NULL)
	{
		free(g_var.buf);
		(*env)[g_var.val] = malloc(sizeof(char) * (_strlen(arr[1]) + _strlen(arr[2]) + 2));
		if ((*env)[g_var.val] != NULL)
		{
			_strcpy((*env)[g_var.val], arr[1]);
			(*env)[g_var.val] = _strcat((*env)[g_var.val], "=");
			(*env)[g_var.val] = _strcat((*env)[g_var.val], arr[2]);
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
		new_env[j] = malloc(sizeof(char) * (_strlen(arr[1]) + _strlen(arr[2]) + 2));
		if (new_env[j] != NULL)
		{
			_strcpy(new_env[j], arr[1]);
			new_env[j] = _strcat(new_env[j], "=");
			new_env[j] = _strcat(new_env[j], arr[2]);
			j++;
		}
		new_env[j] = NULL;
		*env = new_env;
	}
	return (1);
}

/**
 * unset_env - unset environment variable
 * @arr: input string from getline
 * @env: pointer to env variable
 */
void unset_env(char ***env, char **arr)
{
	int ac = 0, i = 0;
	d_ret g_var;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
		ac++, i++;
	if (ac != 2)
	{
		Error_msg(1, "Usage: unsetenv VARIABLE\n");
		return;
	}
	g_var = _getenv(*env, arr[1]);
	if (g_var.buf != NULL)
	{
		free(g_var.buf);
		(*env)[g_var.val] = malloc(sizeof(char) * (_strlen(arr[1]) + 2));
		if ((*env)[g_var.val] != NULL)
		{
			_strcpy((*env)[g_var.val], arr[1]), (*env)[g_var.val] = _strcat((*env)[g_var.val], "=");
		}
	}
free(g_var.buf);
}

/**
 * change_d - changes directory
 * @arr: input string from getline
 * @pr_dr: stores the previous directory
 * @ev: environment variable
 */
void change_d(const char **arr, char **pr_dr, char *ev[])
{
	char *buff, *env;
	size_t buf_size;
	int d_changed;

	if (arr == NULL || arr[0] == NULL)
	{
		Error_msg(1, "Usage: cd [DIRECTORY]\n");
		return;
	}

	if (arr[1] == NULL)
	{
		*pr_dr = _getenv(ev, "PWD").buf;
		d_changed = chdir(env = _getenv(ev, "HOME").buf);
		free_ifnf("s", env);
	}

	else if (_strcmp(arr[1], "-") == 0)
		d_changed = chdir(*pr_dr);
	else
	{
		*pr_dr = _getenv(ev, "PWD").buf;
		d_changed = chdir(arr[1]);
	}

	if (d_changed != 0)
		Error_msg(2, arr[1], ": do not exist.\n");
	else
	{
		buf_size = pathconf(".", _PC_PATH_MAX);
		buff = malloc(sizeof(char) * buf_size);
		if (buff != NULL)
		{
			setenv("PWD", getcwd(buff, buf_size), 1);
			free_ifnf("s", buff);
		}
	}
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
 * @env: reference to environmental variables
 * Return: a duplicate of env variables or NULL if does not exist
 */
char **copy_env_var(char **env)
{
	char **env_dup;
	int num_element = 0, i = 0;

	if (env == NULL)
		return (NULL);
	while (env[num_element] != NULL)
		num_element++;

	env_dup = malloc(sizeof(char *) * (num_element + 1));
	if (env_dup == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		env_dup[i] = malloc(sizeof(char) * _strlen(env[i])  + 1);
		if (env_dup[i] != NULL)
			_strcpy(env_dup[i], env[i]);
		i++;


	}
	env_dup[i] = NULL;
	return (env_dup);
}
