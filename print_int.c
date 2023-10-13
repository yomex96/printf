#include "main.h"

/**
 * printf_int - This function is supposed to print intergers
 * @args: This is the argument
 * Return: Char
 */

int printf_int(va_list args)
{
	int n = va_args(args, int);
	int num, last = n % 10, digit, exp = 1;
	int q = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		q++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			q++;
		}
	}
	_putchar(last + '0');

	return (q);
}

#include "main.h"

/**
 * printf_dec - This function is supposed to print decimals
 * @args: This is the argument
 * Return: Char
 */

int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int q = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		q++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			q++;
		}
	}
	_putchar(last + '0');

return (q);
}
