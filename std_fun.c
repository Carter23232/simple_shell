#include "main.h"

/**
 * _strcmp - compares s1 and s2
 * @s1: lhs
 * @s2 : rhs
 * Return: returns copied string
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, dif = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (_strlen(s1) != _strlen(s2))
		return (_strlen(s1) - _strlen(s2));
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			dif++;
		i++;
	}
	return (dif);
}
/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * convt_str_to_arr - converts strings to array
 * @str1: string 1
 * @str2: string 2
 * @str3: string 3
 * Return: array of strings
 */
char **convt_str_to_arr(char *str1, char *str2, char *str3)
{
	char **arr;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	arr = malloc(sizeof(char *) * 4);
	if (arr != NULL)
	{
		arr[0] = malloc(sizeof(char) * (_strlen(str1) + 1));
		if (arr[0] != NULL)
			_strcpy(arr[0], str1);

		arr[1] = malloc(sizeof(char) * (_strlen(str2) + 1));
		if (arr[1] != NULL)
			_strcpy(arr[1], str2);

		arr[2] = malloc(sizeof(char) * (_strlen(str3) + 1));
		if (arr[2] != NULL)
			_strcpy(arr[2], str3);
	}
	arr[3] = NULL;
	return (arr);
}

/**
 * free_info - free info variables
 * @com_info: the string to calculate the length of
 */
void free_info(info com_info[])
{
	if (com_info->arr != NULL)
		free_str_arr(com_info->arr);

	if (com_info->buf != NULL)
	{
		free(com_info->buf);
		com_info->buf = NULL;
	}

	if (com_info->no != NULL)
	{
		free(com_info->no);
		com_info->no = NULL;
	}

	if (com_info->prv_dir != NULL)
	{
		free(com_info->prv_dir);
		com_info->prv_dir = NULL;
	}
	com_info->input.buf = NULL;
}


