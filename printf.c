#include "main.h"
/**
 * _printf - print strings, characters and %
 * @format: format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, count, b_index, size;
	va_list args;
	/** create an array to hold format string */
	char fm_str[BUFF];

	if (!format || (format[0] == '%' && format[1] == '\0') ||
			(format[0] == '%' && format[1] == ' ' && format[2] == '\0'))
		return (-1);
	va_start(args, format);
	for (i = 0, b_index = 0, count = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			fm_str[b_index++] = format[i];
			printer(fm_str, b_index - 1);
		}
		else
		{
			int x;

			size = check_size(format[i + 1]);
			if (size != 0)
				i++;
			x = print_caller(args, &count, format[i + 1], size);
			if (x == 1)
				i++;
			else
			{
				_putchar('%');
				count++;
			}
		}
	}
va_end(args);
return (count);
}

/**
 * printer - write on the standard output
 * @fm_str: an array of chars in the format string
 * @index: index of char to be printed
 */
void printer(char *fm_str, int index)
{
	write(1, fm_str + index, 1);
}

/**
 * print_caller - call the specifier handler* @list of runtime arguments
 * @list: list of runtime arguments
 * @count: pointer to number of bytes printed so far
 * @sp: the format specifier
 * @sz: the state of the size specifier
 *
 * Return: 1 if it finds a match, o otherwise
 */
int print_caller(va_list list, int *count, char sp, int sz)
{
	fmt fmt_and_fx[] = {
		{'c', print_ch}, {'s', print_str},
		{'b', binconv}, {'%', print_percent},
		{'i', print_int}, {'p', print_mem}, {'R', print_rot13},
		{'c', print_ch}, {'S', print_xcv_string},
		{'b', binconv}, {'%', print_percent},
		{'i', print_int}, {'d', print_dec},
		{'u', print_unsigned}, {'o', print_oct},
		{'x', print_hex}, {'s', print_HEX}, {'r', reverse}
	};
	int i;

	for (i = 0; i < 19; i++)
	{
		if (sp == fmt_and_fx[i].fmt)
		{
			fmt_and_fx[i].print_function(list, count, sz);
			return (1);
		}
	}
	return (0);
}
