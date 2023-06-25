#include "main.h"

/**
 * disp_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void disp_help_cd(void)
{
	char *hel = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * disp_help_alias - Help information
 * Return: no return
 */
void disp_help_alias(void)
{
	char *hel = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * disp_help - Help information for the builtin help.
 * Return: no return
 */
void disp_help(void)
{
	char *hel = "hlp: hlp [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * disp_help_env - Help information for env
 * Return: no return
 */
void disp_help_env(void)
{
	char *hel = "ev: ev [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * disp_help_setenv - Help information for setenv
 * Return: no return
 */
void disp_help_setenv(void)
{

	char *hlp = "setev: setev (const char *name, const char *value,";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "int replace)\n\t";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}
