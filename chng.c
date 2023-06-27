#include "main.h"

/**
 * changedir_shell - switch the curr directory.
 * @data_sh: data shell
 *
 * Return: 1 or 0.
 */
int changedir_shell(shll_comm *data_sh)
{
	int inh1, inh2, isd;
	char *directory = data_sh->args[1];

	if (directory != NULL)
	{
		inh1 = _strcmp("$HOME", directory);
		inh2 = _strcmp("~", directory);
		isd = _strcmp("--", directory);
	}

	if (directory == NULL || !inh1 || !inh2 || !isd)
	{
		changedir_to_home(data_sh);
		return (1);
	}

	if (_strcmp("-", directory) == 0)
	{
		changedir_prev(data_sh);
		return (1);
	}

	if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
	{
		chandir_dor(data_sh);
		return (1);
	}

	cd_to_dist(data_sh);

	return (1);
}

/**
 * chandir_dor - switch to the parent dir.
 * @data_sh: Point data structure
 *
 * Return: void value.
 */
void chandir_dor(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *directory, *chp_printwd, *chp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	chp_printwd = _strdup(pwd);
	set_env("OLDPWD", chp_printwd, data_sh);
	directory = data_sh->args[1];
	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", chp_printwd, data_sh);
		free(chp_printwd);
		return;
	}
	if (_strcmp("/", chp_printwd) == 0)
	{
		free(chp_printwd);
		return;
	}
	chp_strtok_pwd = chp_printwd;
	rev_string(chp_strtok_pwd);
	chp_strtok_pwd = _strtok(chp_strtok_pwd, "/");
	if (chp_strtok_pwd != NULL)
	{
		chp_strtok_pwd = _strtok(NULL, "\0");

		if (chp_strtok_pwd != NULL)
			rev_string(chp_strtok_pwd);
	}
	if (chp_strtok_pwd != NULL)
	{
		chdir(chp_strtok_pwd);
		set_env("PWD", chp_strtok_pwd, data_sh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(chp_printwd);
}
/**
 * cd_to_dist - Changes to a directory specified by the user.
 * @data_sh: Pointer to the data structure containing
 *           the directories.
 *
 * Return: No return value.
 */
void cd_to_dist(shll_comm *data_sh)
{
	char printwd[PATH_MAX];
	char *directory, *cp_pwd, *cp_dir;

	getcwd(printwd, sizeof(printwd));

	directory = data_sh->args[1];
	if (chdir(directory) == -1)
	{
		get_err(data_sh, 2);
		return;
	}

	cp_pwd = _strdup(printwd);
	set_env("OLDPWD", cp_pwd, data_sh);

	cp_dir = _strdup(directory);
	set_env("PWD", cp_dir, data_sh);

	free(cp_pwd);
	free(cp_dir);

	data_sh->stat = 0;

	chdir(directory);
}

/**
 * changedir_prev - Changes to the previous directory.
 * @data_sh: Data relevant to the environment and
 *           directories.
 *
 * Return: No return value.
 */
void changedir_prev(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = get_environ("OLDPWD", data_sh->_env);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, data_sh);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, data_sh);
	else
		set_env("PWD", cp_oldpwd, data_sh);

	p_pwd = get_environ("PWD", data_sh->_env);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	data_sh->stat = 0;

	chdir(p_pwd);
}

/**
 * changedir_to_home - Changes to the home directory.
 * @data_sh: Data relevant to the environment.
 *
 * Return: No return value.
 */
void changedir_to_home(shll_comm *data_sh)
{
	char *print_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	print_pwd = _strdup(pwd);

	home = get_environ("HOME", data_sh->_env);

	if (home == NULL)
	{
		set_env("OLDPWD", print_pwd, data_sh);
		free(print_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_err(data_sh, 2);
		free(print_pwd);
		return;
	}

	set_env("OLDPWD", print_pwd, data_sh);
	set_env("PWD", home, data_sh);
	free(print_pwd);
	data_sh->stat = 0;
}
