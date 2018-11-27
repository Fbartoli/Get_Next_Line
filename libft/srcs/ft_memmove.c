/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:53:50 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/12 16:23:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	while (len--)
	{
		if (!(dst <= src + len && dst >= src))
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		if (dst <= src + len && dst >= src)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	return (dst);
}
