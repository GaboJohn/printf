#include "main.h"
/**
 * handle_print - Prints an argument as per its type.
 * @formatted: Formatted string that will print the arguments.
 * @list: List of arguments that will be printed.
 * @ind: ind.
 * @buffer: Buffer array that handle print.
 * @flags: Calculates active flags.
 * @width: Calculates get width.
 * @precision: Get precision specification
 * @size: Get size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *formatted, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	formatted_t formatted_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; formatted_types[i].formatted != '\0'; i++)
		if (formatted[*ind] == formatted_types[i].formatted)
			return (formatted_types[i].fn(list, buffer, flags, width, precision, size));

	if (formatted_types[i].formatted == '\0')
	{
		if (formatted[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (formatted[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formatted[*ind] != ' ' && formatted[*ind] != '%')
				--(*ind);
			if (formatted[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &formatted[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
