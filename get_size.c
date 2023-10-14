#include "main.h"

/**
 * get_size - This function will simply calculate
 * the size to cast the argument
 * @format: This is the formatted string to print the arguments
 * @d: This is the list of arguments to be printed.
 * Return: Precision.
 */

int get_size(const char *format, int *d)
{
	int curr_i = *d + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*d = curr_i - 1;
	else
		*d = curr_i;

	return (size);
}
