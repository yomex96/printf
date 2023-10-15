#include "main.h"

/**
 * is_printable - This function evaluates if a char is printable
 * @c: This is the character to be evaluated.
 *
 * Return: 1 if c is printable, else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This function will append ASCII
 * in hexadecimal code to buffer
 * @buffer: This is an array of characters.
 * @d: This is the index to start appending from
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int d)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[d++] = '\\';
	buffer[d++] = 'x';

	buffer[d++] = map_to[ascii_code / 16];
	buffer[d] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This function simply verifies if a character is a digit
 * @c: This is the character to be evaluated
 * Return: 1 if c is a digit, else 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This function is expected to
 * cast a number to a specific size
 * @num: This represents the number to be casted.
 * @size: This represents the type to be casted.
 * Return: The value casted
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - This function should cast a
 * number to a specified size
 * @num: This represents the  number to be casted
 * @size: This represents the type to be casted
 *
 * Return:The value casted
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
