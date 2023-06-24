#include "main.h"

/**
 * dsp_hlp_general - Entry point for help information for help builint
 * Return: Void
 */
void dsp_hlp_general(void)
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
 * dsp_hlp_exit - Help information fot the builint exit
 * Return: Void
 */
void dsp_hlp_exit(void)
{
	char *hel = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * display_unsetev - Help information for the builtin unsetenv
 * Return: Void
 */
void display_unsetenv(void)
{
	char *hel = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @signal: Signal handler
 */
void get_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * get_line - assigns the line variable for get_line
 * @lineptr: Pointer to the line variable
 * @num: Pointer to the size of line variable
 * @buf: String that is being assigned to line
 * @size_buf: Size of the buffer
 * Return: void
 */
void get_line(char **lineptr, size_t *num, char *buf, size_t size_buf)
{

	if (*lineptr == NULL)
	{
		if (size_buf > BUFSIZE)
			*num = size_buf;

		else
			*num = BUFSIZE;
		*lineptr = buf;
	}
	else if (*num < size_buf)
	{
		if (size_buf > BUFSIZE)
			*num = size_buf;
		else
			*num = BUFSIZE;
		*lineptr = buf;
	}
	else
	{
		_strcpy(*lineptr, buf);
		free(buf);
	}
}
