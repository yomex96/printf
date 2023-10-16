#include "main.h"

/** PRINT POINTER */
/**
 * print_pointer - This function will print the value of
 * a pointer variable
 * @types: This will list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This will calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This is the size specifier
 * Return: The exact number of characters printed.
 */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));

}

/** PRINT NON PRINTABLE */

/**
 * print_non_printable - This sholud just print ascii codes
 * in hexa of non printable characters
 * @types: This list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This simply calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This is the  size specifier
 * Return: Exact number of characterss printed
 */
int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int d = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[d] != '\0')
	{
		if (is_printable(str[d]))
			buffer[d + offset] = str[d];
		else
			offset += append_hexa_code(str[d], buffer, d + offset);

		d++;
	}

	buffer[d + offset] = '\0';

	return (write(1, buffer, d + offset));
}

/** PRINT REVERSE */

/**
 * print_reverse - This function should print reverse string.
 * @types: This will list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This will calculate active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This will represent the size specifier
 * Return: The exact number of characterss printed
 */

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	int d, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (d = 0; str[d]; d++)
		;

	for (d = d - 1; d >= 0; d--)
	{
		char z = str[d];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/** PRINT A STRING IN ROT13 */

/**
 * print_rot13string - This function is to print a string in rot13.
 * @types: This will list a type of argument
 * @buffer: This is the buffer array to handle print
 * @flags: This simply calculates active flags
 * @width: This will get width
 * @precision: This is precision specification
 * @size: This is the size specifier
 * Return: The exact number of characters printed
 */
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int d, e;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (d = 0; str[d]; d++)
	{
		for (e = 0; in[e]; e++)
		{
			if (in[e] == str[d])
			{
				x = out[e];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[e])
		{
			x = str[d];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
