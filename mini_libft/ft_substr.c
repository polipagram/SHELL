/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:46:40 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/12 22:51:44 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;
	size_t	l;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s + start);
	if (l < len)
		len = l;
	i = 0;
	j = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j++] = s[i];
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	str[] = "flymetothemoon";vc       	
	  			

	printf("%s\n", ft_substr(str, 6, 9));
	return (0);
}

*/
