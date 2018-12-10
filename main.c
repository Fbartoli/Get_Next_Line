#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	fd = open(av[ac-1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		i++;
	}
	close(fd);
}
s
