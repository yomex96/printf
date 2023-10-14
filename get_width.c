#include "main.h"

/**
 * get_width - This function will calculate the width for printing
 * @format: This is the formatted string to print the arguments.
 * @d: This is the list of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *d, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *d + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*d = curr_i - 1;

	return (width);
}
