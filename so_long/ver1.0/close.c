#include "so_long.h"

void	write_error(char *error)
{
	perror(error);
	exit(1);
}

int	window_close(void)
{
	exit(0);
}