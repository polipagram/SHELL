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

int	add_op(t_shell **lst, char *s, int i)
{
	int	len = is_op(s + i);

	if (len)
		add_token(lst, &s[i], len);
	return (i + len);
}


