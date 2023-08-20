#ifndef DRISS_TARIK_H
#define DRISS_TARIK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putch(char ch);
int print_str(char *string);
int print_nombre(int n);
int long_nbr(int nbr);

#endif
