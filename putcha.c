#include "main.h"
/**
 * putcha - prints char
 * @a: input
 * Return: 1
 */
int putcha(char a)
{
	return (write(1, &a, 1));
}
