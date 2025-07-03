/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <kbouarfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:41:36 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/15 02:51:22 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *str, char c)
{
	int	n_w;
	int	f;
	int	i;

	n_w = 0;
	f = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			f = 1;
		else if (f == 1)
		{
			f = 0;
			n_w++;
		}
		i++;
	}
	return (n_w);
}

static char	*ft_mministr(char const *s, int len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	makeup(char **result, char const *s, char c, int nbwords)
{
	int	i;
	int	len;
	int	index;

	i = 0;
	len = 0;
	index = 0;
	while (i < nbwords)
	{
		while (s[index] == c)
			index++;
		len = 0;
		while (s[index + len] && s[index + len] != c)
			len++;
		result[i] = ft_mministr(s + index, len);
		if (result[i] == NULL)
		{
			free_split(result);
			return (0);
		}
		index += len;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n_words;
	int		allok;

	if (!s)
		return (NULL);
	n_words = ft_words(s, c);
	result = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!result)
		return (NULL);
	allok = makeup(result, s, c, n_words);
	if (!allok)
		return (NULL);
	result[n_words] = 0;
	return (result);
}
