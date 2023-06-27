#include "main.h"

/**
 * disp_help_general - display help builtin
 *
 * Return: nothing
 */
void disp_help_general(void)
{
	char *hlp = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}
/**
 * disp_help_exit - display help builtin
 *
 * Return: nothing
 */
void disp_help_exit(void)
{
	char *hlp = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * display_unsetenv - display help builtin for the builtin unsetenv
 *
 * Return: nothing
 */
void display_unsetenv(void)
{
	char *hlp = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * get_sigint - getukgu
 * @sig: iygiyki
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * get_ln - ewtet
 * @lnptr: erggvdsg
 * @num: ertgetee
 * @buf: 5yyyyy4
 * @size_b: 4yyheddd
 *
 * Return: nothing
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
