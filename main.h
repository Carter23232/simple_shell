#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include "mystd_f.h"
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
char **token(char *buffer);
int len_per_word(const char *string, size_t pos);
char  *removeSpacesFromStr(char *str);
void Error_msg(const char *msg);
void execute(int ac, char **argv,char **env);
char *get_path(const char *input);
int test_dir(const char *arg);
char *arg_ind_zero(char *input);
void free_str_arr(char **arr);
int get_num_of_words(char *buffer);
void ext(int status, int *toggle);
void set_env(const char **arr, int *toggle, pid_t *child);
void unset_env(const char **arr, int *toggle, pid_t *child);
char *_getenv(char *env[], char *str);
int envs_unset(char **env);
void change_d(const char **arr, int *toggle, char **previous_dir, pid_t *child, char *env[]);
int trailing_space(d_ret out);
#endif
