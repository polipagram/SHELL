/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <kbouarfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:38:05 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/13 23:09:24 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
