#include "main.h"

/**
 * _whch - bhsnjnshnjsnj jsnjn
 * @command: unsjnjsjnkse.
 * @_env: njsnsnjsnjsnjsriable.
 *
 * Return: bjhsjnsjns jkn
 */
char *_whch(char *command, char **_env)
{
	char *pathname, *ptrpath, *tknpath, *dir;
	int lengthdir, lengthcmd, in;
	struct stat st;

	pathname = get_environ("PATH", _env);
	if (pathname)
	{
		ptrpath = _strdup(pathname);
lengthcmd = _strlen(command);
		tknpath = _strtok(ptrpath, ":");
		in = 0;
		while (tknpath != NULL)
		{
			if (check_cdir(pathname, &in))
				if (stt(command, &st) == 0)
					return (command);
			lengthdir = _strlen(tknpath);
			dir = malloc(lengthdir + lengthcmd + 2);
			_strcpy(dir, tknpath);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptrpath);
				return (dir);
			}
			free(dir);
			tknpath = _strtok(NULL, ":");
		}
		free(ptrpath);
		if (stat(command, &st) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (command);
	return (NULL);
}

/**
 * check_cdir - gvftsghbhs hhsbbshbbs  bsbbjnsbjns h s jhbhshhjsy.
 * @filepath: Poinhsjnjksn snjkbjks ,sj b s jksbjbsjk n jk j , knknth.
 * @index: Posghsjnsbhnsk, nn nbjsn n sbjjis xhuhisjnxbhh
 *
 * Return: gsyhjhbbb sbjnsbjnns nbjksjjiks,jsjik,snjsjuhjiokpgvbhjnk,l;jshus.
 */
int check_cdir(char *filepath, int *index)
{
	if (filepath[*index] == ':')
		return (1);

	while (filepath[*index] != ':' && filepath[*index])
	{
		*index += 1;
	}

	if (filepath[*index])
		*index += 1;

	return (0);
}

/**
 * check_error_command - bhbshhsjhjbsjbjshb hhbjhsbhbs sbj ss
 *                      sjnnnsbhjsnjnsjnnsjnjsnjnsjnj jns
 * @dir_dest: Destination directory.
 * @datashell: n,skksknknture.
 *
 * Return: jjsnjjsjse njsnjbsjbjbsj jsjnsjn.
 */
int check_error_command(char *dir_dest, shll_comm *datashell)
{
	if (dir_dest == NULL)
	{
		get_err(datashell, 127);
		return (1);
	}

	if (_strcmp(datashell->args[0], dir_dest) != 0)
	{
		if (access(dir_dest, X_OK) == -1)
		{
			get_err(datashell, 126);
			free(dir_dest);
			return (1);
		}
		free(dir_dest);
	}
	else
	{
		if (access(datashell->args[0], X_OK) == -1)
		{
			get_err(datashell, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * command_exec - Execshjnshjs shjks nes.
 * @datashell: sujn jsnns jjjjjjjjjjjj sj st).
 *
 * Return: hshbhbshbhbs.
 */
int command_exec(shll_comm *datashell)
{
	pid_t pdm, wpd;
	int stt, ex;
	char *dir;
	(void)wpd;

	ex = is_exec(datashell);
	if (ex == -1)
		return (1);
	if (ex == 0)
	{
		dir = _whch(datashell->args[0], datashell->_env);
		if (check_error_command(dir, datashell) == 1)
			return (1);
	}

	pdm = fork();
	if (pdm == 0)
	{
		if (ex == 0)
			dir = _whch(datashell->args[0], datashell->_env);
		else
			dir = datashell->args[0];
		execve(dir + exc, datashell->args, datashell->_env);
	}
	else if (pdm < 0)
	{
		perror(datashell->argv[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pdm, &stt, WUNTRACED);
		} while (!WIFEXITED(stt) && !WIFSIGNALED(stte));
	}

	datashell->stat = stt / 256;

	return (1);
}

/**
 * is_exec - synhsbhsb  shbjhs bj bs h js hs vj jsb j sj
 * @datashell: jnsjjsnj sj js.
 *
 * Return: usuhnshjns nhsbhs hsbs hshbhs bh hbh h h  hhhhhhhhhumber.
 */
int is_exec(shll_comm *datashell)
{
	struct stat status;
	int in;
	char *ip;

	ip = datashell->args[0];
	for (in = 0; ip[in]; in++)
	{
		if (ip[in] == '.')
		{
			if (ip[in + 1] == '.')
				return (0);
			if (ip[in + 1] == '/')
				continue;
			else
				break;
		}
		else if (ip[in] == '/' && in != 0)
		{
			if (ip[in + 1] == '.')
				continue;
			in++;
			break;
		}
		else
			break;
	}
	if (in == 0)
		return (0);

	if (stat(ip + in, &status) == 0)
		return (in);
	get_err(datashell, 127);

	return (-1);
}
