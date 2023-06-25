#include "main.h"

/**
 * conv_itoa - Converts an integer to a str.
 * @number: The int number to conv
 * Return: The string representation of the intm.
 */
char *conv_itoa(int number)
{
	unsigned int num0;
	int lent = get_length(number);
	char *b;

	b = malloc(sizeof(char) * (lent + 1));
	if (b == 0)
		return (NULL);

	*(b + lent) = '\0';

	if (number < 0)
	{
		nym0 = number * -1;
		b[0] = '-';
	}
	else
		num0 = number;

	lent--;
	do {
		*(b + lent) = (num0 % 10) + '0';
		num0 = num0 / 10;
		lent--;
	} while (num0 > 0);
	return (b);
}

/**
 * get_length - Get the length of num.
 * @number: The number which calculate the length.
 * Return: The length of the number to check.
 */
int get_length(int number)
{
	unsigned int num0;
	int lent = 1;

	if (number < 0)
	{
		lent++;
		num0 = number * -1;
	}
	else
		num0 = number;
	while (num0 > 9)
	{
		lent++;
		num0 = num0 / 10;
	}

	return (lent);
}

/**
 * _atoi - Conv str to integer.
 * @str: str input.
 * Return: The conv int to check.
 */
int _atoi(char *str)
{
	unsigned int cnt = 0, sz = 0, in = 0, pl = 1, n = 1, y;

	while (*(str + cnt) != '\0')
	{
		if (sz > 0 && (*(str + cnt) < '0' || *(str + cnt) > '9'))
			break;

		if (*(str + cnt) == '-')
			pl *= -1;

		if ((*(str + cnt) >= '0') && (*(str + cnt) <= '9'))
		{
			if (sz > 0)
				n *= 10;
			sz++;
		}
		cnt++;
	}

	for (y = cnt - sz; y < cnt; y++)
	{
		in = in + ((*(str + y) - 48) * n);
		n /= 10;
	}
	return (in * pl);
}
