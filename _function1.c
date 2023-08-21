#include "main.h"
/**
 * print_unsigned - Print unsigned int
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed.
 */
int print_unsigned(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	int x = _SIZE - 2;
	unsigned long int nbm = va_arg(kinds, unsigned long int);

	nmb = convert_size_unsgnd(nmb, size);

	if (nmb == 0)
		buff[x--] = '0';

	buff[_SIZE - 1] = '\0';

	while (nbm > 0)
	{
		buff[x--] = (nbm % 10) + '0';
		nbm /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buff, flag, width, precision, size));
}
/**
 * print_octal - Prints unsigned int in octal notation
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_octal(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{

	int x = _SIZE - 2;
	unsigned long int nmb = va_arg(kinds, unsigned long int);
	unsigned long int init_nmb = nmb;

	UNUSED(width);

	nmb = convert_size_unsgnd(nmb, size);

	if (nmb == 0)
		buff[x--] = '0';

	buff[_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		buff[x--] = (nmb % 8) + '0';
		nmb /= 8;
	}

	if (flag & F_HASH && init_nmb != 0)
		buff[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buff, flag, width, precision, size));
}

/**
 * print_hexadecimal - Prints unsigned int in hexadecimal notation
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_hexadecimal(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(kinds, "0123456789abcdef", buff,
		flag, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Print unsigned int in upper hexadecimal notation
 * @kinds: args
 * @buff: handles print
 * @flag: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_hexa_upper(va_list kinds, char buff[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(kinds, "0123456789ABCDEF", buff,
		flag, 'X', width, precision, size));
}
/**
 * print_hexa - Print hexadecimal int in lower or upper case
 * @kinds: args
 * @map_to: maps the number to
 * @buff: handles print
 * @flag: counts flags
 * @flag_ch: counts flags
 * @width: width
 * @precision: Prec specification
 * @size: specifier
 * Return: chars printed
 */
int print_hexa(va_list kinds, char map_to[], char buff[],
	int flag, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int nmb = va_arg(kinds, unsigned long int);
	unsigned long int init_nmb = nmb;

	UNUSED(width);

	nmb = convert_size_unsgnd(nmb, size);

	if (nmb == 0)
		buff[x--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		buff[x--] = map_to[nmb % 16];
		nmb /= 16;
	}

	if (flag & F_HASH && init_nmb != 0)
	{
		buff[x--] = flag_ch;
		buff[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buff, flag, width, precision, size));
}
