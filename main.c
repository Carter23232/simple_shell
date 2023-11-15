#include "main.h"
/**
 * main - entry int to program
 * @ac : argument counter
 * @argv : array of arguments
 * @env : environment variable
 * Return: 0 on success
 */

int main(int ac, char **argv, char *env[])
{

	int status = 0;

	status = execute(ac, argv, env);
	(void)argv;
	return (status);
}
