/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:04:35 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/15 17:40:40 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;

	if (*needle == '\0')
		return ((char*)haystack);
	l = ft_strlen(needle);
	while (*haystack && len-- >= l)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, l) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
