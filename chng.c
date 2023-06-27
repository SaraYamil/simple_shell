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
		in1 = _strcmp("$HOME", directory);
		in2 = _strcmp("~", directory);
		isd = _strcmp("--", directory);
	}

	if (directory == NULL || !in1 || !in2 || !isd)
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
<<<<<<< HEAD
 * chndirdor - Changes to the parent directory.
 * @data_sh: Pointer to the data structure containing the
 *           environment variables.
=======
 * chandir_dor - Changes to the parent directory fhtt.
 * @data_sh: Point to the data struct containing the
 *           env var ofsh.
>>>>>>> 6aa4f2cfc9573993d976d0c9741337f802ae9651
 *
 * Return: none value.
 */
void chndirdor(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *directory, *chd_printwd, *chd_str_pwd;

	getcwd(pwd, sizeof(pwd));
	chd_printwd = _strdup(pwd);
	set_env("OLDPWD", chd_printwd, data_sh);
	directory = data_sh->args[1];
	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", chd_printwd, data_sh);
		free(chd_printwd);
		return;
	}
	if (_strcmp("/", chd_printwd) == 0)
	{
		free(chd_printwd);
		return;
	}
	chd_str_pwd = chd_printwd;
	rev_string(chd_str_pwd);
	chd_str_pwd = _strtok(chd_str_pwd, "/");
	if (chd_str_pwd != NULL)
	{
		chd_str_pwd = _strtok(NULL, "\0");

		if (chd_str_pwd != NULL)
			rev_string(chd_str_pwd);
	}
	if (chd_str_pwd != NULL)
	{
		chdir(chd_str_pwd);
		set_env("PWD", chd_str_pwd, data_sh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(chd_printwd);
}

/**
<<<<<<< HEAD
 * cdtdist - Changes to a directory specified by the user.
 * @data_sh: Pointer to the data structure containing
 *           the directories.
=======
 * cd_to_dist - Changes to a directory specified joh.
 * @data_sh: Point to the dt struct containing
 *           the dir yfkyhf.
>>>>>>> 6aa4f2cfc9573993d976d0c9741337f802ae9651
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
		get_err(data_sh, 2);
		return;
	}

	chd_pwd = _strdup(path);
	set_env("OLDPWD", chd_pwd, data_sh);

	chd_dir = _strdup(directory);
	set_env("PWD", chd_dir, data_sh);

	free(chd_pwd);
	free(chd_dir);

	data_sh->stat = 0;

	chdir(directory);
}

/**
<<<<<<< HEAD
 * chngdirprev - Changes to the previous directory.
 * @data_sh: Data relevant to the environment and
 *           directories.
=======
 * changedir_prev - switch to the pre dir.
 * @data_sh: Data relevant to the env and
 *           dire kjuh.
>>>>>>> 6aa4f2cfc9573993d976d0c9741337f802ae9651
 *
 * Return: void value.
 */
void chngeirprev(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *w_pwd, *w_oldpwd, *chd_pwd, *chd_oldpwd;

	getcwd(pwd, sizeof(pwd));
	chd_pwd = _strdup(pwd);

	w_oldpwd = get_environ("OLDPWD", data_sh->_env);

	if (w_oldpwd == NULL)
		chd_oldpwd = chd_pwd;
	else
		chd_oldpwd = _strdup(w_oldpwd);

	set_env("OLDPWD", chd_pwd, data_sh);

	if (chdir(chd_oldpwd) == -1)
		set_env("PWD", chd_pwd, data_sh);
	else
		set_env("PWD", chd_oldpwd, data_sh);

	w_pwd = get_environ("PWD", data_sh->_env);

	write(STDOUT_FILENO, w_pwd, _strlen(w_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(chd_pwd);
	if (w_oldpwd)
		free(chd_oldpwd);

	data_sh->stat = 0;

	chdir(w_pwd);
}

/**
<<<<<<< HEAD
 * chngdirthome - Changes to the home directory.
 * @data_sh: Data relevant to the environment.
=======
 * changedir_to_home - switch to dir.
 * @data_sh: Data shell.
>>>>>>> 6aa4f2cfc9573993d976d0c9741337f802ae9651
 *
 * Return: void value.
 */
void chngdirthome(shll_comm *data_sh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = get_environ("HOME", data_sh->_env);

	if (home)
	{
		set_env("OLDPWD", p_pwd, data_sh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_err(data_sh, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, data_sh);
	set_env("PWD", home, data_sh);
	free(p_pwd);
	data_sh->stat = 0;
}
