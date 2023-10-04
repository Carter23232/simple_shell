#include "main.h"
/**
 * set_env - set environment variable
 * @arr: input string from getline
 * @toggle: switch that determines if set or not
 * @child: reference to the child PID.
 */
void set_env(const char **arr, int *toggle, pid_t *child)
{
	if (arr == NULL)
	{
		printf("Usage: setenv VARIABLE VALUE\n");
		return;
	}
	if ((setenv(arr[1], arr[2], 1)) != 0)
		Error_msg("failed to set environment variable\n");
	else
	{
		*toggle = 1;
		*child = 0;
	}

}
/**
 * unset_env - unset environment variable
 * @arr: input string from getline
 * @toggle: switch that determines if set or not
 * @child: reference to the child PID.
 */
void unset_env(const char **arr, int *toggle, pid_t *child)
{
	if (arr == NULL || arr[0] == NULL || arr[1] == NULL)
	{
		Error_msg("Usage: unsetenv VARIABLE\n");
		return;
	}
	if ((unsetenv(arr[1])) != 0)
		Error_msg("failed to unset environment variable\n");
	else
	{
		*toggle = 1;
		*child = 0;
	}
}

/**
 * change_d - changes directory
 * @arr: input string from getline
 * @tog: switch that determines if set or not
 * @pr_dr: stores the previous directory
 * @ev: environment variable
 * @chd: reference to the child PID.
 */
void change_d(const char **arr, int *tog, char **pr_dr, pid_t *chd, char *ev[])
{
	char *buff;
	size_t buf_size;
	int d_changed;

	if (arr == NULL || arr[0] == NULL)
	{
		Error_msg("Usage: cd [DIRECTORY]\n");
		return;
	}

	if (arr[1] == NULL)
	{
		*pr_dr = _getenv(ev, "PWD");
		d_changed = chdir(_getenv(ev, "HOME"));
	}

	else if (_strcmp(arr[1], "-") == 0)
		d_changed = chdir(*pr_dr);
	else
	{
		*pr_dr = _getenv(ev, "PWD");
		d_changed = chdir(arr[1]);
	}

	if (d_changed != 0)
		Error_msg(arr[1]), Error_msg(": do not exist.\n");
	else
	{
		*tog = 1;
		*chd = 0;
		buf_size = pathconf(".", _PC_PATH_MAX);
		buff = malloc(sizeof(char) * buf_size);
		if (buff != NULL)
		{
			setenv("PWD", getcwd(buff, buf_size), 1);
			free(buff);
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
	int len_val = 0, i = 0, j, e = 0;

	if (env == NULL)
		return (NULL);

	while (env[i] != NULL)
	{
		if (_strncmp(str, _strlen(str), env[i]) == 0)
		{
			j = _strlen(str) + 1;
			while (env[i][j] != '\0')
				len_val++, j++;
			break;
		}
		i++;
	}
	j = _strlen(str) + 1;
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


int envs_unset(char **env)
{
	int i = 0, n = 0;
	if (env == NULL)
		return (1);
	while (env[i] != NULL)
	{
		if (env[i] != NULL)
			n++;
		i++;
	}
	if (n > 1)
		return (0);
	return (-1);
}