/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:32:04 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/15 12:05:39 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;
	int			count;
	char		ch;

	i = 0;
	d = dest;
	s = src;
	count = 0;
	ch = c;
	while (count != 1 && i < n)
	{
		d[i] = s[i];
		if (s[i] == ch)
			count++;
		i++;
	}
	if (count == 0)
	{
		return (NULL);
	}
	return (d + i);
}
