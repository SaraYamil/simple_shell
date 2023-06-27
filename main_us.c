#include "main.h"

/**
 * geterr - Calls the error message according to the
 *	   builtin, syntax, or permission
 * @datashell: Data structure that contains arguments
 * @error_val: Error value
 *
 * Return: Error value
 */
int geterr(shll_comm *datashell, int error_val)
{
	char *error;

	switch (error_val)
	{
	case -1:
		error = err_envrn(datashell);
		break;
	case 126:
		error = errpth126(datashell);
		break;
	case 127:
		error = err404(datashell);
		break;
	case 2:
		if (_strccmmpp("exit", datashell->args[0]) == 0)
			error = errshellex(datashell);
		else if (_strccmmpp("cd", datashell->args[0]) == 0)
			error = errgcd(datashell);
		break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlength(error));
		free(error);
	}
	datashell->stat = error_val;
	return (error_val);
}

/**
 * empty_dt - frees data structure.
 * @data_shell: data structure.
 *
 * Return: no return.
 */
void empty_dt(shll_comm *data_shell)
{
	unsigned int index;

	for (index = 0; data_shell->_env[index]; index++)
		free(data_shell->_env[index]);

	free(data_shell->_env);
	free(data_shell->pid);
}

/**
 * set_dtshll - Initialize data structure
 * @data_shell: data structure
 * @argv: argument vector
 *
 * Return: no return
 */
void set_dtshll(shll_comm *data_shell, char **argv)
{
	unsigned int i;

	data_shell->argv = argv;
	data_shell->input = NULL;
	data_shell->args = NULL;
	data_shell->stat = 0;
	data_shell->counter = 1;
	for (i = 0; environ[i]; i++)
		;
	data_shell->_env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
	{
		data_shell->_env[i] = _strdupp(environ[i]);
	}
	data_shell->_env[i] = NULL;
	data_shell->pid = convitoa(getpid());
}

/**
 * gethelp - Function that retrieves help messages
 *	   according to built-in command
 * @data_shll: Data structure (args and input)
 *
 * Return: 1
 */
int gethelp(shll_comm *data_shll)
{

	if (data_shll->args[1] == 0)
		dsp_helpgnrl();
	else if (_strccmmpp(data_shll->args[1], "setenv") == 0)
		dsp_helpstnv();
	else if (_strccmmpp(data_shll->args[1], "env") == 0)
		dsp_hlpenv();
	else if (_strccmmpp(data_shll->args[1], "unsetenv") == 0)
		dsp_unstnv();
	else if (_strccmmpp(data_shll->args[1], "help") == 0)
		dsp_hlp();
	else if (_strccmmpp(data_shll->args[1], "exit") == 0)
		dsp_helpex();
	else if (_strccmmpp(data_shll->args[1], "cd") == 0)
		disp_help_cd();
	else if (_strccmmpp(data_shll->args[1], "alias") == 0)
		dsp_helpals();
	else
		write(STDERR_FILENO, data_shll->args[0],
		      _strlength(data_shll->args[0]));
	data_shll->stat = 0;
	return (1);
}

/**
 * getbltn - Retrieves the function pointer of the builtin command
 * @command: Command line
 *
 * Return: Function pointer of the builtin command
 */
int (*getbltn(char *command))(shll_comm *)
{
	builtin_t bltn[] = {
	    {"env", display_env},
	    {"exit", exit_sh},
	    {"setenv", _setenv},
	    {"unsetenv", _unsetenv},
	    {"cd", changedir_shell},
	    {"help", get_hlp},
	    {NULL, NULL}};
	int index;

	for (index = 0; bltn[index].commname; index++)
	{
		if (_strccmmpp(bltn[index].commname, command) == 0)
			break;
	}
	return (bltn[index].f);
}
