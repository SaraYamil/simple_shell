#include "main.h"

/**
 * changedir_shell -  hhgwa Changes a shell in other dir
 * @data_sh: hhhhhhhhhhh hhhhhhhh
 *
 * Return: maso9akch a zin
 */
int changedir_shell(shll_comm *data_sh)
{
	int inh, inh2, board;
	char *dir = data_sh->args[1];

	if (dir != NULL)
	{
		inh = _strcmp("$HOME", dir);
		inh2 = _strcmp("~", dir);
		board = _strcmp("--", dir);
	}

	if (dir == NULL || !inh || !inh2 || !board)
	{
		changedir_to_home(data_sh);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		changedir_prev(data_sh);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		chandir_dor(data_sh);
		return (1);
	}

	cd_to_dist(data_sh);

	return (1);
}

/**
 * chandir_dor - ccccccccccc ccccccccc ccccccccc
 * @data_sh: Ppppppppppppp ppppppppppppp pppppppppp pppp
 * Return: maso9akch kimba
 */
void chandir_dor(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_prntwd, *cp_s_p;

	getcwd(pwd, sizeof(pwd));
	cp_prntwd = _strdup(pwd);
	set_env("OLDPWD", cp_prntwd, data_sh);
	dir = data_sh->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cp_prntwd, data_sh);
		free(cp_prntwd);
		return;
	}
	if (_strcmp("/", cp_prntwd) == 0)
	{
		free(cp_prntwd);
		return;
	}
	cp_s_p = cp_prntwd;
	rev_string(cp_s_p);
	cp_s_p = _strtok(cp_s_p, "/");
	if (cp_s_p != NULL)
	{
		cp_s_p = _strtok(NULL, "\0");

		if (cp_s_p != NULL)
			rev_string(cp_s_p);
	}
	if (cp_s_p != NULL)
	{
		chdir(cp_s_p);
		set_env("PWD", cp_s_p, data_sh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(cp_prntwd);
}

/**
 * cd_to_dist - nnnnnnnnnnn nnnnnnnn nnnnnnnnnnn nnnnnnnn.
 * @data_sh: hhhhhhhhhhh bbbbbbbbbbb bbbbbbbbbb bbbbb
 * Return: maso9akch a zin dyali
 */
void cd_to_dist(shll_comm *data_sh)
{
	char prntwd[PATH_MAX];
	char *dir, *cp_pd, *cp_dr;

	getcwd(prntwd, sizeof(prntwd));

	dir = data_sh->args[1];
	if (chdir(dir) == -1)
	{
		get_err(data_sh, 2);
		return;
	}

	cp_pd = _strdup(prntwd);
	set_env("OLDPWD", cp_pd, data_sh);

	cp_dr = _strdup(dir);
	set_env("PWD", cp_dr, data_sh);

	free(cp_pd);
	free(cp_dr);

	data_sh->stat = 0;

	chdir(dir);
}

/**
 * changedir_prev - maso9aakch a zin dyali hadchi bayn
 * @data_sh: Data relhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh hhhh
 * Return: kimba dkhol soqk
 */
void changedir_prev(shll_comm *data_sh)
{
	char pwd[PATH_MAX];
	char *p_p, *p_oldpd, *cp_pd, *cp_oldpd;

	getcwd(pwd, sizeof(pwd));
	cp_pd = _strdup(pwd);

	p_oldpd = get_environ("OLDPWD", data_sh->_env);

	if (p_oldpd == NULL)
		cp_oldpd = cp_pd;
	else
		cp_oldpd = _strdup(p_oldpd);

	set_env("OLDPWD", cp_pd, data_sh);

	if (chdir(cp_oldpd) == -1)
		set_env("PWD", cp_pd, data_sh);
	else
		set_env("PWD", cp_oldpd, data_sh);

	p_p = get_environ("PWD", data_sh->_env);

	write(STDOUT_FILENO, p_p, _strlen(p_p));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pd);
	if (p_oldpd)
		free(cp_oldpd);

	data_sh->stat = 0;

	chdir(p_pd);
}

/**
 * changedir_to_home - hhhhhhhhhhh hhhhhhhh hhhhhh hhhh
 * @data_sh: Dahh hhhh bbb hhhh hhhhh bbbbb
 * Return: maso9akch a kimba
 */
void changedir_to_home(shll_comm *data_sh)
{
	char *print_p, *hm;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	print_p = _strdup(pwd);

	hm = get_environ("HOME", data_sh->_env);

	if (hm == NULL)
	{
		set_env("OLDPWD", print_p, data_sh);
		free(print_p);
		return;
	}

	if (chdir(hm) == -1)
	{
		get_err(data_sh, 2);
		free(print_p);
		return;
	}

	set_env("OLDPWD", print_p, data_sh);
	set_env("PWD", hm, data_sh);
	free(print_p);
	data_sh->stat = 0;
}
