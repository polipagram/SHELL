#include "minishell.h"

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

t_shell *lexer(char *input)
{
    t_shell *list;
    int i;
    int len;

    i = 0;
    len = 0;
    while(input[i])
    {
       i = pass_space(input, i);
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