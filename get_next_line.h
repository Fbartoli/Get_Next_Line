/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartoli <fbartoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:51:00 by fbartoli          #+#    #+#             */
/*   Updated: 2018/12/10 21:12:48 by fbartoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256
# include "libft.h"
# include <stdio.h>

char	*read_line(char	**save, char *buf, int fd);
char	*parsing_save(char *save, char **line);
int		get_next_line(int fd, char **line);

#endif
