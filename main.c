#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int fd;
	char **line;

	line = 0;
	fd = open(av[ac - 1], O_RDONLY);
	printf("%d \n", get_next_line(fd, line));
	return (0);
}