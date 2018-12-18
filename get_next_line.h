/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:51:00 by fbartoli          #+#    #+#             */
/*   Updated: 2018/12/12 14:03:14 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(int fd, char **line);

#endif
