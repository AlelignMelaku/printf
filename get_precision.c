#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int m = *i + 1;
	int precision = -1;

	if (format[m] != '.')
		return (precision);
	precision = 0;
	for (m += 1; format[m] != '\0';
			m++)
	{
		if (is_digit(format[m]))
		{
			precision *= 10;
			precision += format[m] - '0';
		}
		else if (format[m] == '*')
		{
			m++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = m - 1;
	return (precision);
}
