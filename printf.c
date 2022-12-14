#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
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
	char *strNULL = "(null)";
	if (s == NULL)
	{
		for (i = 0; strNULL[i] != '\0'; i++)
			_putchar(strNULL[i]);
		return (i);
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
		return (i);
	}
}

/**
 * _strlen - _strlen
 * @s: pointer to int
 * Return: print
 */
int _strlen(char *s)
{
	int i = 0;
	int len = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;

	return (len);
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
	int flag = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (!flag && format[i] == '%')
		{
			flag = 1;
		}
		else if (flag && format[i] == 'c')
		{
			_putchar(va_arg(args, int));
			len++;
			flag = 0;
		}
		else if (flag && format[i] == 's')
		{
			len += printString(va_arg(args, char *));
			flag = 0;
		}
		else if (flag && format[i] == '%')
		{
			_putchar(format[i]);
			len++;
			flag = 0;
		}
		else
		{
			_putchar(format[i]);
			len++;
			flag = 0;
		}
	}
	va_end(args);
	return (len);
}