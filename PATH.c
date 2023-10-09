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
 * Return: path to the file if found
 */
char *get_path(const char *input, char **env)
{
	char **func_path = NULL;
	char *path = NULL, *addr_path, *var_path, *fw_slash;
	unsigned int i = 0, len_arr;
	DIR *dir;
	struct dirent *entry;

	if (input == NULL && func_path == NULL && env == NULL)
		return (NULL);
	token(&func_path, var_path = _getenv(env, "PATH"),':');

	while (func_path[i] != NULL)
	{
		dir = opendir(func_path[i]);
		if (dir == NULL)
			Error_msg("directory open failed\n");
		while ((entry = readdir(dir)) != NULL)
		{
			if (_strcmp(input, entry->d_name) == 0)
			{
				len_arr = (_strlen(func_path[i]));
				path = malloc(sizeof(char) * (len_arr + 1));
				if (path == NULL)
				{
					free_ifnf("s", path);
					return (NULL);
				}
				_strcpy(path, func_path[i]), addr_path = _strcat(fw_slash = _strcat(path, "/"), input);
				free_ifnf("sssa", path, var_path, fw_slash, func_path);
				closedir(dir);
				return (addr_path);
			}
		}
		closedir(dir);
		i++;
	}
	free_ifnf("ssa", path, var_path, func_path);
	return (NULL);
}
