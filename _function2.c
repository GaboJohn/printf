#include "main.h"
/**
 * print_pointer - Print variable
 * @kinds: args
 * @buff: handles print
 * @flags: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed.
 */
int print_pointer(va_list kinds, char buff[],
	int flags, int width, int precision, int size)
{
	char more_c = 0, loop = ' ';
	int inn = BUFF_SIZE - 2, length = 2, inn_start = 1;

	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(kinds, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[inn--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		loop = '0';
	if (flags & F_PLUS)
		more_c = '+', length++;
	else if (flags & F_SPACE)
		more_c = ' ', length++;

	inn++;
	return (write_pointer(buff, inn, length,
		width, flags, loop, more_c, inn_start));
}
/**
 * print_non_printable - Prints non printable chars
 * @kinds: args
 * @buff: handles print
 * @flags: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_non_printable(va_list kinds, char buff[],
	int flags, int width, int precision, int size)
{
	int x = 0, setting = 0;
	char *ptr = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(null)", 6));

	while (ptr[x] != '\0')
	{
		if (is_printable(ptr[x]))
			buff[x + setting] = ptr[x];
		else
			setting += append_hexa_code(ptr[x], buff, x + setting);

		x++;
	}

	buff[x + setting] = '\0';

	return (write(1, buff, x + setting));
}
/**
 * print_reverse - Print reverse string.
 * @kinds: args
 * @buff: handles print
 * @flags: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_reverse(va_list kinds, char buff[],
	int flags, int width, int precision, int size)
{
	char *ptr;
	int x, count = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	ptr = va_arg(kinds, char *);

	if (ptr == NULL)
	{
		UNUSED(precision);

		ptr = ")Null(";
	}
	for (x = 0; ptr[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char c = ptr[x];

		write(1, &c, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print a string
 * @kinds: args
 * @buff: handles print
 * @flags: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_rot13string(va_list kinds, char buff[],
	int flags, int width, int precision, int size)
{
	char c;
	char *ptr;
	unsigned int x, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(kinds, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		ptr = "(AHYY)";
	for (x = 0; ptr[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == ptr[x])
			{
				c = out[y];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			c = ptr[x];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
