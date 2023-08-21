#include "main.h"
/**
 * print_char - Print character
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: Width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_char(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	char s = va_arg(kinds, int);

	return (handle_write_char(s, buff, flag, width, precision, size));
}
/**
 * print_string - Print string
 * @kinds: args
 * @buff: handles print
 * @flag:  Counts flags
 * @width: width.
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_string(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	int length = 0, x;
	char *ptr = va_arg(kinds, char *);

	UNUSED(buff);
	UNUSED(flag);
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
		if (flag & F_MINUS)
		{
			write(1, &ptr[0], length);
			for (i = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; i > 0; x--)
				write(1, " ", 1);
			write(1, &ptr[0], length);
			return (width);
		}
	}

	return (write(1, ptr, length));
}
/**
 * print_percent - Print percentage sign
 * @kinds: args
 * @buff: handles print
 * @flag: count flags
 * @width:  width.
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_percent(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	UNUSED(kinds);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width.
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_int(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int y = va_arg(kinds, long int);
	unsigned long int nmb;

	y = convert_size_number(y, size);

	if (y == 0)
		buff[x--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	nmb = (unsigned long int)y;

	if (y < 0)
	{
		nmb = (unsigned long int)((-1) * y);
		is_negative = 1;
	}

	while (nmb > 0)
	{
		buff[x--] = (nmb % 10) + '0';
		nmb /= 10;
	}

	x++;

	return (write_number(is_negative, x, buff, flag, width, precision, size));
}

/**
 * print_binary - Print unsigned numb
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width.
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed.
 */
int print_binary(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	unsigned int x, y, z, sum;
	unsigned int n[32];
	int count;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(kinds, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	n[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		n[z] = (x / y) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += n[z];
		if (sum || z == 31)
		{
			char c = '0' + n[z];

			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
