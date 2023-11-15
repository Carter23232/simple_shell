#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include "mystd_f.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

/**
 * struct double_return - returns double variables
 * @buf: string
 * @val: value
 * Description: returns two output in a function
 */
typedef struct double_return
{
	char *buf;
	int val;
} d_ret;

/**
 * struct info - stores all info of user input
 * @buf : argument counter
 * @prv_dir: previous dir
 * @no: stores converted string to no.
 * @arr : tokenized array
 * @env_dup : duplicated environment variable
 * @child : stores child process variable
 * @status : update status value
 * @num_E: stores number of errors
 * @ext_err:exit toggle
 * @env_editted : checks if env is edited
 * Description: organise user inputs
 */

typedef struct info
{
	char *buf;
	char *prv_dir;
	char *no;
	char **arr;
	char **env_dup;
	pid_t child;
	int status;
	int num_E;
	int ext_err;
	int env_edited;
	int env_full;
	d_ret input;

}info;
#define D_RET_INIT \
{NULL, 0}
#define INFO_INIT \
{NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, D_RET_INIT}

d_ret get_command(void);
char **token(char ***sorted_array, char *buffer, char key);
int len_per_word(const char *string, size_t pos, char key);
char  *removeSpacesFromStr(char *str);
void _E_puts(char *msg1, char *msg2, char *msg3);
int execute(int ac, char **argv, char **env);
char *get_path(char *input, char **env);
int test_dir(const char *arg);
void arg_ind_zero(char **input, char **env);
void free_str_arr(char **arr);
int get_num_of_words(char *buffer, char key);
void ext(int status);
int set_env(info info[]);
int set_env_str(info *info, char *var, char *value);
int unset_env(info *info);
d_ret _getenv(char *env[], char *str);
int change_d(info info[]);
int _atoi(info *info, char arg[]);
int _env(info info[]);
int  built_in(info *com_info, char **argv);
int trailing_space(d_ret out);
void copy_env_var(info *info ,char **env);
char **convt_str_to_arr(char *str1, char *str2, char *str3);
void free_info (info *com_info);
#endif