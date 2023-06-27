#include "main.h"

/**
<<<<<<< HEAD
 * disp_help_general - ggggggggggg gggggggggg gg gggggggggggg gggggggg ggggg
 *
 * Return: Vggg
=======
 * disp_help_general - display help builtin
 *
 * Return: nothing
>>>>>>> c9c3c29390012187b08c11d8f0032f67679d93f9
 */
void disp_help_general(void)
{
	char *hep = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hep, _strlen(hep));
}
/**
<<<<<<< HEAD
 * disp_help_exit - hhhhhhhhhhhhhhhhh hhhhhhhhhhh vavhbjt
 *
 * Return: Vddd
=======
 * disp_help_exit - display help builtin
 *
 * Return: nothing
>>>>>>> c9c3c29390012187b08c11d8f0032f67679d93f9
 */
void disp_help_exit(void)
{
	char *hep = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hep, _strlen(hep));
}

/**
<<<<<<< HEAD
 * display_unsetenv - ccccccccc cccbbbbb bbbbbbbbbb bbbbbbbbbbn
 *
 * Return: Vxxx
=======
 * display_unsetenv - display help builtin for the builtin unsetenv
 *
 * Return: nothing
>>>>>>> c9c3c29390012187b08c11d8f0032f67679d93f9
 */
void display_unsetenv(void)
{
	char *hep = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, hep, _strlen(hep));
	hep = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hep, _strlen(hep));
}

/**
<<<<<<< HEAD
 * get_sigint - xxxxxxxxxxx xxxxxxxx xxxxxxxxxxx x
 * @sig: xxxxxxxxxndler
=======
 * get_sigint - getukgu
 * @sig: iygiyki
>>>>>>> c9c3c29390012187b08c11d8f0032f67679d93f9
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
<<<<<<< HEAD
 * get_ln - zzzzzzzzz zzzzzz z zzzzzzzzzzzzze
 * @lnptr: Pzzzzzzzzzz zzzzzzzzzariable
 * @num: Poinzzzzzzzzz zzzzz of zzzzzzzzzzble
 * @buf: String thabbbbb bbbbbbbbbbbb bbbbbbbe
 * @size_b: gggggg ggggg bbbbr
 *
 * Return: vvvv
=======
 * get_ln - ewtet
 * @lnptr: erggvdsg
 * @num: ertgetee
 * @buf: 5yyyyyyy4
 * @size_b: 4yyheddd
 *
 * Return: nothing
>>>>>>> c9c3c29390012187b08c11d8f0032f67679d93f9
 */
void get_ln(char **lnptr, size_t *num, char *buf, size_t size_b)
{

	if (*lnptr == NULL)
	{
		if (size_b > BUFSIZE)
			*num = size_b;

		else
			*num = BUFSIZE;
		*lnptr = buf;
	}
	else if (*num < size_b)
	{
		if (size_b > BUFSIZE)
			*num = size_b;
		else
			*num = BUFSIZE;
		*lnptr = buf;
	}
	else
	{
		_strcpy(*lnptr, buf);
		free(buf);
	}
}
