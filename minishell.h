/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:15:13 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 02:38:25 by kbouarfa@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "mini_libft/libft.h"
typedef enum e_token
{
    PIPE,
    RED_IN,
    RED_OUT,
    HEREDOC,
    RED_APPEND,
    WORD
}t_token;

typedef struct s_shell
{
    char    *value;
    t_token kind;
    struct s_shell *next;
}t_shell;

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}t_env;

t_shell *lexer(char *input);
t_shell	*add_token(t_shell **head, const char *start, int len);
t_token	get_token_type(const char *str);
int	toklen(const char *s, int i);
int     fly_over_quotes(const char *str, int i);
int     is_op(const char *s);
void *env_to_list(t_env **head, char **env);
void clear_env(t_env **head);

#endif

