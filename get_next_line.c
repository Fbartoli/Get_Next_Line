/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:15 by fbartoli          #+#    #+#             */
/*   Updated: 2018/12/11 18:45:48 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				res;
	static t_lst	*start;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0 || fd < 0 || !line || BUFF_SIZE < 1)
			return (-1);
		buf[ret] = '\0';
		if ((res = check_extra(fd, buf, &start)) == 1)
		{
			*line = get_extra(fd, &start);
			return (1);
		}
		if (res == -1)
			return (-1);
	}
	if ((*line = get_extra(fd, &start)) != NULL)
		return (1);
	return (0);
}

char	*get_extra(int fd, t_lst **start)
{
	t_lst	*elem;
	char	*begin;
	char	*end;
	char	*tmp;

	elem = find_extra(fd, start);
	if (elem->left == NULL)
		return (NULL);
	if ((end = ft_strstr((char *)elem->left, "\n")) != NULL)
	{
		if (!(begin = ft_strsub((char *)elem->left, 0,
						(elem->left_size - ft_strlen(++end) - 2))))
			return (NULL);
		tmp = elem->left;
		elem->left = (ft_strlen(end) == 0) ? NULL : (void *)ft_strdup(end);
		elem->left_size = ft_strlen(end) + 1;
		free(tmp);
	}
	else
	{
		if (!(begin = ft_strdup((char *)elem->left)))
			return (NULL);
		free(elem->left);
		elem->left = NULL;
		elem->left_size = 0;
	}
	return (begin);
}

t_lst	*find_extra(int fd, t_lst **start)
{
	t_lst	*tmp;

	tmp = *start;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	return (tmp);
}

int		check_extra(int fd, char *buf, t_lst **start)
{
	t_lst	*elem;
	char	*tmp;

	elem = find_extra(fd, start);
	if (elem == NULL)
	{
		if (!(elem = (t_lst *)ft_lstnew((void *)buf, (ft_strlen(buf) + 1))))
			return (-1);
		elem->fd = fd;
		ft_lstadd((t_list **)start, (t_list *)elem);
	}
	else
	{
		if (!(tmp = ft_strjoin((char *)elem->left, buf)))
			return (-1);
		free(elem->left);
		elem->left = (void *)tmp;
		elem->left_size = ft_strlen(tmp) + 1;
	}
	if (ft_strstr((char *)elem->left, "\n") != NULL)
		return (1);
	return (0);
}
