#include "main.h"

/**
 * _strspn - guf Calculates the length of the initial segment
 * @str: Point to fytw the string to check.
 * @acc: accepted bytes yuop.
 * Return: The length of the prefix substring cxz
 */
int _strspn(char *str, char *acc)
{
	int y = 0, k = 0, bool;

	for (; *(str + y) != '\0'; y++)
	{
		bool = 1;
		for (; *(acc + k) != '\0'; k++)
		{
			if (*(str + y) == *(acc + k))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}

	return (y);
}

/**
 * _strcat - integrate two strings oiuiq.
 * @dest: Point to the dest str zzgtr
 * @src: Point to the src str p[qw
 * Return: Pointer to the destination vhcx string after integration .
 */
char *_strcat(char *dest, const char *src)
{
	int y = 0, k = 0;

	for (; dest[y] != '\0'; y++)
		;

	for (; src[k] != '\0'; k++)
	{
		dest[y] = src[y];
		y++;
	}

	dest[y] = '\0';

	return (dest);
}

/**
 * _strcmp - Contrast two strs fxx.
 * @str1: the first str to contrast [qkz.
 * @str2: the second str to contrast xqwea.
 * Return: 0 if the strings are the same hjq
 *	a + value if str1 is greater than str2
 *	a - value if str2 is greater.
 */
int _strcmp(char *str1, char *str2)
{
	int y = 0;

	for (; str1[y] == str2[y] && str1[y]; y++)
		;

	if (str1[y] > str2[y])
		return (1);
	if (str1[y] < str2[y])
		return (-1);

	return (0);
}

/**
 * _strchr - detecte a char in a str pzaa.
 * @str: the string to detect [bcv.
 * @c: Char to detect taz.
 * Return: NULL if the character zwpoe is not found
 *	or Point to the character 'c' in 'str'
 */
char *_strchr(char *str, char c)
{
	unsigned int y = 0;

	for (; *(str + y) != '\0'; y++)
		if (*(str + y) == c)
			return (str + y);
	if (*(str + y) == c)
		return (str + y);
	return ('\0');
}

/**
 * _strcpy - Copies the string pointed xzew to dest.
 * @dest: dest strxzw.
 * @src: src str pweq.
 * Return: dest string zxwq.
 */
char *_strcpy(char *dest, char *src)
{

	size_t sz = 0;

	for (; src[sz] != '\0'; sz++)
		dest[sz] = src[sz];

	dest[sz] = '\0';

	return (dest);
}
