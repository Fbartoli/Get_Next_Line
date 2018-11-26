/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:53:41 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/12 17:29:48 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1bis;
	const unsigned char *s2bis;

	s1bis = s1;
	s2bis = s2;
	while (n--)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		s1bis++;
		s2bis++;
	}
	return (0);
}
