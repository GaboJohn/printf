#include "main.h"

/**
 * get_flags - counts flags
 * @format: Formatted string
 * @i: takes parameter.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{

	int x, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[curr_i] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
