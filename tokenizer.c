#include "minishell.h"
void    ft_syntax_quote(char c)
{
	ft_putstr_fd("minishel : sytax error unclosed", 2);
	ft_putchar_fd('c', 2);
	ft_putchar_fd('\n', 2);
}
void	pass_space(char *s, int *i)
{
	while(s[*i] == ft_isspace(s[*i]))
	(*i)++;
}
int     pass_quotes(char *input, int *i)
{
	char quote;

	if(input[*i] == '\'' || input[*i] == "\"")
		return(0);
	quote = input[*i];
	(*i)++;
	while(input[*i] != quote)
	{
		if(!input[*i])
			return(ft_syntax_quote(quote), -1);
		(*i)++;
	}
	return(0);
}
void	process_input(char *s, int *i)
{
	while(s[*i])
	{
		if(is_op())
	}
}
void lexer(char *input)
{
	int i;

	while(input[i])
	{
		pass_space(input, &i);
		if(pass_quotes(input, &i) == -1)
			exit(0);
		process_input(input, i);
	}
}
