#include "main.h"

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	shll_comm datash;
	(void)argc;

	signal(SIGINT, get_sigint);
	set_dtshll(&datash, argv);
	loopshll(&datash);
	empty_dt(&datash);
	if (datash.stat < 0)
		return (255);
	return (datash.stat);
}
