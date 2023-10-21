#include "main.h"

/**
 * test_dir - copies array of string
 * @info: source
 * Return: 0 on success. otherwise -1
 */
int test_dir(info info[])
{
	if (info->arr == NULL)
		return (-1);
	return (access(info->arr[0], F_OK));
}

/**
 * arg_ind_zero - modify  index 0 of arr of str and pass as valid bash command
 * @info: input command
 * @env : environment variable
 * Return: modified string
 */
void arg_ind_zero(info info[], char **env)
{
	int i = 0, is_path = 0;

	if (info->arr == NULL)
		return;
	while (info->arr[0][i] != '\0')
	{
		if (info->arr[0][i] == '/')
			is_path = 1;
		i++;
	}
	if (!(is_path))
		get_path(info, env);
}

/**
 * get_path - gets the path of a given test if exist
 * @info: command input
 * @env : environment variable
 * Return: path to the file if found.
 */
void get_path(info info[], char **env)
{
	char **func_path = NULL;
	char *path = NULL, *var_path;
	unsigned int i = 0, len_arr;
	DIR *dir;
	struct dirent *entry;

	if (info->arr[0] == NULL && env == NULL)
		return;

	var_path = _getenv(info, "PATH").buf;
	if (var_path == NULL || (_strlen(var_path) == 0))
		return;

	token(&func_path, var_path, ':');

	while (func_path[i] != NULL)
	{
		dir = opendir(func_path[i]);
		if (dir == NULL)
		{
			free_str_arr(func_path);
			closedir(dir);
			return;
		}
		while ((entry = readdir(dir)) != NULL)
		{
			if (_strcmp(info->arr[0], entry->d_name) == 0)
			{
				len_arr = _strlen(func_path[i]) + _strlen(info->arr[0]);
				path = malloc(sizeof(char) * (len_arr + 2));
				if (path == NULL)
				{
					free(path);
					return;
				}
				_strcpy(path, func_path[i]), _strcat(path, "/"),
				_strcat(path, (char *)info->arr[0]);
				free(info->arr[0]);
				info->arr[0] = malloc(sizeof(char) * (len_arr + 2));
				if (info->arr != NULL)
					_strcpy(info->arr[0], path);
				free(var_path), free(path), free_str_arr(func_path);
				closedir(dir);
				return;
			}
		}
		closedir(dir);
		i++;
	}
	free(var_path), free_str_arr(func_path);
}

