/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:16:00 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 14:20:24 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char		*s;
	int			neg;
	long long	result;

	s = (char*)str;
	neg = 1;
	result = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
					|| *s == '\r' || *s == ' ')
		s++;
	neg = (*s == '-') ? -1 : 1;
	s = (*s == '+' || *s == '-') ? s + 1 : s;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + *s - 48;
		s++;
		if (result < 0 && neg == 1)
			return (-1);
		if (result < 0 && neg == -1)
			return (0);
	}
	return (result * neg);
}
