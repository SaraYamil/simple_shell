#include "main.h"

/**
 * disp_hlpcd - Help information for the builtin alias.
 *
 * Return: no return
 */
void disp_hlpcd(void)
{
	char *hlp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * dsp_helpals - Help information for the builtin alias.
 *
 * Return: no return
 */
void dsp_helpals(void)
{
	char *hlp = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * dsp_hlp - Help information for the builtin help.
 *
 * Return: no return
 */
void dsp_hlp(void)
{
	char *hlp = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * dsp_hlpenv - Help information for the builtin env
 *
 * Return: no return
 */
void dsp_hlpenv(void)
{
	char *hlp = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * dsp_helpstnv - Help information for the builtin setenv
 *
 * Return: no return
 */
void dsp_helpstnv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
