#include "main.h"

/**
 * replace_str - kijuihyugytf vyfyvvyc gvtyfty vyctyc vyufug.
 * @inp: ujnjj k,k,kg.
 * @data_shell: nnj,k,k jnjnne.
 *
 * Return: hhyuhnjhi jnjnk.
 */
char *replace_str(char *inp, shll_comm *data_shell)
{
	int oln, nln;
	r_var *hd, *i;
	char *stt, *nw_inp;

	stt = conv_itoa(data_shell->stt);
	hd = NULL;

	oln = verify_vars(&hd, inp, stt, data_shell);

	if (hd == NULL)
	{
		free(stt);
		return (inp);
	}

	i = hd;
	nln = 0;

	while (i != NULL)
	{
		nln += (i->len_val - i->len_var);
		i = i->next;
	}

	nln += oln;

	nw_inp = malloc(sizeof(char) * (nln + 1));
	nw_inp[nln] = '\0';

	nw_inp = rpl_inp(&hd, inp, nw_inp, nln);

	free(inp);
	free(stt);
	free_value_ls(&hd);

	return (nw_inp);
}

/**
 * _unsetenv - nnnnjuihnj kihnj:ljn  kjnkjnjnjnmb bknkknjk  nkbjnjjkne.
 * @datash: HHHN HBJJNJNJN JNKJNJNKN JNKNKNUHUB JJJNJN JHYUGTYCFV N.
 *
 * Return: MASO9AKCH BB.
 */
int _unsetenv(shll_comm *datash)
{
	int in, jn, kn;
	char **real_env;
	char *varnv, *nmnv;

	if (datash->args[1] == NULL)
	{
		get_err(datash, -1);
		return (1);
	}
	kn = -1;
	for (in = 0; datash->_env[in]; in++)
	{
		varnv = _strdup(datash->_env[in]);
		nmnv = _strtok(varnv, "=");
		if (_strcmp(nmenv, datash->args[1]) == 0)
		{
			kn = in;
		}
		free(varnv);
	}
	if (kn == -1)
	{
		get_err(datash, -1);
		return (1);
	}
	real_env = malloc(sizeof(char *) * (in));
	for (in = jn = 0; datash->_env[in]; in++)
	{
		if (in != kn)
		{
			real_env[jn] = datash->_env[in];
			jn++;
		}
	}
	real_env[jn] = NULL;
	free(datash->_env[kn]);
	free(datash->_env);
	datash->_env = real_env;
	return (1);
}

/**
 * set_env - ynjnj  jnjnjn jnjnkjnk jjnne.
 * @environ_name: bhbljnjknj jn jbilnl jn jbjnjn j.
 * @val: gvbjkkjb hbjkb;jhb hjbbjhb  hbjhj.
 * @data_sh: ghyulln uiiljkilj uojoijolijio ink,lkjioj jkniiljkn.
 * Return: maso9kech.
 */
void set_env(char *environ_name, char *val, shll_comm *data_sh)
{
	int in;
	char *varnv, *nmnv;

	for (in = 0; data_sh->_env[in]; in++)
	{
		varnv = _strdup(data_sh->_env[in]);
		nmnv = _strtok(varenv, "=");
		if (_strcmp(nmnv, environ_name) == 0)
		{
			free(data_sh->_env[in]);
			data_sh->_env[in] = cp_info(nmnv, val);
			free(varnv);
			return;
		}
		free(varnv);
	}

	data_sh->_env = _reallocdp(data_sh->_env, in, sizeof(char *) * (in + 2));
	data_sh->_env[in] = cp_info(environ_name, val);
	data_sh->_env[in + 1] = NULL;
}

/**
 * _setenv - cojdnjndjfnuifnfhbbbiijknnes
 * @data_sh: dHJHBJJBJJK NJNKJNH JKNJJNJHNKJN JNJNJN
 * Return: NJKJHYUJcKNJNJB
 */
int _setenv(shll_comm *data_sh)
{

	if (data_sh->args[1] == NULL || data_sh->args[2] == NULL)
	{
		get_err(data_sh, -1);
		return (1);
	}

	set_env(data_sh->args[1], data_sh->args[2], data_sh);

	return (1);
}

/**
 * cp_info - hddjdndbj dhdbjhndnbjhbdb nd jbjhdjd jbhddn jhdbhbhjd hdhhd jvdj.
 * @alias_name: hdbjbkdhjdlijl,jxinkldhDXjknlihhfnjdhuihx.
 * @val: bhxbdbhbdxbdyuyxdhbx yhxdhbhdxu xduhbubxds.
 *
 * Return: ,xninjnehwuihxeknwhxwkenxnxkjexhe.
 */
char *cp_info(char *alias_name, char *val)
{
	char *nw;
	int ln_name, ln_value, ln;

	ln_name = _strlen(alias_name);
	ln_value = _strlen(val);
	ln = ln_name + ln_value + 2;
	nw = malloc(sizeof(char) * (ln));
	_strcpy(nw, alias_name);
	_strcat(nw, "=");
	_strcat(nw, val);
	_strcat(nw, "\0");

	return (nw);
}
