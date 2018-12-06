/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:15 by fbartoli          #+#    #+#             */
/*   Updated: 2018/12/06 17:13:58 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

char	*read_line(char **save, char *buf, int fd)
{
	char	*tmp;
	int		ret;

	tmp = ft_strdup("");
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	*save = ft_strdup(tmp);
	ft_strdel(&buf);
	ft_strdel(&tmp);
	return (*save);
}

char	*parsing_save(char *save, char **line)
{
	int				i;

	i = 1;
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n' && save[i] != '\0')
			i++;
		if (!(*line = ft_strsub(save, 0, i)))
			return (NULL);
		if (!(save = ft_strsub(save, i + 1, ft_strlen(save))))
			return (NULL);
		return (save);
	}
	if(!ft_strchr(save, '\n'))
	{
		if (*save)
		{
			if(!(*line = ft_strdup(save)))
				return (NULL);
		}
		else
		{
			ft_strclr(*line);
		}
		ft_strclr(save);
		return (save);
	}
	return (save);
}
int		get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buf;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE + 1)) \
		|| read(fd, buf, 0) == -1)
		return (-1);
	if (!save)
	{
		if(!(save = read_line(&save, buf, fd)))
			return (-1);
	}
	if (!(save = parsing_save(save, line)))
		return (-1);
	if (ft_strlen(*line) > 1)
		return (1);
	return (0);
}

/*int			main(int ac, char **av)
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
}*/