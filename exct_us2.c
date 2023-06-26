#include "main.h"

/**
 * exit_sh - bhdbjhdbhdbj llR
 * @datashell: ,kdikdk dkkdnjk dnd j djk dj tus and args)
 * Return: maso9akch ww.
 */
int exit_sh(shll_comm *datashell)
{
	unsigned int ustat;
	int is_dgt, strlen, big_n;

	if (datashell->args[1] != NULL)
	{
		ustat = _atoi(datashell->args[1]);
		is_dgt = _isdigit(datashell->args[1]);
		strlen = _strlen(datashell->args[1]);
		big_n = ustat > (unsigned int)INT_MAX;
		if (!is_dgt || strlen > 10 || big_n)
		{
			get_err(datashell, 2);
			datashell->stat = 2;
			return (1);
		}
		datashell->stat = (ustat % 256);
	}
	return (0);
}

/**
 * execute_line - jsbsusb sjhbjbsuuushbhsbands.
 * @datash: snjsjnknsjknjksnsks).
 * Return: shbjhbsjbhshbsk
 */
int execute_line(shll_comm *datash)
{
	int (*builtin)(shll_comm *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_bltn(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (command_exec(datash));
}

/**
 * err_environ - jsnnjsns  sjhsb jhshyhsyusu ybshbhsbbbbsated operations.
 * @data_sh: ks,kl,snjysgugv svu sgvsvkvs, svvsb sujisiknts).
 * Return: siujsbbsbsb hbb sjh .
 */
char *err_environ(shll_comm *data_sh)
{
	int length;
	char *err, *txt, *vstr;

	vstr = conv_itoa(data_sh->counter);
	txt = ": Unable to add/remove from environment\n";
	length = _strlen(data_sh->argv[0]) + _strlen(vstr);
	length += _strlen(data_sh->args[0]) + _strlen(txt) + 4;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}

	_strcpy(err, data_sh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, txt);
	_strcat(err, "\0");
	free(vstr);

	return (err);
}

/**
 * err_path126 - jsujnjsnjnjsjnsjnjksnkskbksk sk sbbs ksbkks
 *                operations with permission denied.
 * @data_sh: kjsjbsnbhbsbkshlihnlsnjhbsnsb sbhhsjns juments).
 *
 * Return: jksnjnjsjskhsbjhbhsjnsjjsnj
 */
char *err_path126(shll_comm *data_sh)
{
	int length;
	char *vstr, *err;

	vstr = conv_itoa(data_sh->counter);
	length = _strlen(data_sh->argv[0]) + _strlen(vstr);
	length += _strlen(data_sh->args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}
	_strcpy(err, data_sh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(vstr);
	return (err);
}

/**
 * conc_err_msg - csnjnsjns n sjkbjkbsk ns bs ns jh sj js  jn sj shb.
 * @data_sh: sbhbshvyukgsh sv vs s gjcusb sb sghvuvs sgvusuvs).
 * @disp_msg: nsjh sbhsbh sb sjhbhbsn.
 * @err: jsnjsjnjsjsksksls fer.
 * @vstr: hsuhnsjnjsnjsux
 *
 * Return: bsbdbhd hbdhb dhd hbdjh bd hge.
 */
char *conc_err_msg(shll_comm *data_sh, char *disp_msg, char *err, char *vstr)
{
	char *illegal_flag;

	_strcpy(err, data_sh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, disp_msg);
	if (data_sh->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data_sh->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, data_sh->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}
