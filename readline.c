#include "main.h"
/**
 * get_command - gets command from stdin
 * @env: evironment variable
 * Return: a string and a value as output
 */
d_ret get_command(void)
{
	d_ret stream;
	size_t buffer_len = 0;
	int interactive;

	stream.val = 0;
	stream.buf = NULL;
	interactive = isatty(STDIN_FILENO);
	if (interactive)
		myprintf("$ ");
	stream.val = (int)getline(&(stream.buf), &buffer_len, stdin);
	if (stream.val == -1)
		free_ifnf("s", stream.buf);
	if (stream.val == -1 && interactive == 1)
		exit(0);
	if (stream.val != -1)
		stream.buf[_strlen(stream.buf) - 1] = '\0';
	return (stream);
}
/**
 * removeSpacesFromStr - removes trailing spaces from string
 * @string: input string
 * Return: an edited string
 */
char *removeSpacesFromStr(char *string)
{
	size_t  len = _strlen(string), i, j;

	for (i = 0 ; i < len; i++)
	{
		if (string[0] == ' ')
		{
			for (i = 0; i < (len - 1); i++)
				string[i] = string[i + 1];
			string[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (string[i] == ' ' && string[i + 1] == ' ')
		{
			for (j = i; j < (len - 1); j++)
			{
				string[j] = string[j + 1];
			}
			string[j] = '\0';
			len--;
			i--;
		}
		else if (string[i] == ' ' && string[i + 1] == '\0')
			string[i] = '\0';
	}
	return (string);
}
/**
 * get_num_of_words - calculates the number of words in a string
 * @buffer: input string
 * @key: delimeter
 * Return: number of words
 */
int get_num_of_words(char *buffer, char key)
{
	int n_of_words = 1;

	if (buffer == NULL)
		return (0);
	while (*buffer != '\0')
	{
		if (*buffer == key)
		{
			n_of_words++;
		}
		buffer++;
	}
	return (n_of_words);
}
/**
 * len_per_word - calculates the number characters in a word
 * @str: input string
 * @pos: current position of iterator
 * @key: delimeter
 * Return: number of characters in a word
 */
int len_per_word(const char *str, size_t pos, char key)
{
	int len = 0;

	while (str[pos] != '\0')
	{
		if (str[pos] != key)
			len++;
		pos++;
		if (str[pos] == key)
			break;
	}
	return (len);
}
/**
 * token - splits a string into tokens(array of words)
 * @sorted_array: variable to store tokenized array
 * @buffer: input string
 * @key: delimeter
 * Return: array of token.
 */
char **token(char ***sorted_array, char *buffer, char key)
{
	char *mem_E_msg = "memory allocation failed\n";
	int index_array = 0, no_words = get_num_of_words(buffer, key);
	size_t i, buf_len, sorted_index = 0, len;

	if (buffer == NULL && *sorted_array != NULL)
		return (NULL);
	buf_len = _strlen(buffer);
	(*sorted_array) = malloc(sizeof(char *) * (no_words + 1));
	if ((*sorted_array)  == NULL)
		Error_msg(1, mem_E_msg);
	len = len_per_word(buffer, 0, key);
	for (i = 0; i < buf_len; i++)
	{
		(*sorted_array)[index_array] = malloc((sizeof(char) * (len + 1)));
		if ((*sorted_array)[index_array] == NULL)
		{
			Error_msg(1, mem_E_msg);
			free_ifnf("a", (*sorted_array));
		}
		while ((buffer)[i] != key && (buffer)[i] != '\0')
		{
			if ((*sorted_array)[index_array] != NULL && sorted_index < len)
			{
				(*sorted_array)[index_array][sorted_index] = (buffer)[i];
				sorted_index++, i++;
			}
			if (sorted_index == len)
				(*sorted_array)[index_array][len] = '\0';
		}
		len = len_per_word(buffer, i, key), sorted_index = 0, index_array++;
	}
	(*sorted_array)[no_words] = NULL;
	return (*sorted_array);
}
