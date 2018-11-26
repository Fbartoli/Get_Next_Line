/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:58:20 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 18:27:57 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *string;

	if (!s)
		return (NULL);
	if (!(string = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ft_strncpy(string, &s[start], len);
	return (string);
}
