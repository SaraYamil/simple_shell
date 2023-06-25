#include "main.h"

/**
 * get_environ - hbhbh hbhbhbh hbhibjb jnknjknjn jnjnjnjk.
 * @envname: gvvhbyu vvuvbjhb hbbhbhb huhuhle.
 * @_env: hbbhb hbuinjnuj hbnnjn jnjnles.
 * Return: gtyfhbhvyu vuvyuyubhv yyugyugjhbyg ygiii yyyugable
 */
char *get_environ(const char *envname, char **_env)
{
	char *ptr_ev;
	int i, mv;

	/* Initializehuhuhuuhhun ne */
	ptr_ev = NULL;
	mv = 0;
	/* Compajn,k;hfrdftgyv ent;jgtfbvdes */
	/* htfdrfg gvbh gvbh crv gvtfrtgyuj njile */
	for (i = 0; _env[i]; i++)
	{
		/* edrfg vgbhj tfyv jnnnn jn */
		mv = compare_envname(_env[i], envname);
		if (mv)
		{
			ptr_ev = _env[i];
			break;
		}
	}

	return (ptr_ev + mv);
}

/**
 * display_env - frdfgvb cfgvbhjnk,l vbhjn,k vbnk,
 * @data_sh: rftghnj tgnj nrfgnj tgynjture condrsedrftthe
 * Return: drth drftgyhbhb hhhhhhhhhhhh 
 */
int display_env(shll_comm *data_sh)
{
	int k, n;

	for (k = 0; data_sh->_env[k]; k++)
	{

		for (n = 0; data_sh->_env[k][n]; n++)
			;

		write(STDOUT_FILENO, data_sh->_env[k], n);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_sh->stat = 0;

	return (1);
}

/**
 * _getline - efghbnj vvgbhnj vgbhjm
 * @lnptr: vgbhnjtvbhnj tun,i tgyui tbn, tgyhuji tfyut
 * @num: rtyu dtfvyuni xrctvbyun rctv
 * @filestream: xcgvbh yun xcvb crv
 *
 * Return: ftgy ctv ctvybuni t
 */
ssize_t _getline(char **lnptr, size_t *num, FILE *filestream)
{
	int i;
	static ssize_t ip;
	ssize_t rtval;
	char *buff;
	char t = 'z';

	if (ip == 0)
		fflush(filestream);
	else
		return (-1);
	ip = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && ip == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && ip != 0)
		{
			ip++;
			break;
		}
		if (ip >= BUFSIZE)
			buff = _realloc(buff, ip, ip + 1);
		buff[ip] = t;
		ip++;
	}
	buff[ip] = '\0';
	get_ln(lnptr, num, buff, ip);
	rtval = ip;
	if (i != 0)
		ip = 0;
	return (rtval);
}
