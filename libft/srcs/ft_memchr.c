/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:24:42 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/12 17:22:43 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sbis;
	char		cbis;

	sbis = s;
	cbis = c;
	while (n--)
	{
		if (*sbis == cbis)
			return ((void*)sbis);
		sbis++;
	}
	return (NULL);
}
