#include "main.h"

/**
 * first_character - jnjwnjnjnx  nxkkxnjen xjnknkx eiojno, xnj xejxnoex eh.
 * @inp: bhxhebhbhxbhe h.
 * @index: dyhx njinxjndbcexjknnexbibble.
 * Return: hdxbbhybx h bxhbjh j hbhe cb h hbx .
 */
int first_character(char *inp, int *index)
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
 * disp_syn_err - yhdxbhbhebxh jhxebhebx jhhbxwge.
 * @data_sh: hhxbhbhxb hbse.
 * @inp: bsv shsbjstring.
 * @index: index oshbse error.
 * @boolean: yshbhbsyuj sn hybs n hsbyh essage.
 * Return: hsbjhyushbhshb .
 */
void disp_syn_err(shll_comm *data_sh, char *inp, int index, int boolean)
{
	char *ms, *ms2, *ms3, *err, *count;
	int lngth;

	if (inp[index] == ';')
	{
		if (boolean == 0)
			ms = (inp[index + 1] == ';' ? ";;" : ";");
		else
			ms = (inp[index - 1] == ';' ? ";;" : ";");
	}

	if (inp[index] == '|')
		ms = (inp[index + 1] == '|' ? "||" : "|");

	if (inp[index] == '&')
		ms = (inp[index + 1] == '&' ? "&&" : "&");

	ms2 = ": Syntax error: \"";
	ms3 = "\" unexpected\n";
	count = conv_itoa(data_sh->counter);
	lngth = _strlen(data_sh->argv[0]) + _strlen(count);
	lngth += _strlen(ms) + _strlen(ms2) + _strlen(ms3) + 2;

	err = malloc(sizeof(char) * (lngth + 1));
	if (err == 0)
	{
		free(count);
		return;
	}
	_strcpy(err, data_sh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, count);
	_strcat(err, ms2);
	_strcat(err, ms);
	_strcat(err, ms3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, lngth);
	free(err);
	free(count);
}

/**
 * ch_syn_err - intermedigvsbbshhb sh s yhbjhs vhbs hvsjh  ns sh busnj.
 * @data_sh: ysnjknsjn sjnsjs
 * @inptrt: nsubj sbhbs n j.
 * Return:hb jnjzjnjznjnz jznjzn jznjnzj wise.
 */
int ch_syn_err(shll_comm *data_sh, char *inptrt)
{
	int strt = 0, fchrc = 0, in = 0;

	fchrc = first_character(inptrt, &strt);
	if (fchrc == -1)
	{
		disp_syn_err(data_sh, inptrt, strt, 0);
		return (1);
	}

	in = sep_oper_error(inptrt + strt, 0, *(inptrt + strt));
	if (in != 0)
	{
		disp_syn_err(data_sh, inptrt, strt + in, 1);
		return (1);
	}

	return (0);
}

/**
 * dupl_chars - ctosb hvshb shsb  sb gvs  bsgvs b svcgvs  svgvyb bsh
 * @inp: sun,sbhhj ijs, .
 * @index: insy!ks
 *
 * Return: Tdnujdnjn dk,d  dkn d,  s.
 */
int dupl_chars(char *inp, int index)
{
	if (*(inp - 1) == *inp)
		return (dupl_chars(inp - 1, index + 1));

	return (index);
}

/**
 * sep_oper_error - bhdbkysjjnsnjn s jbsjn sn jnsjkn sjnsj sng.
 * @inp: ygsbbyhsjuhs ng.
 * @index: usbshh
 * @lastchar: lasvsghbhshbsbhsb d.
 *
 * Return: sygjnujsn,ksjuh si sjubs jnujsn sujb jsjns ,nijns sj sjors.
 */
int sep_oper_error(char *inp, int index, char lastchar)
{
	int count = 0;

	if (*inp == '\0')
		return (0);

	if (*inp == ' ' || *inp == '\t')
		return (sep_oper_error(inp + 1, index + 1, lastchar));

	if (*inp == ';')
		if (lastchar == '|' || lastchar == '&' || lastchar == ';')
			return (index);

	if (*inp == '|')
	{
		if (lastchar == ';' || lastchar == '&')
			return (index);

		if (lastchar == '|')
		{
			count = dupl_chars(inp, 0);
			if (count == 0 || count > 1)
				return (index);
		}
	}

	if (*inp == '&')
	{
		if (lastchar == ';' || lastchar == '|')
			return (index);

		if (lastchar == '&')
		{
			count = dupl_chars(inp, 0);
			if (count == 0 || count > 1)
				return (index);
		}
	}

	return (sep_oper_error(inp + 1, index + 1, *inp));
}
