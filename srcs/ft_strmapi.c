/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:03:08 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 20:28:19 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(fresh = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (fresh[i])
	{
		fresh[i] = (*f)(i, fresh[i]);
		i++;
	}
	return (fresh);
}
