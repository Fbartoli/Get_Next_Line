/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:51:39 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/15 17:56:34 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	l;
	size_t	l2;
	int		result;

	l = ft_strlen(s1) + 1;
	l2 = ft_strlen(s2) + 1;
	l = (l <= l2) ? l : l2;
	result = ft_memcmp(s1, s2, l);
	return (result);
}
