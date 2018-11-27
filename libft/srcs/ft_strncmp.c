/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:43:39 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/15 17:58:42 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;
	size_t	l2;
	int		result;

	l = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l = (l <= l2) ? l + 1 : l2 + 1;
	l = (l <= n) ? l : n;
	result = ft_memcmp(s1, s2, l);
	return (result);
}
