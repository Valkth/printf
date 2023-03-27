#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string
 * @i: List of arguments
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int ch_i = *i + 1;
	int size = 0;

	if (format[ch_i] == 'l')
		size = S_LONG;
	else if (format[ch_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ch_i - 1;
	else
		*i = ch_i;

	return (size);
}
