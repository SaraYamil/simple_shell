#include "main.h"

/**
 * main - for testing 
 * @argc: inpute for main
 * @argv: inpute for main
 * Return: maso9kach 
 */
int main(int argc, char **argv)
{
	shll_comm datash;
	(void)argc;

	signal(SIGINT, get_sigint);
	set_datashell(&datash, argv);
	looping_shll(&datash);
	empty_data(&datash);
	if (datash.stat < 0)
		return (255);
	return (datash.stat);
}
