#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string
 * @i: List of arguments iterated
 * @list: list of arguments
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int ch_i;
	int width = 0;

	for (ch_i = *i + 1; format[ch_i] != '\0'; ch_i++)
	{
		if (is_digit(format[ch_i]))
		{
			width *= 10;
			width += format[ch_i] - '0';
		}
		else if (format[ch_i] == '*')
		{
			ch_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ch_i - 1;

	return (width);
}
