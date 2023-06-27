#include "main.h"

/**
 * *replc_str - Calls functions to replace string into vars.
 * @inp: Input string.
 * @data_shell: Data structure.
 *
 * Return: Replaced string.
 */
char *replc_str(char *inp, shll_comm *data_shell)
{
	int olen, nlen;
	r_var *hd, *index;
	char *stat, *new_inp;

	stat = convitoa(data_shell->stat);
	hd = NULL;

	olen = verfyvrs(&hd, inp, stat, data_shell);

	if (hd == NULL)
	{
		free(stat);
		return (inp);
	}

	index = hd;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->len_val - index->len_var);
		index = index->next;
	}

	nlen += olen;

	new_inp = malloc(sizeof(char) * (nlen + 1));
	new_inp[nlen] = '\0';

	new_inp = rplinp(&hd, inp, new_inp, nlen);

	free(inp);
	free(stat);
	free_valls(&hd);

	return (new_inp);
}

/**
 * _unstnv - Deletes an environment variable with the specified name.
 * @datash: Data structure containing the environment variable name.
 *
 * Return: 1 on success.
 */
int _unstnv(shll_comm *datash)
{
	int i, j, k;
	char **real_env;
	char *varenv, *nmenv;

	if (datash->args[1] == NULL)
	{
		geterr(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_env[i]; i++)
	{
		varenv = _strdupp(datash->_env[i]);
		nmenv = _strtiktok(varenv, "=");
		if (_strccmmpp(nmenv, datash->args[1]) == 0)
		{
			k = i;
		}
		free(varenv);
	}
	if (k == -1)
	{
		geterr(datash, -1);
		return (1);
	}
	real_env = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_env[i]; i++)
	{
		if (i != k)
		{
			real_env[j] = datash->_env[i];
			j++;
		}
	}
	real_env[j] = NULL;
	free(datash->_env[k]);
	free(datash->_env);
	datash->_env = real_env;
	return (1);
}

/**
 * stenv - Sets an environment variable.
 * @environ_name: Name of the environment variable.
 * @val: Value of the environment variable.
 * @data_sh: Data structure containing the environment variables.
 *
 * Return: No return.
 */
void stenv(char *environ_name, char *val, shll_comm *data_sh)
{
	int i;
	char *varenv, *nmenv;

	for (i = 0; data_sh->_env[i]; i++)
	{
		varenv = _strdupp(data_sh->_env[i]);
		nmenv = _strtiktok(varenv, "=");
		if (_strccmmpp(nmenv, environ_name) == 0)
		{
			free(data_sh->_env[i]);
			data_sh->_env[i] = cpinf(nmenv, val);
			free(varenv);
			return;
		}
		free(varenv);
	}

	data_sh->_env = _reallcdp(data_sh->_env, i, sizeof(char *) * (i + 2));
	data_sh->_env[i] = cpinf(environ_name, val);
	data_sh->_env[i + 1] = NULL;
}

/**
 * _stnv - compares env variables names
 *           with the name passed.
 * @data_sh: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _stnv(shll_comm *data_sh)
{

	if (data_sh->args[1] == NULL || data_sh->args[2] == NULL)
	{
		geterr(data_sh, -1);
		return (1);
	}

	setenv(data_sh->args[1], data_sh->args[2], data_sh);

	return (1);
}

/**
 * cp_info - Copies information to create a new environment variable or alias.
 * @alias_name: Name of the environment variable or alias.
 * @val: Value of the environment variable or alias.
 *
 * Return: New environment variable or alias.
 */
char *cp_info(char *alias_name, char *val)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlength(alias_name);
	len_value = _strlength(val);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcopy(new, alias_name);
	_strcat(new, "=");
	_strccaat(new, val);
	_strccaat(new, "\0");

	return (new);
}
