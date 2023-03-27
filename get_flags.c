#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string
 * @i: take a parameter.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int m, ch_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ch_i = *i + 1; format[ch_i] != '\0'; ch_i++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[ch_i] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*i = ch_i - 1;

	return (flags);
}
