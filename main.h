#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define UN_NEEDED(x) (void)(x)
#define SIZE 1024

/**
 * struct fmt - Struct op
 * @fmt: the format
 * @fn: The function associated
 */
typedef struct format
{
	char fmt;
	int (*print_function)(va_list pars, int *, int);
}fmt;

/*****************Functions********************/
int _printf(const char *format, ...);

int print_str(va_list args, int *, int);

#endif
