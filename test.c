#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;


    len2 = printf("Let's try to printf a simple sentence.\n");
    len = _printf("Let's try to printf a simple sentence.\n");
	printf("%i, %i\n", len, len2);

    printf("Character:[%c]\n", 'H');
    _printf("Character:[%c]\n", 'H');
    printf("String:[%s]\n", "I am a string !");
    _printf("String:[%s]\n", "I am a string !");

    len2 = printf("Percent:[%%]\n");
    len = _printf("Percent:[%%]\n");

    return (0);
}