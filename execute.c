#include "main.h"

int  built_in (int *status, char **arr ,char *buf, char *env[])
{
	char *previous_dir = NULL;

	if (_strcmp((arr)[0], "exit") == 0)
	{
		if ((arr)[1] != NULL)
			*status = _atoi((arr)[1]);
		free_ifnf("as", arr ,buf);
		ext(*status);
	}
	else if (_strcmp((arr)[0], "setenv") == 0)
	{
		previous_dir = _getenv(env, "PWD");
		set_env((const char **)arr);
		return (1);
	}
	else if (_strcmp((arr)[0], "unsetenv") == 0)
	{
		unset_env((const char **)arr);
		return (1);
	}

	else if (_strcmp((arr)[0], "cd") == 0)
	{
		previous_dir = _getenv(env, "PWD");
		change_d((const char **)(arr), &previous_dir, env);
		free(previous_dir);
		return (1);
	}

	return (0);
}


/**
 * execute - executes the program
 * @env : environment variable
 * @ac : argument counter
 * @argv : argument variable
 */
void execute(int ac, char **argv, char **env)
{
	d_ret ret;
	char *buf = NULL, *err = NULL;
	char **arr = NULL;
	pid_t child;
	int status = 0;

	(void)ac;
	while ((ret = get_command(env)).val != -1)
	{
		if (!trailing_space(ret))
		{
			buf = removeSpacesFromStr(ret.buf);
			token(&arr, buf, ' ');
			child = -1;
			if (built_in(&status, arr, buf, env));
			else
			{
				arg_ind_zero(&arr[0], env);
				if (test_dir(arr[0]) == 0)
					child = fork();
				else
				{
					Error_msg(err = _strcat(argv[0], ": No such file or directory.\n"));
					free_ifnf("s", err);
				}
				if (child == 0)
				{
					if (execve(arr[0], arr, env))
						Error_msg(buf),	Error_msg(" failed to run command .\n");
				}
				else
					wait(&status);
			}
		}
		free_ifnf("as", arr, buf);
	}
}
