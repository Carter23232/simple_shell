#include "main.h"
/**
 * built_in - handles built in functions
 * @status : update status value
 * @argv: argument variables
 * @pr_dir: previous dir
 * @buf : argument counter
 * @arr : tokenized array
 * @env : environment variable
 * @ext_er:exit toggle
 * @env_edt: env edit toggle
 * Return: 1 if command is builtin 0 o/w
 */

int  built_in(int *status, char **argv, char **pr_dir, char **arr, char *buf, char *env[], int *ext_er, int *env_edt)
{
	if (_strcmp((arr)[0], "exit") == 0)
	{
		if ((arr)[1] != NULL)
			*status = _atoi((const char **)arr, argv[0], ext_er);
		free_str_arr(arr), free(buf);
		ext(*status);
	}
	else if (_strcmp((arr)[0], "env") == 0)
	{
		_env(env);
		return (1);
	}
	else if (_strcmp((arr)[0], "setenv") == 0)
	{

		*env_edt = set_env(&env, arr);
		return (1);
	}
	else if (_strcmp((arr)[0], "unsetenv") == 0)
	{
		unset_env(&env, arr);
		return (1);
	}

	else if (_strcmp((arr)[0], "cd") == 0)
	{

		change_d((const char **)(arr), &(*pr_dir), env);
		return (1);
	}
	return (0);
}


/**
 * execute - executes the program
 * @env : environment variable
 * @ac : argument counter
 * @argv : argument variable
 * Return: exit status value
 */
int execute(int ac, char **argv, char **env)
{
	d_ret ret;
	char *buf = NULL, *prv_dir = getenv("PWD"), *no = NULL;
	char **arr = NULL, **env_dup = copy_env_var(env);
	pid_t child;
	int status = 0, num_E = 0, ext_err = 0, env_edited;

	(void)ac;
	while ((ret = get_command()).val != -1)
	{
		if (!trailing_space(ret))
		{
			buf = removeSpacesFromStr(ret.buf);
			token(&arr, buf, ' ');
			child = -1;
			if (built_in(&status, argv, &prv_dir, arr, buf, env_dup, &ext_err, &env_edited))
				;
			else
			{
				arg_ind_zero(&arr[0], env_dup);
				if (test_dir(arr[0]) == 0)
					child = fork();
				else
				{
					num_E++, status = 127;
					no = int_str(num_E);
					Error_msg(argv[0], ": ", no);
					Error_msg(": ", buf, ": not found\n");
				}
				if (child == 0)
				{
					if (execve(arr[0], arr, env_dup))
						Error_msg(buf, "failed to run command .\n", NULL);
				}
				else
					wait(&status);
				if (WIFEXITED(status))
					/* Set return status to child's exit status */
					status = WEXITSTATUS(status);
			}
			free_str_arr(arr), free(buf);
			if (!env_edited)
				free_str_arr(env_dup);
		}
		else
			free_str_arr(env_dup), free(ret.buf);
		env_dup = copy_env_var(env);
	}
	free(no);
	return (status);
}
