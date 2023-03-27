#include "main.h"

/**
 * get_precision - Calculates the precision
 * @format: Formatted string
 * @i: Listing arguments
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int ch_i = *i + 1;
	int precision = -1;

	if (format[ch_i] != '.')
		return (precision);

	precision = 0;

	for (ch_i += 1; format[ch_i] != '\0'; ch_i++)
	{
		if (is_digit(format[ch_i]))
		{
			precision *= 10;
			precision += format[ch_i] - '0';
		}
		else if (format[ch_i] == '*')
		{
			ch_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ch_i - 1;

	return (precision);
}
