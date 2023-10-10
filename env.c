#include "main.h"
/**
 * set_env - set environment variable
 * @arr: input string from getline
 */
void set_env(const char **arr)
{
	int ac = 0, i = 0;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
		ac++, i++;
	if (ac != 3)
	{
		Error_msg(1, "Usage: setenv VARIABLE VALUE\n");
		return;
	}
	else if ((setenv((const char *)arr[1], (const char *)arr[2], 1)) != 0)
		Error_msg(1, "failed to set environment variable\n");

}
/**
 * unset_env - unset environment variable
 * @arr: input string from getline
 */
void unset_env(const char **arr)
{
	int ac = 0, i = 0;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
		ac++, i++;
	if (ac != 2)
	{
		Error_msg(1, "Usage: unsetenv VARIABLE\n");
		return;
	}
	else if ((unsetenv((const char *)arr[1])) != 0)
		Error_msg(1, "failed to unset environment variable\n");

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
		*pr_dr = _getenv(ev, "PWD");
		d_changed = chdir(env = _getenv(ev, "HOME"));
		free_ifnf("s", env);
	}

	else if (_strcmp(arr[1], "-") == 0)
		d_changed = chdir(*pr_dr);
	else
	{
		*pr_dr = _getenv(ev, "PWD");
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
char *_getenv(char *env[], char *str)
{
	char *env_;
	int len_val = 0, i = 0, j, e = 0, size;

	if (env == NULL)
		return (NULL);
	size = _strlen(str);
	while (env[i] != NULL)
	{
		if (_strncmp(str, size, env[i]) == 0)
		{
			j = size + 1;
			while (env[i][j] != '\0')
				len_val++, j++;
			break;
		}
		i++;
	}
	j = size + 1;
	env_ = malloc((len_val + 1) * sizeof(char));
	if (env_ == NULL)
		return (NULL);
	while (env[i][j] != '\0' && e < len_val)
	{
		env_[e] = env[i][j];
		j++, e++;
	}
	env_[len_val] = '\0';
	return (env_);
}
