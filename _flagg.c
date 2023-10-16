#include "main.h"

/**
 * get_flags - this function simply calculates active flags
 * @format: This is the formatted string to print the arguments
 * @d: This will take a parameter.
 * Return: The flags:
 */
int get_flags(const char *format, int *d)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int e, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *d + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (e = 0; FLAGS_CH[e] != '\0'; e++)
			if (format[curr_i] == FLAGS_CH[e])
			{
				flags |= FLAGS_ARR[e];
				break;
			}

		if (FLAGS_CH[e] == 0)
			break;
	}

	*d = curr_i - 1;

	return (flags);
}
