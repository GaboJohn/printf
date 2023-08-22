#include "main.h"

/**
 * print_pointer - Print value of pointer
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;

	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}
/**
 * print_non_printable - Prints chars that are non printable
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[g] != '\0')
	{
		if (is_printable(str[g]))
			buffer[g + offset] = str[g];
		else
			offset += append_hexa_code(str[g], buffer, g + offset);

		g++;
	}

	buffer[g + offset] = '\0';

	return (write(1, buffer, g + offset));
}

/**
 * print_reverse - Print reverse string.
 * @types: args
 * @buffer: handles print
 * @flags: count flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *ptr;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	ptr = va_arg(types, char *);

	if (ptr == NULL)
	{
		UNUSED(precision);

		ptr = ")Null(";
	}
	for (x = 0; ptr[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = ptr[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Prints strings
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char g;
	char *ptr;
	unsigned int x, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(types, char *);
	UNUSED(buffer);
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
				g = out[y];
				write(1, &g, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			g = ptr[x];
			write(1, &g, 1);
			count++;
		}
	}
	return (count);
}
