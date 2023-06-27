#include "main.h"

/**
 * frstchrctr - finds the index of the first non-whitespace character.
 * @inp: intptr_t string.
 * @index: pointer to the index variable.
 *
 * Return: 1 if there is an error, 0 otherwise.
 */
int frstchrctr(char *inp, int *index)
{

	for (*index = 0; inp[*index]; *index += 1)
	{
		if (inp[*index] == ' ' || inp[*index] == '\t')
			continue;

		if (inp[*index] == ';' || inp[*index] == '|' || inp[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * dspsynerr - displays a syntax error message.
 * @data_sh: data structure.
 * @inp: intptr_t string.
 * @index: index of the error.
 * @boolean: flag to control the error message.
 *
 * Return: No return value.
 */
void dspsynerr(shll_comm *data_sh, char *inp, int index, int boolean)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (inp[index] == ';')
	{
		if (boolean == 0)
			msg = (inp[index + 1] == ';' ? ";;" : ";");
		else
			msg = (inp[index - 1] == ';' ? ";;" : ";");
	}

	if (inp[index] == '|')
		msg = (inp[index + 1] == '|' ? "||" : "|");

	if (inp[index] == '&')
		msg = (inp[index + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = convitoa(data_sh->counter);
	length = _strlength(data_sh->argv[0]) + _strlength(counter);
	length += _strlength(msg) + _strlength(msg2) + _strlength(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcopy(error, data_sh->argv[0]);
	_strccaat(error, ": ");
	_strccaat(error, counter);
	_strccaat(error, msg2);
	_strccaat(error, msg);
	_strccaat(error, msg3);
	_strccaat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * chsynerr - intermediate function to find and print a syntax error.
 * @data_sh: data structure.
 * @inptrt: intptr_t string.
 *
 * Return: 1 if there is an error, 0 otherwise.
 */
int chsynerr(shll_comm *data_sh, char *inptrt)
{
	int start = 0, fcharac = 0, index = 0;

	fcharac = frstchrctr(inptrt, &start);
	if (fcharac == -1)
	{
		dspsynerr(data_sh, inptrt, start, 0);
		return (1);
	}

	index = sepopererr(inptrt + start, 0, *(inptrt + start));
	if (index != 0)
	{
		dspsynerr(data_sh, inptrt, start + index, 1);
		return (1);
	}

	return (0);
}

/**
 * duplchrs - counts the repetitions of a character in a string.
 * @inp: intptr_t string.
 * @index: index.
 *
 * Return: The number of repetitions.
 */
int duplchrs(char *inp, int index)
{
	if (*(inp - 1) == *inp)
		return (duplchrs(inp - 1, index + 1));

	return (index);
}

/**
 * sepopererr - finds syntax errors in the intptr_t string.
 * @inp: intptr_t string.
 * @index: index.
 * @lastchar: last character read.
 *
 * Return: The index of the error. Returns 0 when there are no errors.
 */
int sepopererr(char *inp, int index, char lastchar)
{
	int counter = 0;

	if (*inp == '\0')
		return (0);

	if (*inp == ' ' || *inp == '\t')
		return (sepopererr(inp + 1, index + 1, lastchar));

	if (*inp == ';')
		if (lastchar == '|' || lastchar == '&' || lastchar == ';')
			return (index);

	if (*inp == '|')
	{
		if (lastchar == ';' || lastchar == '&')
			return (index);

		if (lastchar == '|')
		{
			counter = duplchrs(inp, 0);
			if (counter == 0 || counter > 1)
				return (index);
		}
	}

	if (*inp == '&')
	{
		if (lastchar == ';' || lastchar == '|')
			return (index);

		if (lastchar == '&')
		{
			counter = duplchrs(inp, 0);
			if (counter == 0 || counter > 1)
				return (index);
		}
	}

	return (sepopererr(inp + 1, index + 1, *inp));
}
