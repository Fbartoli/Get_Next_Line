/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:38:44 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/20 18:00:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest != '\0')
	{
		ft_strcpy(dest, s1);
	}
	return (dest);
}
