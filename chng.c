#include "main.h"

/**
<<<<<<< HEAD
 * chngdirshell - Changes the current directory.
 * @data_sh: Pointer to the data
=======
 * changedir_shell - switch the current dir.
 * @data_sh: data pointer
>>>>>>> 6aa4f2cfc9573993d976d0c9741337f802ae9651
 *
 * Return: 1 or 0.
 */
int chngdirshell(shll_comm *data_sh)
{
	int in1, in2, isd;
	char *directory = data_sh->args[1];

	if (!directory)
	{
		in1 = _strccmmpp("$HOME", directory);
		in2 = _strccmmpp("~", directory);
		isd = _strccmmpp("--", directory);
	}

	if (directory == NULL || !in1 || !in2 || !isd)
	{
		changedir_to_home(data_sh);
		return (1);
	}

	if (_strccmmpp("-", directory) == 0)
	{
		chngeirprev(data_sh);
		return (1);
	}

	if (_strccmmpp(".", directory) == 0 || _strcmp("..", directory) == 0)
	{
		chndirdor(data_sh);
		return (1);
	}

	cdtdist(data_sh);

	return (1);
}

/**
 * chndirdor - Changes to the parent directory.
 * @data_sh: Pointer to the data structure containing the
 *           environment variables.
 *
 * Return: none value.
 */
void chndirdor(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *directory, *chd_printwd, *chd_str_pwd;

	getcwd(pwd, sizeof(pwd));
	chd_printwd = _strdup(pwd);
	stenv("OLDPWD", chd_printwd, data_sh);
	directory = data_sh->args[1];
	if (_strccmmpp(".", directory) == 0)
	{
		set_env("PWD", chd_printwd, data_sh);
		free(chd_printwd);
		return;
	}
	if (_strccmmpp("/", chd_printwd) == 0)
	{
		free(chd_printwd);
		return;
	}
	chd_str_pwd = chd_printwd;
	rv_strng(chd_str_pwd);
	chd_str_pwd = _strtiktok(chd_str_pwd, "/");
	if (chd_str_pwd != NULL)
	{
		chd_str_pwd = _strtiktok(NULL, "\0");

		if (chd_str_pwd != NULL)
			rv_strng(chd_str_pwd);
	}
	if (chd_str_pwd != NULL)
	{
		chdir(chd_str_pwd);
		stenv("PWD", chd_str_pwd, data_sh);
	}
	else
	{
		chdir("/");
		stenv("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(chd_printwd);
}

/**
 * cdtdist - Changes to a directory specified by the user.
 * @data_sh: Pointer to the data structure containing
 *           the directories.
 *
 * Return: void value.
 */
void cdtdist(shll_comm *data_sh)
{
	char path[PATH_MAX];
	char *directory, *chd_pwd, *chd_dir;

	getcwd(path, sizeof(path));

	directory = data_sh->args[1];
	if (chdir(directory) == -1)
	{
		geterr(data_sh, 2);
		return;
	}

	chd_pwd = _strdupp(path);
	setenv("OLDPWD", chd_pwd, data_sh);

	chd_dir = _strdupp(directory);
	setenv("PWD", chd_dir, data_sh);

	free(chd_pwd);
	free(chd_dir);

	data_sh->stat = 0;

	chdir(directory);
}

/**
 * chngdirprev - Changes to the previous directory.
 * @data_sh: Data relevant to the environment and
 *           directories.
 *
 * Return: void value.
 */
void chngeirprev(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *w_pwd, *w_oldpwd, *chd_pwd, *chd_oldpwd;

	getcwd(pwd, sizeof(pwd));
	chd_pwd = _strdupp(pwd);

	w_oldpwd = getenvrn("OLDPWD", data_sh->_env);

	if (w_oldpwd == NULL)
		chd_oldpwd = chd_pwd;
	else
		chd_oldpwd = _strdupp(w_oldpwd);

	setenv("OLDPWD", chd_pwd, data_sh);

	if (chdir(chd_oldpwd) == -1)
		setenv("PWD", chd_pwd, data_sh);
	else
		setenv("PWD", chd_oldpwd, data_sh);

	w_pwd = getenvrn("PWD", data_sh->_env);

	write(STDOUT_FILENO, w_pwd, _strlength(w_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(chd_pwd);
	if (w_oldpwd)
		free(chd_oldpwd);

	data_sh->stat = 0;

	chdir(w_pwd);
}

/**
 * chngdirthome - Changes to the home directory.
 * @data_sh: Data relevant to the environment.
 *
 * Return: void value.
 */
void chngdirthome(shll_comm *data_sh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdupp(pwd);

	home = getenvrn("HOME", data_sh->_env);

	if (home)
	{
		setenv("OLDPWD", p_pwd, data_sh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		geterr(data_sh, 2);
		free(p_pwd);
		return;
	}

	setenv("OLDPWD", p_pwd, data_sh);
	setenv("PWD", home, data_sh);
	free(p_pwd);
	data_sh->stat = 0;
}
