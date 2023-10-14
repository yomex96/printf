#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - this is a printf function
 * @format: This is format.
 * Return: chars.
 */
int _printf(const char *format, ...)
{
	int d, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (d = 0; format && format[d] != '\0'; d++)
	{
		if (format[d] != '%')
		{
			buffer[buff_ind++] = format[d];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[d], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &d);
			width = get_width(format, &d, list);
			precision = get_precision(format, &d, list);
			size = get_size(format, &d);
			++d;
			printed = handle_print(format, &d, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - This will print the content of a buffer
 * @buffer: Array of chars
 * @buff_ind: This is the index to add next char snd represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
