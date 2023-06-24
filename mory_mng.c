#include "main.h"

/**
 * add_line_nd_end - Adds a command line at the end of a line
 * @hd: the header of the linked list.
 * @cmd_line: Command line.
 * Return: Address of the header.
 */
line_list *add_line_nd_end(line_list **hd, char *cmd_line)
{
	line_list *new, *tmp;

	new = malloc(sizeof(line_list));
	if (nw == NULL)
		return (NULL);

	new->line = cmd_line;
	new->next = NULL;
	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*hd);
}

/**
 * free_ln_list - Free line_list.
 * @hd: the header of the linked list.
 * Return: No return.
 */
void free_ln_list(line_list **hd)
{
	line_list *tmp;
	line_list *current;

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

/**
 * add_nde_en - Adds a separator found at the end of a sep_list.
 * @hd: the head of the linked list.
 * @sp: Separator found (; | &).
 * Return: Address of the head.
 */
sep_list *add_nde_en(sep_list **hd, char sp)
{
	sep_list *new_sp, *tmp;

	new_sp = malloc(sizeof(sep_list));
	if (new_sp == NULL)
		return (NULL);

	new_sp->sep = sp;
	new_sp->next = NULL;
	tmp = *hd;

	if (tmp)
	{
		*hd = new_sp;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_sp;
	}

	return (*hd);
}

/**
 * free_sp_list - Free a sep_list.
 * @hd: the header of the linked list.
 * Return: No return.
 */
void free_sp_list(sep_list **hd)
{
	sep_list *tmp;
	sep_list *current;

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
