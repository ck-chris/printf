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
 * struct format - print function
 * @fmt: the format
 * @pars: va_list of parameters
 */
typedef struct format
{
	char fmt;
	int (*print_function)(va_list pars, int *, int);
} fmt;

/*****************Functions********************/
int _printf(const char *format, ...);

int print_str(va_list pars, int *, int);

int print_ch(va_list args, int *, int);

int binconv(va_list args, int *, int);

int print_percent(va_list, int *, int);

int printer(char *, int);


int print_int(va_list args, int *, int);


int print_dec(va_list args, int *count, int);


int print_unsigned(va_list args, int *count, int);


int print_oct(va_list ap, int *count, int);


int print_hex(va_list ap, int *count, int);


int print_HEX(va_list ap, int *count, int);

int _putchar(char cHar);


int print_mem(va_list list, int *count, int);

int print_rot13(va_list list, int *count, int);

char *rot13(char *str, char *);

int reverse(va_list list, int *count, int);

int print_rev(char *s, int *x);

int print_caller(va_list list, int *count, char sp, int);

int check_size(char c);

long int convert_size(long int n, int sz);

int print_x(unsigned int num);

int print_xcv_string(va_list ap, int *count, int sz);

#endif
