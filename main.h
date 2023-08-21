#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buf_in);
int print_char(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_string(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_percent(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_int(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_binary(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_unsigned(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_octal(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_hexadecimal(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_hexa_upper(va_list kinds, char buff[],
        int flag, int width, int precision, int size);
int print_pointer(va_list kinds, char buff[],
        int flags, int width, int precision, int size);
int print_non_printable(va_list kinds, char buff[],
        int flags, int width, int precision, int size);
int print_reverse(va_list kinds, char buff[],
        int flags, int width, int precision, int size);
int print_rot13string(va_list kinds, char buff[],
        int flags, int width, int precision, int size);


#endif
