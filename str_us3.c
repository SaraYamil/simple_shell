#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment
 * @str: Point to the string to check.
 * @acc: accepted bytes.
 * Return: The length of the prefix substring
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
 * _strcat - integrate two strings.
 * @dest: Point to the dest str
 * @src: Point to the src str
 * Return: Pointer to the destination string after integration .
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
 * _strcmp - Contrast two strs.
 * @str1: the first str to contrast.
 * @str2: the second str to contrast.
 * Return: 0 if the strings are the same
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
 * _strchr - detecte a char in a str.
 * @str: the string to detect.
 * @c: Char to detect.
 * Return: NULL if the character is not found
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
 * _strcpy - Copies the string pointed to dest.
 * @dest: dest str.
 * @src: src str.
 * Return: dest string.
 */
char *_strcpy(char *dest, char *src)
{

	size_t sz = 0;

	for (; src[sz] != '\0'; sz++)
		dest[sz] = src[sz];

	dest[sz] = '\0';

	return (dest);
}
