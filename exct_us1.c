#include "main.h"

/**
 * _wch - Locates a command.
 * @command: Command name.
 * @_env: Environment variable.
 *
 * Return: Location of the command.
 */
char *_wch(char *command, char **_env)
{
	char *path_name, *ptrpath, *tkn_path, *directory;
	int length_dir, length_cmd, index;
	struct stat st;

	path_name = getenvrn("PATH", _env);
	if (path_name)
	{
		ptrpath = _strdupp(path_name);
		length_cmd = _strlength(command);
		tkn_path = _strtiktok(ptrpath, ":");
		index = 0;
		while (tkn_path != NULL)
		{
			if (chckcdir(path_name, &index))
				if (stat(command, &st) == 0)
					return (command);
			length_dir = _strlength(tkn_path);
			directory = malloc(length_dir + length_cmd + 2);
			_strcopy(directory, tkn_path);
			_strccaat(directory, "/");
			_strccaat(directory, command);
			_strccaat(directory, "\0");
			if (stat(directory, &st) == 0)
			{
				free(ptrpath);
				return (directory);
			}
			free(directory);
			tkn_path = _strtiktok(NULL, ":");
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
 * chckcdir - Checks if ":" is present in the current directory.
 * @filepath: Pointer to a character string representing the filepath.
 * @index: Pointer to an integer representing the index.
 *
 * Return: 1 if the path is searchable in the current directory, 0 otherwise.
 */
int chckcdir(char *filepath, int *index)
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
 * chck_errcommnd - Verifies if the user has permissions
 *                      to access a command or directory.
 * @dir_dest: Destination directory.
 * @datashell: Data structure.
 *
 * Return: 1 if there is an error, 0 if not.
 */
int chck_errcommnd(char *dir_dest, shll_comm *datashell)
{
	if (dir_dest == NULL)
	{
		geterr(datashell, 127);
		return (1);
	}

	if (_strccmmpp(datashell->args[0], dir_dest) != 0)
	{
		if (access(dir_dest, X_OK) == -1)
		{
			geterr(datashell, 126);
			free(dir_dest);
			return (1);
		}
		free(dir_dest);
	}
	else
	{
		if (access(datashell->args[0], X_OK) == -1)
		{
			geterr(datashell, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmmnd_ex - Executes command lines.
 * @datashell: Data relevant (args and input).
 *
 * Return: 1 on success.
 */
int cmmnd_ex(shll_comm *datashell)
{
	pid_t pidm, wpid;
	int stte, exc;
	char *dir;
	(void)wpid;

	exc = isexc(datashell);
	if (exc == -1)
		return (1);
	if (exc == 0)
	{
		dir = _wch(datashell->args[0], datashell->_env);
		if (chck_errcommnd(dir, datashell) == 1)
			return (1);
	}

	pidm = fork();
	if (pidm == 0)
	{
		if (exc == 0)
			dir = _wch(datashell->args[0], datashell->_env);
		else
			dir = datashell->args[0];
		execve(dir + exc, datashell->args, datashell->_env);
	}
	else if (pidm < 0)
	{
		perror(datashell->argv[0]);
		return (1);
	}
	else
	{
		do {
			wpid = waitpid(pidm, &stte, WUNTRACED);
		} while (!WIFEXITED(stte) && !WIFSIGNALED(stte));
	}

	datashell->stat = stte / 256;

	return (1);
}

/**
 * isexc - Determines if a command is an executable.
 * @datashell: Data structure.
 *
 * Return: 0 if it's not an executable, otherwise a positive number.
 */
int isexc(shll_comm *datashell)
{
	struct stat status;
	int index;
	char *inp;

	inp = datashell->args[0];
	for (index = 0; inp[index]; index++)
	{
		if (inp[index] == '.')
		{
			if (inp[index + 1] == '.')
				return (0);
			if (inp[index + 1] == '/')
				continue;
			else
				break;
		}
		else if (inp[index] == '/' && index != 0)
		{
			if (inp[index + 1] == '.')
				continue;
			index++;
			break;
		}
		else
			break;
	}
	if (index == 0)
		return (0);

	if (stat(inp + index, &status) == 0)
		return (index);
	geterr(datashell, 127);

	return (-1);
}
