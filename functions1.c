#include "main.h"

/** PRINT UNSIGNED NUMBER */

/**
 * print_unsigned - This will simply print a non negative number
 * @types: This lists a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: This will calculate active flags
 * @width: This will get width
 * @precision: this is precision specification
 * @size: This represents the size specifier
 * Return: The exact number of characters printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int d = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[d--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[d--] = (num % 10) + '0';
		num /= 10;
	}

	d++;

	return (write_unsgnd(0, d, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN OCTAL */

/**
 * print_octal - This should print a non negative number in octal notation
 * @types: This list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags:  This simply calculates active flags
 * @width: This will get width
 * @precision: this is precision specification
 * @size:This represents size specifier
 * Return:The exact number of characters printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int d = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[d--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[d--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[d--] = '0';

	d++;

	return (write_unsgnd(0, d, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN HEXADECIMAL */

/**
 * print_hexadecimal - This will print a non negative number
 * in hexadecimal notation
 * @types: This list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This represents the size specifier
 * Return: The exact number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */

/**
 * print_hexa_upper - This will print a non negative number
 * in upper hexadecimal notation
 * @types: This list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This simply calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This is the size specifier
 * Return: Exact number of characters printed
 */

int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** PRINT HEXX NUM IN LOWER OR UPPER */

/**
 * print_hexa - This should print a hexadecimal number in lower or upper case
 * @types: This list a type of arguments
 * @map_to: This is an array of values to map the number to
 * @buffer: This is the buffer array to handle print
 * @flags: This simply calculates active flags
 * @flag_ch: This calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This is the size specifier
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int d = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[d--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[d--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[d--] = flag_ch;
		buffer[d--] = '0';
	}

	d++;

	return (write_unsgnd(0, d, buffer, flags, width, precision, size));
}
