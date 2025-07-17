/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:13:52 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 02:38:25 by kbouarfa@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_op(const char *s)
{
	if (!ft_strncmp(s, ">>", 2) || !ft_strncmp(s, "<<", 2))
		return (2);
	if (*s == '|' || *s == '<' || *s == '>')
		return (1);
	return (0);
}

int	fly_over_quotes(const char *str, int i)
{
	char	q;

	q = str[i];
	i++;
	while (str[i] && str[i] != q)
		i++;
	return (i);
}

int fly_over_space(char *s, int i)
{
    while(s[i] && ft_isspace(s[i]))
      i++;
    return(i);
}

int	add_op(t_shell **lst, char *s, int i)
{
	int	len = is_op(s + i);

	if (len)
		add_token(lst, &s[i], len);
	return (i + len);
}

t_shell *lexer(char *input)
{
    t_shell *list;
    int i;
    int len;

    i = 0;
    len = 0;
    while(input[i])
    {
       i = fly_over_space(input, i);
        if(!input[i])
            break;
        if(is_op(&input[i]))
            i = add_op(&list, &input[i], len);
        else
		{
			len = toklen(input, i);
			add_token(&list, &input[i], len);
			i += len;
		}
    }
    return (list);
}
