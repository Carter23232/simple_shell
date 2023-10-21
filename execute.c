#include "main.h"

/**
 * built_in - handles built in functions
 * @com_info : command infos
 * @argv : main input args
 * Return: 1 if built in or  o/w
 */
int  built_in(info *com_info, char **argv)
{
	if (_strcmp((com_info->arr)[0], "exit") == 0)
	{
		if ((com_info->arr)[1] != NULL)
			com_info->status = _atoi(com_info, argv[0]);
		free_str_arr(com_info->arr), free(com_info->buf), free(com_info->prv_dir);
		free_str_arr(com_info->env_dup);
		ext(com_info->status);
	}
	else if (_strcmp((com_info->arr)[0], "env") == 0)
	{
		_env(com_info);
		return (1);
	}
	else if (_strcmp((com_info->arr)[0], "setenv") == 0)
	{

		com_info->env_edited = set_env(com_info);
		return (1);
	}
	else if (_strcmp((com_info->arr)[0], "unsetenv") == 0)
	{
		unset_env(com_info);
		return (1);
	}

	else if (_strcmp((com_info->arr)[0], "cd") == 0)
	{

		change_d(com_info);
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
	info com_info[] = { INFO_INIT, };

	com_info->prv_dir = _getenv(env, "PWD").buf, copy_env_var(com_info, env);
	com_info->input.buf = NULL, com_info->input.val = 0;
	(void)ac;
	while (((com_info->input = get_command())).val != -1)
	{
		com_info->buf = removeSpacesFromStr(com_info->input.buf);
		if (_strlen(com_info->buf) > 0)
		{
			token(&(com_info->arr), com_info->buf, ' ');
			com_info->child = -1;
			if (!(built_in(com_info, argv)))
			{
				arg_ind_zero(&(com_info->arr)[0], com_info->env_dup);
				if (test_dir((com_info->arr)[0]) == 0)
					com_info->child = fork();
				else
				{
					com_info->num_E++, com_info->status = 127;
					_E_puts(argv[0], ": ", com_info->no = int_str(com_info->num_E));
					_E_puts(": ", com_info->buf, ": not found\n");
				}
				if (com_info->child == 0)
				{
					if (execve((com_info->arr)[0], com_info->arr, com_info->env_dup))
						_E_puts(com_info->buf, "failed to run command .\n", NULL);
				}
				else
					wait(&(com_info->status));
				if (WIFEXITED(com_info->status))
					/* Set return status to child's exit status */
					com_info->status = WEXITSTATUS(com_info->status);
			}
			free_str_arr(com_info->arr), free(com_info->buf), free(com_info->no);
			if (!com_info->env_edited)
				free_str_arr(com_info->env_dup);
		}
		else
			free_str_arr(com_info->env_dup), free(com_info->input.buf);
		if (!com_info->env_edited)
			copy_env_var(com_info, env);
	}
	free(com_info->prv_dir), free_str_arr(com_info->env_dup);
	return (com_info->status);
}
