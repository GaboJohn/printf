#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printing function
 * @format: char string
 * Return: Printed character.
 */
int _printf(const char *format, ...)
{
	int g, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (g = 0; format && format[g] != '\0'; g++)
	{
		if (format[g] != '%')
		{
			buffer[buff_ind++] = format[g];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &g);
			width = get_width(format, &g, list);
			precision = get_precision(format, &g, list);
			size = get_size(format, &g);
			++g;
			printed = handle_print(format, &g, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Print buffer if it exist
 * @buffer: chars
 * @buff_ind: Index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
