/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:34:52 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 20:27:57 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		fresh[i] = (*f)(fresh[i]);
		i++;
	}
	return (fresh);
}
