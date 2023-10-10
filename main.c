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
	(void)argv;
	return (execute(ac, argv, env));
}
