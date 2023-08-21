#include "main.h"

void print_buffer(char buffer[], int *buf_in);
/**
 * _printf - Produce output according to format
 * @format:character string
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int size, buf_in, width, precision, flag = 0;
	int x, count, str_count = 0;

	va_list holder;
	char buffer[_SIZE];

	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	va_start(hold, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buf_in++] = format[x];
			if (buf_in == _SIZE)
				print_buffer(buffer, &buf_in);
			str_count++;
		}
		else
		{
			print_buffer(buffer, &buf_in);
			size = set_size(format, &x);
			precision = set_prec(format, &x, hold);
			width = set_width(format, &x, hold);
			flag = set_flags(format, &x);
			++x;
	count = handle_print(format, % x, hold, buffer, flag, width, precision, size);
			if (count == -1)
				return (-1);
			str_count += count;
		}
		}
	print_buffer(buffer & buf_in);

	va_end(holder);
	return (str_count);
}
/**
 * print_buffer - print existing buff
 * @buffer: chars
 * @buf_in: index representing length
 */
void print_buffer(char buffer[], int *buf_in)
{
	if (*buf_in > 0)

		write(1, &buffer[0], *buf_in);
	*buf_in = 0;
}
