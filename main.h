#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include "mystd_f.h"
#include "printf.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

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

d_ret get_command(char *env[]);
char **token(char ***sorted_array, char *buffer, char key);
int len_per_word(const char *string, size_t pos, char key);
char  *removeSpacesFromStr(char *str);
void Error_msg(int i, ...);
int execute(int ac, char **argv,char **env);
char *get_path(const char *input, char **env);
int test_dir(const char *arg);
void arg_ind_zero(char **input, char **env);
void free_str_arr(char **arr);
int get_num_of_words(char *buffer, char key);
void ext(int status);
void set_env(const char **arr);
void unset_env(const char **arr);
char *_getenv(char *env[], char *str);
void change_d(const char **arr, char **previous_dir, char *env[]);
int  built_in(int *status,char **argv, char **pr_dir, char **arr, char *buf, char *env[], int *ext_er);
int trailing_space(d_ret out);
char **copy_env_var(char **env);
#endif
