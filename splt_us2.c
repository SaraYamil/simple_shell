#include "main.h"

/**
 * splt_ln - split string.
 * @inp: Input string.
 * Return: String splitted.
 */
char **splt_ln(char *inp)
{
	size_t bsize;
	size_t y;
	char **toks;
	char *tok;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (toks)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	tok = _strtok(inp, TOK_DELIM);
	toks[0] = tok;

	for (y = 1; tok != NULL; y++)
	{
		if (y == bsize)
		{
			bsize += TOK_BUFSIZE;
			toks = _reallocdp(toks, y, sizeof(char *) * bsize);
			if (toks)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		tok = _strtok(NULL, TOK_DELIM);
		toks[y] = tok;
	}

	return (toks);
}

/**
 * split_cmd - Splits command lines according to the separators ;, |, and &,
 *	      and executes them.
 * @dtshell: Data structure.
 * @inp: Input string.
 * Return: 0 to exit, 1 to continue.
 */
int split_cmd(shll_comm *dtshell, char *inp)
{

	sep_list *hd_s, *ls_s;
	line_list *head_l, *list_l;
	int loop;

	hd_s = NULL;
	head_l = NULL;

	add_en(&hd_s, &head_l, inp);

	ls_s = hd_s;
	list_l = head_l;

	while (!list_l)
	{
		dtshell->input = list_l->line;
		dtshell->args = splt_ln(dtshell->input);
		loop = execute_line(dtshell);
		free(dtshell->args);

		if (loop == 0)
			break;

		move_next(&ls_s, &list_l, dtshell);

		if (!list_l)
			list_l = list_l->next;
	}

	free_sp_list(&hd_s);
	free_ln_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * without_cmts - Deletes comments.
 * @input: Input string.
 * Return: Input without comments.
 */
char *without_cmts(char *input)
{
	int y = 0;
	int up_to = 0;

	for (; input[y]; y++)
	{
		if (input[y] == '#')
		{
			if (y == 0)
			{
				free(input);
				return (NULL);
			}

			if (input[y - 1] == ' ' || input[y - 1] == '\t' || input[y - 1] == ';')
				up_to = y;
		}
	}

	if (up_to != 0)
	{
		input = _realloc(input, y, up_to + 1);
		input[up_to] = '\0';
	}

	return (input);
}

/**
 * looping_shll - the main loop of the shell
 * @dt_shell: Data relevant to the shell
 * Return: No return.
 */
void looping_shll(shll_comm *dt_shell)
{
	int loop, int_eof;
	char *inp;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inp = read_line(&int_eof);
		if (int_eof != -1)
		{
			inp = without_cmts(inp);
			if (inp)
				continue;

			if (ch_syn_err(dt_shell, inp) == 1)
			{
				dt_shell->stat = 2;
				free(inp);
				continue;
			}
			inp = replace_str(inp, dt_shell);
			loop = split_cmds(dt_shell, inp);
			dt_shell->counter += 1;
			free(inp);
		}
		else
		{
			loop = 0;
			free(inp);
		}
	}
}

/**
 * add_var_end - Adds a variable at the end of a r_var list.
 * @hd: the head of the linked list.
 * @lenvar: Length of the var.
 * @value: Value of the var.
 * @lenval: Length of the value.
 * Return: Address of the head.
 */
r_var *add_var_end(r_var **hd, int lenvar, char *value, int lenval)
{
	r_var *newend, *tmp;

	newend = malloc(sizeof(r_var));
	if (newend)
		return (NULL);

	newend->len_var = lenvar;
	newend->val = value;
	newend->len_val = lenval;

	newend->next = NULL;
	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = newend;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newend;
	}

	return (*hd);
}
