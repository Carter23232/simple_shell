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
char *arg_ind_zero(char *input)
{
	char *generated_path;
	int i = 0, is_path = 0;

	if (input == NULL)
		return (NULL);
	while (input[i] != '\0')
	{
		if ((input[i]) == '/')
			is_path = 1;
		i++;
	}
	if (!(is_path))
	{
		generated_path = get_path(input);
		return (generated_path);
	}
	return (input);
}

/**
 * get_path - gets the path of a given test if exist
 * @input: string to lookup
 * Return: path to the file if found
 */
char *get_path(const char *input)
{
	char *func_path[] = {"/usr/local/sbin/",
			     "/usr/local/bin/", "/usr/sbin/", "/usr/bin/",
			     "/sbin/", "/bin/", NULL};
	char *path = NULL;
	unsigned int i = 0, len_arr;
	DIR *dir;
	struct dirent *entry;

	if (input == NULL)
		return (NULL);

	while (func_path[i] != NULL)
	{
		dir = opendir(func_path[i]);
		if (dir == NULL)
			Error_msg("directory open failed\n");
		while ((entry = readdir(dir)) != NULL)
		{
			if (_strcmp(input, entry->d_name) == 0)
			{
				len_arr = (_strlen(input) + _strlen(func_path[i]));
				path = malloc(sizeof(char) * (len_arr + 1));
				if (path == NULL)
				{
					free(path);
					return (NULL);
				}
				_strcpy(path, func_path[i]), _strcat(path, input);
				path[len_arr] = '\0';
				closedir(dir);
				return (path);
			}
		}
		closedir(dir);
		i++;
	}
	free(path);
	return (NULL);
}
