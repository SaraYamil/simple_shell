#include "main.h"

/**
 * add_ln_nd_end - Adds a command line at the end the list
 * @hd: the header of the linked list.
 * @cmd_line: Command line.
 * Return: Address of the header.
 */
line_list *add_ln_nd_end(line_list **hd, char *cmd_line)
{
	line_list *new, *tp;

	new = malloc(sizeof(line_list));
	if (new)
		return (NULL);

	new->line = cmd_line;
	new->next = NULL;
	tp = *hd;

	if (tp)
	{
		*hd = new;
	}
	else
	{
		while (tp->next != NULL)
			tp = tp->next;
		tp->next = new;
	}

	return (*hd);
}

/**
 * free_line_ls - Free line_list.
 * @hd: the header of the linked list.
 * Return: No return.
 */
void free_line_ls(line_list **hd)
{
	line_list *tp;
	line_list *crt;

	if (!hd)
	{
		crt = *hd;
		while ((tp = crt) != NULL)
		{
			crt = crt->next;
			free(tp);
		}
		*hd = NULL;
	}
}

/**
 * add_node_en - Adds a separator found at the end of a list sep.
 * @hd: the head of the linked list.
 * @sp: Separator found.
 * Return: Address of the head.
 */
sep_list *add_node_en(sep_list **hd, char sp)
{
	sep_list *new_sp, *tp;

	new_sp = malloc(sizeof(sep_list));
	if (new_sp == NULL)
		return (NULL);

	new_sp->sep = sp;
	new_sp->next = NULL;
	tp = *hd;

	if (tp)
	{
		*hd = new_sp;
	}
	else
	{
		while (tp->next != NULL)
			tp = tp->next;
		tp->next = new_sp;
	}

	return (*hd);
}

/**
 * free_sp_ls - Free a sep list.
 * @hd: the header of the linked list.
 * Return: No return.
 */
void free_sp_ls(sep_list **hd)
{
	sep_list *tp;
	sep_list *crt;

	if (!hd)
	{
		crt = *hd;
		while ((tp = crt) != NULL)
		{
			crt = crt->next;
			free(tp);
		}
		*hd = NULL;
	}
}
