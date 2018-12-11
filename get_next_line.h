/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:51:00 by fbartoli          #+#    #+#             */
/*   Updated: 2018/12/11 13:37:56 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256
# include "libft.h"
# include <stdio.h>

typedef struct		s_lst
{
	void			*left;
	size_t			left_size;
	struct s_lst	*next;
	int				fd;
}					t_lst;

int					get_next_line(int const fd, char **line);
int					check_extra(int fd, char *buf, t_lst **head);
t_lst				*find_extra(int fd, t_lst **head);
char				*get_extra(int fd, t_lst **head);

#endif
