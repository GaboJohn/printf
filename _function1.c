#include "main.h"

/**
 * print_unsigned - Prints unsigned int
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints unsigned number in octal notation
 * @types: args
 * @buffer: handles print
 * @flags:  counts active flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int xx = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Print unsigned number in hexadecimal notation
 * @types: args
 * @buffer: handles print
 * @flags: counts active flags
 * @width:obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
			flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Print unsigned number in upper hexadecimal notation
 * @types: args
 * @buffer: handles print
 * @flags: counts flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return:  printed chars
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Print hexadecimal number in lower or upper
 * @types: args
 * @map_to: map the number to
 * @buffer: handles print
 * @flags:  Counts active flags
 * @flag_ch: Calculates active flags
 * @width: obtains width
 * @precision: Prec specification
 * @size: specifier
 * Return: printed chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
