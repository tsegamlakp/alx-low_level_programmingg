#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * len -returns length of string
 * @s: string to test
 *
 * Description: return length of string
 *
 * Return: length excluding null char
 */
int len(char *s)
{
	int le;

	le = 0;
	while (*s != '\0')
	{
		le++;
		s++;
	}

	return (le);
}
/**
 * RevStr - reverse string buffer
 * @s: string to be reversed
 *
 * Description: reverse string buffer
 *
 * Return: pointer to reversed string
 */
char *RevStr(char *s)
{
	int i, j;
	char tmp;

	j = len(s) - 1;
	for (i = 0; i < len(s) / 2; i++)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		j--;
	}

	return (s);
}
/**
 * asint - return character as integre 1- 9
 * @c: character to be changed
 *
 * Description: return asci numbers to digits 1- 9
 *
 * Return: digits  1- 9
 */
int asint(char c)
{
	return (c - '0');
}
/**
 * aschar -return char representation of digits
 * @n: digit to be changed
 *
 * Description: return digit to asci code
 *
 * Return: asci code of digits  1- 9
 */
char aschar(int n)
{
	return (n + '0');
}
/**
 * _malloc -realloc memory give size
 * @size: new size
 *
 * Description: realoc memory
 *
 * Return: pointer to allocated memory
 */
char *_malloc(int size)
{
	char *m;
	int i;

	m = malloc(sizeof(char) * (size + 1));
	if (m == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		m[i] = '0';
	m[size] = '\0';
	return (m);
}
/**
 * mcp -memory copy
 * @src: source
 * @dest: destinaton
 *
 * Description: copy memory data from src to destination
 *
 * Return: destination
 */
char *mcp(char *src, char *dest)
{
	int i;

	for (i = 0; i < len(dest); i++)
		dest[i] = src[i];
	return (dest);
}
/**
 * _realloc_print -realloc exact memory
 * @r: src
 * @s: size
 *
 * Description: reallocate memory
 */
void _realloc_print(char *r, int s)
{
	int size, i;
	char *RR, *R;

	i = 0;
	while (r[i] == '0')
	{
		i++;
	}
	size = s  - i;
	RR = _malloc(size);
	if (RR == NULL)
	{
		exit(98);
	}
	R = mcp(&r[i], RR);
	printf("%s\n", R);
	free(RR);
}
/**
 * sumArray -get sum of elements of array
 * @src: source
 * @row: rows
 * @col: columns
 * @size: size required for storing result
 *
 * Description: sum elements of array colum wise
 *
 * Return: pointer to result array
 */
char *sumArray(char **src, int row, int col, int size)
{
	char *result;
	int co, sum, j, i;

	co = sum = 0;
	result = malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	co = 0;
	sum = 0;

	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row; i++)
		{
			sum = sum + asint(src[i][j]);
		}
		sum = sum + co;
		co = sum / 10;
		result[j] = aschar(sum % 10);
		sum = 0;
	}
	result[col] = aschar(co);

	return (result);
}
/**
 * print_s -print str
 * @s: string to be printed
 *
 * Descripion: print string
 */
void print_s(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}
/**
 * fill_array -fill array
 * @mArray: input array
 * @row: number of rows
 * @col: number of colmuns
 * @num2: second number
 *
 * Description: fill array with nums
 *
 * Return: pointer to filled array
 */
char **fill_array(char **mArray, int row, int col, char *num2)
{
	int tmp, i, j, co;

	co = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			tmp = asint(mArray[i][j]);
			mArray[i][j] = aschar((tmp * asint(num2[i]) + co) % 10);
			co = (tmp * asint(num2[i]) + co) / 10;
		}
		mArray[i][j] = co;
		co = 0;
	}

	return (mArray);
}


/**
 * init_array -initialize the two D  array
 * @row: number of rows
 * @col: number of columns
 * @num1: first num
 * @num2: second num
 *
 * Description: initialize the two D array
 *
 * Return: pointer to twoD array
 */
char **init_array(int row, int col, char *num1, char *num2)
{
	char **mArray;
	int i, j;

	mArray = malloc(sizeof(char *) * row);
	if (mArray == NULL)
		return (NULL);
	for (i = 0; i < row; i++)
	{
		mArray[i] = malloc(sizeof(char) * col);
		if (mArray[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(mArray[j]);
			free(mArray);
			return (NULL);
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < i)
				mArray[i][j] = '0';
			else if (j < (i + len(num1)))
				mArray[i][j] = num1[j - i];
			else
				mArray[i][j] = '0';

		}
	}
	fill_array(mArray, row, col, num2);

	return (mArray);
}
/**
 * check_zero -check if all are zero
 * @s: string
 *
 * Description: check if all are zero
 *
 * Return: value if zero
 */
int check_zero(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != '0')
			i++;
		s++;
	}

	return (i);
}
/**
 * main -entry point
 * @argc: number of argumnents
 * @argv: argumnet vector
 *
 * Description: main program
 *
 * Return: 0 always  98 if fail exits
 */

int main(int argc, char **argv)
{
	char *num1, *num2, *r, *result;
	char **mArray;
	int i, row, col, size;

	if (argc != 3)
	{
		print_s("Error");
		exit(98);
	}
	if (check_zero(argv[1]) == 0 || check_zero(argv[2]) == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	num1 = RevStr(argv[1]);
	num2 = RevStr(argv[2]);
	row = len(num2);
	size = len(num1) + len(num2) + 2;
	col = len(num1) + len(num2) + 1;
	for (i = 0; i < row; i++)
		if (num2[i] > '9' || num2[i] < '0')
		{
			print_s("Error");
			exit(98);
		}
	for (i = 0 ; i < len(num1); i++)
		if (num1[i] > '9' || num1[i] < '0')
		{
			print_s("Error");
			exit(98);
		}
	mArray = init_array(row, col, num1, num2);
	result = sumArray(mArray, row, col, size);
	r = RevStr(result);
	_realloc_print(r, size);
	free(r);

	return (0);
}
