#include "main.h"

/**
 * disp_help_general - Entry point for help info
 * Return: Void
 */
void disp_help_general(void)
{
	char *hel = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "These commands are defined internally.Type 'hlp' to see the list";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Type 'hlp name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "[dir]\nexit: exit [n]\n  ev: ev [option] [name=value] [command ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}
/**
 * disp_help_exit - Help information fot the builint exit
 * Return: Void
 */
void disp_help_exit(void)
{
	char *hel = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * display_unsetenv - Help information
 * Return: Void
 */
void display_unsetenv(void)
{
	char *hel = "unsetev: unsetev (const char *name)\n\t";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * get_sigint - Handle the crtl + c call
 * @sig: Signal hand
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * get_ln - assigns the line variable
 * @lnptr: Pointer to the line var
 * @num: Pointer to the size of line var
 * @buf: String that is being assigned to line
 * @size_b: Size of the buffer
 * Return: void
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
		*lineptr = buf;
	}
	else
	{
		_strcpy(*lnptr, buf);
		free(buf);
	}
}
