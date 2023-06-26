#include "main.h"

/**
 * verify_env - hhhhhh hh  hh hyuhh njnjhjle ishh   jnjjnjjbrr variabhh.
 * @hd: hhh& bhg bhghg hggh hnjkk
 * @inp: jnjn jjnjnng.
 * @shell_data: Datb st,;:::fh.
 * Return: maso9kach hhhhhhhhh
 */
void verify_env(r_var **hd, char *inp, shll_comm *shell_data)
{
	int ln, chrc, in, lft_value;
	char **_env;

	_env = shell_data->_env;
	for (ln = 0; _env[ln]; ln++)
	{
		for (in = 1, chrc = 0; _env[ln][chrc]; chrc++)
		{
			if (_env[ln][chrc] == '=')
			{
				lft_value = _strlen(_env[ln] + chrc + 1);
				add_var_nd(hd, in, _env[ln] + chrc + 1, lft_value);
				return;
			}

			if (inp[in] == _env[ln][chrc])
				in++;
			else
				break;
		}
	}

	for (in = 0; inp[in]; in++)
	{
		if (inp[in] == ' ' || inp[in] == '\t' || inp[in] == ';' || inp[in] == '\n')
			break;
	}

	add_var_nd(hd, in, NULL, 0);
}

/**
 * rpl_inp - Replaces variaJLLL HHHHH HBHNBgg  hbbg.
 * @hd: Hjhhnj jnjn hygtcftrxx h
 * @inp: variab string
 * @new_inp: New inputhgg,kkk,ghujikdrft.
 * @numlen: input length
 * Return: maso9kch a zin hhhhhhhhhhh
 */
char *rpl_inp(r_var **hd, char *inp, char *new_inp, int numlen)
{
	r_var *i;
	int in, l, m;

	i = *hd;
	for (l = in = 0; in < numlen; in++)
	{
		if (inp[l] == '$')
		{
			if (!(i->len_var) && !(i->len_val))
			{
				new_inp[in] = inp[l];
				l++;
			}
			else if (i->len_var && !(i->len_val))
			{
				for (m = 0; m < i->len_var; m++)
					l++;
				in--;
			}
			else
			{
				for (m = 0; m < i->len_val; m++)
				{
					new_inp[in] = i->val[m];
					in++;
				}
				l += (i->len_var);
				in--;
			}
			i = i->next;
		}
		else
		{
			new_inp[in] = inp[l];
			l++;
		}
	}

	return (new_inp);
}

/**
 * verify_vars - Check if the tydbgvdgvgdvdggvdgvgdgv $?
 * @header: Head of;knd,djnudndjist.
 * @inp: Input string.
 * @str: Last stdjnjdsjndnnjshell.
 * @datashell: sata stru shbde.
 * Return: Numberdhbbbdhdbhbdjj processed.
 */
int verify_vars(r_var **header, char *inp, char *str, shll_comm *datashell)
{
	int in, lftst, lftpd;

	lftst = _strlen(str);
	lftpd = _strlen(datashell->pid);

	for (in = 0; inp[in]; in++)
	{
		if (inp[in] == '$')
		{
			if (inp[in + 1] == '?')
				add_var_nd(header, 2, str, lftst), in++;
			else if (inp[in + 1] == '$')
				add_var_nd(header, 2, datashell->pid, lftpd), in++;
			else if (inp[in + 1] == '\n')
				add_var_nd(header, 0, NULL, 0);
			else if (inp[in + 1] == '\0')
				add_var_nd(header, 0, NULL, 0);
			else if (inp[in + 1] == ' ')
				add_var_nd(header, 0, NULL, 0);
			else if (inp[in + 1] == '\t')
				add_var_nd(header, 0, NULL, 0);
			else if (inp[in + 1] == ';')
				add_var_nd(header, 0, NULL, 0);
			else
				verify_env(header, inp + in, datashell);
		}
	}

	return (in);
}

/**
 * compare_envname - JJJhhhhhhhhhb hhbhbbh hbhbnjjnj jOJUGF
 * @name_env: inpute ta3 fonction wa  variable.
 * @name_ptr: inpute ta3 comparw safe.
 * Return: maso9kach a zeen kimba dkhol a hbibae
 */
int compare_envname(const char *name_env, const char *name_ptr)
{
	int i;

	for (i = 0; name_env[i] != '='; i++)
	{
		if (name_env[i] != name_ptr[i])
		{
			return (0);
		}
	}

	return (i + 1);
}
