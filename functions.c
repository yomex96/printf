#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - This will print a char
 * @types: This will list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: This is expected to simply calculate active flags
 * @width: This is the width
 * @precision: this is the precision specification
 * @size: This represents the size specifier
 * Return: The exact number of characters printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Thi should print a string
 * @types: This will list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: This simply calculates active flags
 * @width: This should get the width.
 * @precision: This represents precision specification
 * @size: this represents the size specifier
 * Return: the exact number of characters printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, d;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (d = width - length; d > 0; d--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (d = width - length; d > 0; d--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - This should simply  print a percentage symbol
 * @types: This will list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: This will simply calculate active flags
 * @width: This will get width.
 * @precision: This is the precision specification
 * @size: This will represent the size specifier
 * Return: The exact number of characters printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - This is espected to just print an int
 * @types: This will list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: this simply will calculate active flags
 * @width: This will get width.
 * @precision: This is the precision specification
 * @size: This will represent the size specifier
 * Return: The exact number of characters printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int d = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[d--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[d--] = (num % 10) + '0';
		num /= 10;
	}

	d++;

	return (write_number(is_negative, d, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/

/**
 * print_binary - This should simply print an unsigned number
 * @types: This will list a type of arguments
 * @buffer: This is the buffer array to handle print
 * @flags: this will calculate active flags
 * @width: This will get width.
 * @precision: This is the precision specification
 * @size:This represents the size specifier
 * Return: The exact number of characters printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int y, m, d, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	y = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = y / m;
	for (d = 1; d < 32; d++)
	{
		m /= 2;
		a[d] = (y / m) % 2;
	}
	for (d = 0, sum = 0, count = 0; d < 32; d++)
	{
		sum += a[d];
		if (sum || d == 31)
		{
			char z = '0' + a[d];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
