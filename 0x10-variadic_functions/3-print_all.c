#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_s -print string
 * @list: arg list
 *
 * Description: print str
 */
void print_s(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		printf("(nil)");
	printf("%s", s);
}
/**
 * print_i -pprint integer
 * @list: arg list
 *
 * Description: print int
 */
void print_i(va_list list)
{
	printf("%d", va_arg(list, int));
}
/**
 * print_f -print float
 * @list: arg list
 *
 * Description: print float
 */
void print_f(va_list list)
{
	printf("%f", va_arg(list, double));
}
/**
 * print_c -print char
 * @list: arg list
 *
 * Description: print char
 */
void print_c(va_list list)
{
	printf("%c", va_arg(list, int));
}
/**
 * print_all -print every thing
 * @format: format string
 *
 * Description: print string based on format
 */
void print_all(const char *const format, ...)
{
	char fmt[] = {'c', 'i', 'f', 's'};
	int i, j;
	va_list args;
	void (*ptr_print[])(va_list) = {print_c, print_i, print_f, print_s};

	va_start(args, format);
	i = j = 0;
	while (format[i] != '\0')
	{
		while ((format[i] != fmt[j]) && j < 4)
			j++;
		if (j < 4)
		{
			ptr_print[j](args);
		}
		/*printf("\tj = %d \tformat[%d + 1] = %c\t\n", j, i, format[i + 1]);*/
		if (!((j < 4 && format[i + 1] == '\0') || j >= 4))
			printf(", ");
		i++;
		j = 0;
	}
	printf("\n");
}
