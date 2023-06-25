#include "main.h"
/**
 * dsp_hlp_cd - Help information for the builtin alias.
 * Return: no return
 */
void dsp_hlp_cd(void)
{
	char *hel = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * dsp_hlp_alias - Help information for the builtin alias.
 * Return: no return
 */
void dsp_hlp_alias(void)
{
	char *hel = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * dsp_hlp - Help information for the builtin help.
 * Return: no return
 */
void dsp_hlp(void)
{
	char *hel = "hlp: hlp [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * dsp_hlp_env - Help information for the builtin env
 * Return: no return
 */
void dsp_hlp_env(void)
{
	char *hel = "env: nev [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, hel, _strlen(hel));
	hel = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hel, _strlen(hel));
}

/**
 * dsp_hlp_setev - Help information for the builtin setenv
 *
 * Return: no return
 */

void dsp_hlp_setenv(void)
{

	char *hlp = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "int replace)\n\t";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}
