#include "main.h"

/**
 * rev_string - converses the char in a given str.
 * @s: The input string to be conversed.
 * Return: nothing
 */
void rev_string(char *s)
{
	int cnt = 0, y = 0, k;
	char *strin, tp;

	while (cnt >= 0)
	{
		if (s[cnt] == '\0')
			break;
		cnt++;
	}
	strin = s;

	for (; y < (cnt - 1); y++)
	{
		for (k = y + 1; k > 0; k--)
		{
			tp = *(strin + k);
			*(strin + k) = *(strin + (k - 1));
			*(strin + (k - 1)) = tp;
		}
	}
}
