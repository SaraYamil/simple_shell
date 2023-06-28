#include "main.h"

/**
 * _strspn - str ikkn
 * @str: Pointer str
 * @acc: Pointeraccepted
 * Return: len.
 */
int _strspn(char *str, char *acc)
{
	int y, k, bool;

	for (y = 0; *(str + y) != '\0'; y++)
	{
		bool = 1;
		for (k = 0; *(acc + k) != '\0'; k++)
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
 * _strcat - conca str.
 * @dest: dest
 * @src: src
 *
 * Return: to des.
 */
char *_strcat(char *dest, const char *src)
{
	int y, k;

	for (y = 0; dest[y] != '\0'; y++)
		;

	for (k = 0; src[k] != '\0'; k++)
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
 * Return: 0 or bigger than 0
*/
int _strcmp(char *str1, char *str2)
{

	int y;

	for (y = 0; str1[y] == str2[y] && str1[y]; y++)
		;

	if (str1[y] > str2[y])
		return (1);
	if (str1[y] < str2[y])
		return (-1);

	return (0);
}

/**
 * _strchr - serch ddd.
 * @str: string to search.
 * @c: Chara to find.
 *
 * Return: o or 1
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
 * _strcpy -Copies the string pointed to dest.
 * @dest: dest str.
 * @src: src str.
 * Return: dest string.
 */
char *_strcpy(char *dest, char *src)
{

	size_t sz;

	for (sz = 0; src[sz] != '\0'; sz++)
		dest[sz] = src[sz];

	dest[sz] = '\0';

	return (dest);
}
