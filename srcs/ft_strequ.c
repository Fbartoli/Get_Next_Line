/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:16:59 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 15:56:48 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	n;

	if (!s1 || !s2)
		return (0);
	n = (ft_strlen(s1) >= ft_strlen(s2)) ? ft_strlen(s1) : ft_strlen(s2);
	if (ft_memcmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
