/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:53:26 by flbartol          #+#    #+#             */
/*   Updated: 2018/11/25 19:50:23 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset1(void *b, int c, size_t len)
{
	while (len--)
		*(((unsigned char*)b) + len) = (unsigned char)c;
	return (b);
}
