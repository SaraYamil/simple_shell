#include "main.h"

/**
 * move_next - Moves to the next command line.
 * @lis_s: Separator list.
 * @lis_l: line list.
 * @dt_shell: Data structure.
 * Return: No return value.
 */
void move_next(sep_list **lis_s, line_list **lis_l, shll_comm *dt_shell)
{
	int lop_sep;
	sep_list *lst_s;
	line_list *lst_l;


	lop_s = 1;
	lst_s = *lis_s;
	lst_l = *lis_l;

	while (lst_s != NULL && loop_s)
	{
		if (dt_shell->stat == 0)
		{
			if (lst_s->sep == '&' || lst_s->sep == ';')
				lop_sep = 0;
			if (lst_s->sep == '|')
				lst_l = lst_l->next, lst_s = lst_s->next;
		}
		else
		{
			if (lst_s->sep == '|' || lst_s->sep == ';')
				lop_sep = 0;
			if (lst_s->sep == '&')
				lst_l = lst_l->next, lst_s = lst_s->next;
		}
		if (lst_s != NULL && !lop_sep)
			lst_s = lst_s->next;
	}
	*lis_s = lst_s;
	*lis_l = lst_l;
}

/**
 * swp_character - Swaps '|' and '&' for non-printed characters
 * @inp: string input.
 * @boolean: Type of swap. If boolean is 0, swaps '|' and '&'
 *           for non-printed characters.
 * Return: Swapped string.
 */
char *swp_character(char *inp, int boolean)
{
	int y = 0;

	if (boolean == 0)
	{
		for (; inp[y]; y++)
		{
			if (inp[y] == '|')
			{
				if (inp[y + 1] != '|')
					inp[y] = 16;
				else
					y++;
			}

			if (inp[y] == '&')
			{
				if (inp[y + 1] != '&')
					inp[y] = 12;
				else
					y++;
			}
		}
	}
	else
	{
		for (; inp[y]; y++)
		{
			inp[y] = (inp[y] == 16 ? '|' : inp[y]);
			inp[y] = (inp[y] == 12 ? '&' : inp[y]);
		}
	}
	return (inp);
}

/**
 * add_en - Adds sep and cmd lines to the lists.
 * @hd_s: the head of the sep list.
 * @hd_l: the head of the cmd lines list.
 * @inp: Input string.
 * Return: No return value.
 */
void add_en(sep_list **hd_s, line_list **hd_l, char *inp)

{
	int y = 0;
	char *cmd_line;

	inp = swp_character(inp, 0);

	for (; inp[y]; y++)
	{
		if (inp[y] == ';')
			add_node_en(hd_s, inp[y]);

		if (inp[y] == '|' || inp[y] == '&')
		{
			add_node_en(hd_s, inp[y]);
			y++;
		}
	}

	cmd_line = _strtok(inp, ";|&");
	do {
		cmd_line = swp_character(cmd_line, 1);
		add_ln_nd_end(hd_l, cmd_line);
		cmd_line = _strtok(NULL, ";|&");
	} while (cmd_line != NULL);
}

/**
 * read_ln - Reads the input string.
 * @int_eof: Return value of the getline func.
 * Return: Input string.
 */
char *read_ln(int *int_eof)
{
	char *inp = NULL;
	size_t buffersize = 0;

	*int_eof = getline(&inp, &buffersize, stdin);

	return (inp);
}

/**
 * free_v_ls - Frees a r_var list.
 * @hd: the head of the linked list.
 * Return: No return.
 */
void free_v_ls(r_var **hd)
{
	r_var *tmp;
	r_var *current;

	if (!hd)
	{
		current = *hd;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*hd = NULL;
	}
}
