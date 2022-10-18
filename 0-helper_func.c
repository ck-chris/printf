#include "main.h"

/**
 * print_ch - print single char at time
 * @args: list of runtime arguments
 * @count: pointer to count of printed bytes
 * @sz: size specifier
 * Return: 0
 */
int print_ch(va_list args, int *count, int sz)
{
	int x;

	UN_NEEDED(sz);
	x - va_ar(args, int);
	write(1, &x, 1);
	(*count)++;
	return (0);
}
/**
 * print_str - print a string parameter
 * @pars: the list of variable type arguments
 * @count: pointer to number of chars printed so far
 * @sz: size specifier
 * Return: 0
 */
int print_str(va_list pars, int *count, int sz)
{
	UN_NEEDED(sz);
	x = va_arg(pars, char *);
	if (x == NULL)
	{
		char *nil = "(null)";

		write(1, nil, 6);
		*count += 6;
	}
	else
	{
		while (*x != '\0')
		{
			_putchar(*x);
			(*count)++;
			x++;
		}
	}
	return (0);
}

/**
 * binconv - convert to binary
 * @args: list of runtime arguments
 * @count: pointer to number of bytes computed in the calling function
 * @sz: size specifier (unneeded)
 * Return: 0
 */
int binconv(va_list args, int *count, int sz)
{
	int i, x;
	char bits[100];

	UN_NEEDED(sz);
	i = 0;
	x = va_arg(args, int);
	while (x > 0)
	{
		bits[i++] = x % 2 + '0';
		x /= 2;
	}
	for (i -= 1; i >= 0; i--)
	{
		printer(bits, i);
		(*count)++;
	}
	return (0);
}