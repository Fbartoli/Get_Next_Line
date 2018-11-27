/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:15 by fbartoli          #+#    #+#             */
/*   Updated: 2018/11/27 19:23:48 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

char	*read_line(char *save, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	tmp = strdup("");
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	save = ft_strdup(tmp);
	return (save);
}

int		get_next_line(int fd, char **line)
{
	static char		*save;
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	i = 1;
	if (!save)
		save = read_line(save, fd);
	//printf("save sortie read: %s\n", save);
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n' && save[i] != '\0')
			i++;
		*line = ft_strsub(save, 0, i);
		save = ft_strsub(save, i, ft_strlen(save));
	}
	if(!ft_strchr(save, '\n'))
	{
		*line = ft_strdup(save);
		save[0] = '\0';
	}
	//printf("i : %d '\n", i);
	//printf("save sortie sub : %s\n", save);
	//printf("line : %s\n", *line);
	if (ft_strlen(save) > 1)
		return (1);
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
		write(fd, line, strlen(line));				// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal						// vous inquietez pas
	}
	close(fd);
	return (0);
}