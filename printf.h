#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

/* Functions prototypes */

int print_char(char c);
int print_string(char *s);
int _printf(const char *format, ...);
int getNumberLength(int myNum);
void check_number(int n);

#endif
