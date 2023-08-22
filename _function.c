#include "main.h"

/**
 * print_char - Print char
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Print string
 * @types: args
 * @buffer: handles print
 * @flags:  Counts active flags
 * @width: obtains width.
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, x;
	char *ptr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			write(1, &ptr[0], length);
			return (width);
		}
	}

	return (write(1, ptr, length));
}
/**
 * print_percent - Prints percentage sign
 * @types: args
 * @buffer: handles print
 * @flags:  counts flags
 * @width: obtains width.
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print integer
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width.
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int q = va_arg(types, long int);
	unsigned long int num;

	q = convert_size_number(q, size);

	if (q == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)q;

	if (q < 0)
	{
		num = (unsigned long int)((-1) * q);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}
/**
 * print_binary - Print num
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width.
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int q, r, t, sum;
	unsigned int s[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	q = va_arg(types, unsigned int);
	r = 2147483648; /* (2 ^ 31) */
	s[0] = q / r;
	for (t = 1; t < 32; t++)
	{
		q /= 2;
		s[t] = (q / r) % 2;
	}
	for (t = 0, sum = 0, count = 0; t < 32; t++)
	{
		sum += s[t];
		if (sum || t == 31)
		{
			char z = '0' + s[t];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
