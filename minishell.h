#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_token
{
    PIPE,
    RED_IN,
    RED_OUT,
    HERDOC,
    RED_APPEND,
    RED_ERR
}t_token;

typedef struct s_shell
{
    char    *token;
    t_token kind;
    struct s_shell  *next;
}t_shell;



#endif

