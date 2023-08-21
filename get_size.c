#include "main.h"

/**
 * get_size - Calculates the size to show the argument
 * @format: Formatted string in which will print the arguments
 * @p: List of arguments that will be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *p)
{
	int curr_p = *p + 1;
	int size = 0;

	if (format[curr_p] == 'l')
		size = S_LONG;
	else if (format[curr_p] == 'h')
		size = S_SHORT;

	if (size == 0)
		*p = curr_p - 1;
	else
		*p = curr_p;

	return (size);
}
