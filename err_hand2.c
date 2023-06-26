#include "main.h"

/**
 * error_404 - hdbh hdbhd  jh hsbhdn hbdhbhd hhbdbhd bhbd hd h bdhhd hd b
 * @data_sh: gbsjh jhbhsbh sb ghvsh b svsh s g hs hs  yhsh ss
 *
 * Return: jnx nsjns sjbs jjs
 */
char *error_404(shll_comm *data_sh)
{
	char *error, *vstor;
	int lngth;

	vstor = conv_itoa(data_sh->counter);
	lngth = _strlen(data_sh->argv[0]) + _strlen(vstr);
	lngth += _strlen(data_sh->args[0]) + 16;
	error = malloc(sizeof(char) * (lngth + 1));
	if (error == 0)
	{
		free(error);
		free(vstor);
		return (NULL);
	}
	_strcpy(error, data_sh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, vstor);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(vstor);

	return (error);
}

/**
 * err_shell_exit - gehysjnksj sjjs j sj jsj sj sj sjj sj bs
 *                  "exit" command in get_exit.
 * @data_sh: hbhsb hbs sb sh h sh sh hs hhhhhhhh jjjjjjjjjsss
 *
 * Return:  hygshbsjhbbs hve.
 */
char *err_shell_exit(shll_comm *data_sh)
{
	char *error, *vstor;
	int lngth;

	vstor = conv_itoa(data_sh->counter);
	lngth = _strlen(data_sh->argv[0]) + _strlen(vstor);
	lngth += _strlen(data_sh->args[0]) + _strlen(data_sh->args[1]) + 23;
	error = malloc(sizeof(char) * (lngth + 1));
	if (error == 0)
	{
		free(vstor);
		return (NULL);
	}
	_strcpy(error, data_sh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, vstor);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, data_sh->args[1]);
	_strcat(error, "\n\0");
	free(vstor);

	return (error);
}

/**
 * err_gcd - gdbhbdh dhbhd  dhb d hd bhbd dh bdjh dn d hbhd dhbduj jdd.
 * @data_sh: ghjdbhjdbjh d bujbd b djvdj bd jhd j d.
 *
 * Return: njnjnjnz jznjnzj .
 */
char *err_gcd(shll_comm *data_sh)
{
	char *error, *vstor, *errormsg;
	int ln, lnid;

	vstor = conv_itoa(data_sh->counter);
	if (data_sh->args[1][0] == '-')
	{
		errormsg = ": Illegal option ";
		lnid = 2;
	}
	else
	{
		errormsg = ": can't cd to ";
		lnid = _strlen(data_sh->args[1]);
	}

	ln = _strlen(data_sh->argv[0]) + _strlen(data_sh->args[0]);
	ln += _strlen(vstor) + _strlen(errormsg) + lnid + 5;
	error = malloc(sizeof(char) * (ln + 1));

	if (error == 0)
	{
		free(vstor);
		return (NULL);
	}

	error = conc_err_msg(data_sh, errormsg, error, vstor);

	free(vstor);

	return (error);
}
