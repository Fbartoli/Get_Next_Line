/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:15 by fbartoli          #+#    #+#             */
/*   Updated: 2018/11/27 02:50:19 by fbartoli         ###   ########.fr       */
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
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	tmp = ft_strdup(buf);
	while (buf[ret] != '\n')
			ret--;
	buf[ret] = '\0';
	*line = ft_strsub(buf, 0, ret);
	save = ft_strsub(tmp, ret, BUFF_SIZE);
	printf("buf, %s:'\n'", buf);
	printf("line, %s:'\n'", *line);
	printf("save, %s:'\n'", save);
	if (*save)
	{
		ft_bzero(save, ft_strlen(save));
		return (1);
	}
	return (0);
	}

	int	main(int argc, char ** argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		close(fd);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd, line, strlen(line));				// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	return (0);
}