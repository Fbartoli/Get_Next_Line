/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:15 by fbartoli          #+#    #+#             */
/*   Updated: 2018/11/27 01:57:33 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int		get_next_line(int fd, char **line)
{
	static char		*save;
	int				ret;
	char			*buf;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	while (buf[ret] != '\n')
		ret--;
	printf("buf, %s:'\n'", buf);
	*line = ft_strsub(buf, 0, ret);
	save = ft_strsub(buf, ret, BUFFER_SIZE - ret);
	printf("line, %s:'\n'", *line);
	printf("save, %s:'\n'", save);
	return (1);
	}

	int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));				// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	return (0);
}