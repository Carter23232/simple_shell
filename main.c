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

/**
	// Print the updated environment
	for (int i = 0; env[i] != NULL; i++) {
		printf("%s\n", env[i]);
	}
	printf("\n\n");
char *arr[] = {"setenv","KOFI","100", NULL};
	set_env(&env, arr, &status);

		// Print the updated environment
	for (int i = 0; env[i] != NULL; i++) {
		printf("%s\n", env[i]);
	}
	char *unset[] = {"unsetenv", "KOFI", NULL};
	unset_env(&env, unset);
	printf("\n\n");
	for (int i = 0; env[i] != NULL; i++) {
		printf("%s\n", env[i]);
	}
 **/
}
