/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:15:56 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 16:47:33 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *string;

	if (!s1 || !s2)
		return (NULL);
	if (!(string = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcpy(&string[ft_strlen(s1)], s2);
	return (string);
}
