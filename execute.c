#include "main.h"

/**
 * execute - executes the program
 * @env : environment variable
 * @ac : argument counter
 * @argv : argument variable
 */
void execute(int ac, char **argv, char **env)
{
	d_ret ret;
	char *buf = NULL, *arg_zero = NULL, *previous_dir = _getenv(env, "PWD"), *dig;
	char **arr = NULL;
	pid_t child = -1;
	int status = 0, exec, exit_ = 0, setenv_ = 0, unsetenv_ = 0, cd_ = 0;

	while ((ret = get_command(env)).val != -1)
	{
		if (!trailing_space(ret))
		{
			buf = removeSpacesFromStr(ret.buf), arr = token(buf),
			arg_zero = arg_ind_zero(arr[0]), exit_ = 0, setenv_ = 0,
			unsetenv_ = 0, cd_ = 0, child = -1;
			if (_strcmp(arr[0], "exit") == 0)
			{
				if (arr[1] != NULL)
					status = _atoi(arr[1]);
				free(previous_dir), free(ret.buf), free_str_arr(arr);
				ext(status, &exit_);
			}
			if (_strcmp(arr[0], "setenv") == 0)
				set_env((const char **)arr, &setenv_, &child);
			if (_strcmp(arr[0], "unsetenv") == 0)
				unset_env((const char **)arr, &unsetenv_, &child);
			if (_strcmp(arr[0], "cd") == 0)
				change_d((const char **)arr, &cd_, &previous_dir, &child, env);
			else
			{
				if (test_dir(arg_zero) == 0)
					child = fork();
				else if
				((exit_ ^ setenv_ ^ unsetenv_) == 1);
				else
				{
					Error_msg(_strcat(argv[0], ": "));
					Error_msg(_strcat(dig = int_str(ac), ": "));
					Error_msg(_strcat(buf, ": not found\n"));
					free(dig);
					ext(127, &exit_);

				}

				if (child < 0 && (exit_ ^ setenv_ ^ unsetenv_) != 1)
					;
				else if (child == 0)
				{
					exec = execve(arg_zero, arr, env);
					if (exec == -1 && ((~(exit_ ^ setenv_ ^ unsetenv_)) == 1))
						Error_msg(buf),	Error_msg(" failed to run.\n");
				}
				else
					wait(&status);
			}
			free(buf), free(arg_zero);
		}
	}
	free(previous_dir);
}
