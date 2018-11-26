/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:47:08 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/19 21:12:44 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while ((ft_is_space(s[start])))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while ((ft_is_space(s[len])) && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
