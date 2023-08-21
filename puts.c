#include "main.h"

/**
 * putss - print string
 * @a: input
 * Return: bytes
 */
int putss(char *a)
{
	int count = 0;

	if (a)
	{
		for (count = 0; a[count] != '\0'; count++)
		{
			putcha(a[count]);
		}
	}
	return (count);
}
