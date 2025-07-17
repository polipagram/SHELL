/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:34:52 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 02:38:49 by kbouarfa@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	toklen(const char *s, int i)
{
	int	start;
    
    start = i;
	while (s[i] && !ft_isspace(s[i]) && !is_op(&s[i]))
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = fly_over_quotes(s, i);
		i++;
	}
	return (i - start);
}


t_token	get_token_type(const char *str)
{
	if (!ft_strncmp(str, "<", 1))
		return (RED_IN);
	if (!ft_strncmp(str, ">", 1))
		return (RED_OUT);
	if (!ft_strncmp(str, ">>", 2))
		return (RED_APPEND);
	if (!strcmp(str, "<<"))
		return (HEREDOC);
	return (WORD);
}

t_shell	*add_token(t_shell **head, const char *start, int len)
{
	t_shell	*new = malloc(sizeof(t_shell));
	t_shell	*tmp;

	if (!new)
		return (NULL);
	new->value = ft_substr(start, 0, len);
	new->kind = get_token_type(new->value);
	new->next = NULL;
	// new->previous = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		// new->previous = tmp;
	}
	return (new);
}
