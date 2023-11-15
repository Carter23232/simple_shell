#include "main.h"

/**
 * test_dir - copies array of string
 * @arg: source
 * Return: 0 on success. otherwise -1
 */
int test_dir(const char *arg)
{
	if (arg == NULL)
		return (-1);
	return (access(arg, F_OK));
}

/**
 * arg_ind_zero - modify  index 0 of arr of str and pass as valid bash command
 * @input: string to modify
 * @env : environment variable
 * Return: modified string
 */
void arg_ind_zero(char **input, char **env)
{
	int i = 0, is_path = 0;

	if (input == NULL)
		return;
	while ((*input)[i] != '\0')
	{
		if ((*input)[i] == '/')
			is_path = 1;
		i++;
	}
	if (!(is_path))
		*input = get_path(*input, env);
}

/**
 * get_path - gets the path of a given test if exist
 * @input: string to lookup
 * @env : environment variable
 * Return: path to the file if found.
 */
char *get_path(char *input, char **env)
{
	char **func_path = NULL;
	char *path = NULL, *var_path;
	unsigned int i = 0, len_arr;
	DIR *dir;
	struct dirent *entry;

	if (input == NULL && env == NULL)
		return ((char *)input);

	var_path = _getenv(env, "PATH").buf;
	if (var_path == NULL || (_strlen(var_path) == 0))
		return ((char *)input);

	token(&func_path, var_path, ':');

	while (func_path[i] != NULL)
	{
		dir = opendir(func_path[i]);
		if (dir == NULL)
		{
			free_str_arr(func_path);
			closedir(dir);
			return (NULL);
		}
		while ((entry = readdir(dir)) != NULL)
		{
			if (_strcmp(input, entry->d_name) == 0)
			{
				len_arr = (_strlen(func_path[i]));
				path = malloc(sizeof(char) * (len_arr + 2 + _strlen(input)));
				if (path == NULL)
				{
					free(path);
					return ((char *)input);
				}
				_strcpy(path, func_path[i]), _strcat(path, "/"),
				_strcat(path, (char *)input);
				free(var_path), free(input), free_str_arr(func_path);
				closedir(dir);
				return (path);
			}
		}
		closedir(dir);
		i++;
	}
	free(path), free(var_path), free_str_arr(func_path);
	return ((char *)input);
}
