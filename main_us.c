#include "main.h"

/**
 * get_err - Calls the error message
 * @dtshell: Data structure that contains arguments
 * @err_v: Error value
 * Return: Error value
 */
int get_err(shll_comm *dtshell, int err_v)
{
	char *err;

	switch (err_v)
	{
	case -1:
		err = err_environ(dtshell);
		break;
	case 126:
		err = err_path126(dtshell);
		break;
	case 127:
		err = error_404(dtshell);
		break;
	case 2:
		if (_strcmp("exit", dtshell->args[0]) == 0)
			err = err_shell_exit(dtshell);
		else if (_strcmp("cd", dtshell->args[0]) == 0)
			err = err_gcd(dtshell);
		break;
	}
	if (err == NULL)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}
	dtshell->stat = err_v;
	return (err_v);
}

/**
 * empty_dt - frees data structure.
 * @dt_shell: data structure.
 * Return: no return.
 */
void empty_dt(shll_comm *dt_shell)
{
	unsigned int ind = 0;

	for (; dt_shell->_env[ind]; ind++)
		free(dt_shell->_env[ind]);

	free(dt_shell->_env);
	free(dt_shell->pid);
}

/**
 * set_dtshell - Initialize data structure
 * @dt_shell: data structure
 * @argv: argument vector
 * Return: no return
 */
void set_dtshell(shll_comm *dt_shell, char **argv)
{
	unsigned int y = 0;

	dt_shell->argv = argv;
	dt_shell->input = NULL;
	dt_shell->args = NULL;
	dt_shell->stat = 0;
	dt_shell->counter = 1;
	for (; environ[y]; y++)
		;
	dt_shell->_env = malloc(sizeof(char *) * (y + 1));
	for (; environ[y]; y++)
	{
		dt_shell->_env[y] = _strdup(environ[y]);
	}
	dt_shell->_env[y] = NULL;
	dt_shell->pid = conv_itoa(getpid());
}

/**
 * get_help - Function that retrieves help messages
 * @data_shll: Data structure
 * Return: 1
 */
int get_help(shll_comm *data_shll)
{

	if (data_shll->args[1] == 0)
		dsp_hlp_general();
	else if (_strcmp(data_shll->args[1], "setenv") == 0)
		dsp_hlp_setenv();
	else if (_strcmp(data_shll->args[1], "env") == 0)
		dsp_hlp_env();
	else if (_strcmp(data_shll->args[1], "unsetenv") == 0)
		display_unsetenv();
	else if (_strcmp(data_shll->args[1], "help") == 0)
		dsp_hlp();
	else if (_strcmp(data_shll->args[1], "exit") == 0)
		dsp_hlp_exit();
	else if (_strcmp(data_shll->args[1], "cd") == 0)
		dsp_hlp_cd();
	else if (_strcmp(data_shll->args[1], "alias") == 0)
		dsp_hlp_alias();
	else
		write(STDERR_FILENO, data_shll->args[0],
		      _strlen(data_shll->args[0]));
	data_shll->stat = 0;
	return (1);
}

/**
 * get_blt - Retrieves the function pointer of the builtin command
 * @command: Command line
 * Return: Function pointer of the builtin
 */
int (*get_blt(char *command))(shll_comm *)
{
	builtin_t bltn[] = {
	    {"env", display_env},
	    {"exit", exit_sh},
	    {"setenv", _setenv},
	    {"unsetenv", _unsetenv},
	    {"cd", changedir_shell},
	    {"help", get_hlp},
	    {NULL, NULL}};
	int ind = 0;

	for (; blt[ind].commname; ind++)
	{
		if (_strcmp(blt[ind].commname, command) == 0)
			break;
	}
	return (blt[ind].f);
}
