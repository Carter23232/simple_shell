#ifndef MYSTD_F
#define MYSTD_F
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, int n, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _atoi(const char **s, char *argv, int *err_n);
char *_strcpy(char *dest, const char *src);
char *int_str(int num);
int _puts(char *str);
int _env(char **env_var);
#endif
