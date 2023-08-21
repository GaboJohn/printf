#include "main.h"

/**
 * _printf - Produce output according to format
 * @format:character string
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int x;
	int count, str_count = 0;

	va_list holder;

	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	va_start(holder, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			putcha(format[x]);
		}
		else if (format[x] == '%' && format[x + 1] == 'c')
		{
			putcha(va_arg(holder, int));
			x++;
		}
		else if (format[x] == '%' && format[x + 1] == 's')
		{
			str_count = putss(va_arg(holder, char *));
			x++;
			count += (str_count - 1);
		}
		else if (format[x + 1] == '%')
		{
			putcha('%');
		}
		count += 1;
	}
	va_end(holder);
	return (count);
}
