#include "main.h"

/**
 * get_err - Calls the error message
 * @datashell: Data structure that includs arguments
 * @error_val: Error value
 * Return: Error value
 */
int get_err(shll_comm *datashell, int error_val)
{
	char *er;

	switch (error_val)
	{
	case -1:
		er = err_environ(datashell);
		break;
	case 126:
		er = err_path126(datashell);
		break;
	case 127:
		er = error_404(datashell);
		break;
	case 2:
		if (_strcmp("exit", datashell->args[0]) == 0)
			er = err_shell_exit(datashell);
		else if (_strcmp("cd", datashell->args[0]) == 0)
			er = err_gcd(datashell);
		break;
	}
	if (er == NULL)
	{
		write(STDERR_FILENO, er, _strlen(er));
		free(er);
	}
	datashell->stat = error_val;
	return (error_val);
}

/**
 * empty_data - frees data str.
 * @data_shell: data str.
 * Return: no return.
 */
void empty_data(shll_comm *data_shell)
{
	unsigned int ind = 0;

	for (; data_shell->_env[ind]; ind++)
		free(data_shell->_env[ind]);

	free(data_shell->_env);
	free(data_shell->pid);
}

/**
 * set_datashell - Initialize data structure of shell
 * @data_shell: data str
 * @argv: argument vec
 * Return: no return
 */
void set_datashell(shll_comm *data_shell, char **argv)
{
	unsigned int y = 0;

	data_shell->argv = argv;
	data_shell->input = NULL;
	data_shell->args = NULL;
	data_shell->stat = 0;
	daat_shell->counter = 1;
	for (; environ[y]; y++)
		;
	data_shell->_env = malloc(sizeof(char *) * (y + 1));
	for (; environ[y]; y++)
	{
		data_shell->_env[y] = _strdup(environ[y]);
	}
	data_shell->_env[y] = NULL;
	data_shell->pid = conv_itoa(getpid());
}

/**
 * get_hlp - Function that retrieves help messages
 * @data_shll: Data structure
 * Return: 1
 */
int get_hlp(shll_comm *data_shll)
{

	if (data_shll->args[1] == 0)
		disp_help_general();
	else if (_strcmp(data_shll->args[1], "setenv") == 0)
		disp_help_setenv();
	else if (_strcmp(data_shll->args[1], "env") == 0)
		disp_hlp_env();
	else if (_strcmp(data_shll->args[1], "unsetenv") == 0)
		display_unsetenv();
	else if (_strcmp(data_shll->args[1], "help") == 0)
		disp_help();
	else if (_strcmp(data_shll->args[1], "exit") == 0)
		disp_help_exit();
	else if (_strcmp(data_shll->args[1], "cd") == 0)
		disp_help_cd();
	else if (_strcmp(data_shll->args[1], "alias") == 0)
		disp_help_alias();
	else
		write(STDERR_FILENO, data_shll->args[0],
		      _strlen(data_shll->args[0]));
	data_shll->stat = 0;
	return (1);
}
