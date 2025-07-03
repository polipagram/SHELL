/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:42:35 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/12 22:21:38 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joi_str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joi_str = (char *)malloc(len1 + len2 + 1);
	if (!joi_str)
	{
		return (NULL);
	}
	ft_memcpy(joi_str, s1, len1);
	ft_memcpy(joi_str + len1, s2, len2);
	joi_str[len1 + len2] = '\0';
	return (joi_str);
}
