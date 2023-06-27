#include "main.h"

/**
 * ext_sh - Exits the shell
 * @datashell: Data structure containing relevant data
 *             (status and args)
 *
 * Return: 0 on success.
 */
int ext_sh(shll_comm *datashell)
{
	unsigned int ustat;
	int is_dgt, strlen, big_n;

	if (datashell->args[1] != NULL)
	{
		ustat = _ati(datashell->args[1]);
		is_dgt = _isdigital(datashell->args[1]);
		strlen = _strlength(datashell->args[1]);
		big_n = ustat > (unsigned int)INT_MAX;
		if (!is_dgt || strlen > 10 || big_n)
		{
			geterr(datashell, 2);
			datashell->stat = 2;
			return (1);
		}
		datashell->stat = (ustat % 256);
	}
	return (0);
}

/**
 * excut_ln - Finds built-ins and commands.
 * @datash: Data relevant (args).
 *
 * Return: 1 on success.
 */
int excut_ln(shll_comm *datash)
{
	int (*builtin)(shll_comm *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_bltn(datash->args[0]);

	if (builtin != NULL)
		return (getbltn(datash));

	return (cmmnd_ex(datash));
}

/**
 * err_envrn - generates an error message for env-related operations.
 * @data_sh: data relevant to the shell (counter, arguments).
 *
 * Return: Error message string.
 */
char *err_envrn(shll_comm *data_sh)
{
	int length;
	char *err, *txt, *vstr;

	vstr = convitoa(data_sh->counter);
	txt = ": Unable to add/remove from environment\n";
	length = _strlength(data_sh->argv[0]) + _strlength(vstr);
	length += _strlength(data_sh->args[0]) + _strlength(txt) + 4;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}

	_strcopy(err, data_sh->argv[0]);
	_strccaat(err, ": ");
	_strccaat(err, vstr);
	_strccaat(err, ": ");
	_strccaat(err, data_sh->args[0]);
	_strccaat(err, txt);
	_strccaat(err, "\0");
	free(vstr);

	return (err);
}

/**
 * errpth126 - generates an error message for path-related
 *                operations with permission denied.
 * @data_sh: data relevant to the shell (counter, arguments).
 *
 * Return: The error message string.
 */
char *errpth126(shll_comm *data_sh)
{
	int length;
	char *vstr, *err;

	vstr = convitoa(data_sh->counter);
	length = _strlength(data_sh->argv[0]) + _strlength(vstr);
	length += _strlength(data_sh->args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}
	_strcopy(err, data_sh->argv[0]);
	_strccaat(err, ": ");
	_strccaat(err, vstr);
	_strccaat(err, ": ");
	_strccaat(err, data_sh->args[0]);
	_strccaat(err, ": Permission denied\n");
	_strccaat(err, "\0");
	free(vstr);
	return (err);
}

/**
 * concermsg - concatenates an error message for the 'cd' command.
 * @data_sh: data relevant to the shell (directory, arguments).
 * @disp_msg: message to be displayed.
 * @err: output message buffer.
 * @vstr: counter lines.
 *
 * Return: The concatenated error message.
 */
char *concermsg(shll_comm *data_sh, char *disp_msg, char *err, char *vstr)
{
	char *illegal_flag;

	_strcopy(err, data_sh->argv[0]);
	_strccaat(err, ": ");
	_strccaat(err, vstr);
	_strccaat(err, ": ");
	_strccaat(err, data_sh->args[0]);
	_strccaat(err, disp_msg);
	if (data_sh->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data_sh->args[1][1];
		illegal_flag[2] = '\0';
		_strccaat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, data_sh->args[1]);
	}

	_strccaat(err, "\n");
	_strccaat(err, "\0");
	return (err);
}
