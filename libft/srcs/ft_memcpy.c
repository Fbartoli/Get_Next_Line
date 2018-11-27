/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:16:25 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/25 17:47:26 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy1(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	size_t			i;
	short int		*d;
	const short int	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n / 2)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_memcpy4(void *dest, const void *src, size_t n)
{
	size_t		i;
	int			*d;
	const int	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n / 4)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_memcpy8(void *dest, const void *src, size_t n)
{
	size_t				i;
	long long int		*d;
	const long long int	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n / 8)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n % 8 == 0)
		return (ft_memcpy8(dest, src, n));
	if (n % 4 == 0)
		return (ft_memcpy4(dest, src, n));
	if (n % 2 == 0)
		return (ft_memcpy2(dest, src, n));
	else
		return (ft_memcpy1(dest, src, n));
}
