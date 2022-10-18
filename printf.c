#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printString - prints a string using _putchar
 * @s: String
 * Return: No. of chars printed (length)
 */
int printString(char *s)
{
	int i = 0;

	write(1,s,3);

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * _strlen - _strlen
 *@s: pointer to int
 * Return: print
 */
int _strlen(char *s)
{
	int i = 0;
	int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - _strcpy
 *@dest: pointer to int
 *@src: pointer to int
 * Return: print
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = *(src + i);
	return (dest);
}


 /**
  * _printf - printf
  * @format: char string
  * Return: number of chars printed. 
  */
int _printf(const char *format, ...)
{
	int i = 0;
	int len = 0;
	va_list args;
	va_list tempArgs;
	int flag = 0;
	char *tempStr;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			flag = 1;
		}
		else if (flag && format[i] == 'c')
		{
			_putchar(va_arg(args, int));
			flag = 0;
			len++;
		}
		else if (flag && format[i] == 's')
		{
			_putchar('s');
			printf(va_arg(tempArgs, char *));
			va_copy(args, tempArgs);
			tempStr = malloc(100);
			tempStr = _strcpy(tempStr, va_arg(args, char *));
			va_end(tempArgs);
			len += printString(tempStr);
			flag = 0;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}