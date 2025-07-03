#include "minishell.h"
void    target(char c)
{
    if(c == '>' || c == '<' | c == '|' )
        return(1);
    return(0);
}
void    lexer(char *token)
{
    int i = 0;
    while(token[i])
    {
        while(ft_isspace(token[i]))
            i++;
        if(target(token[i]))
        {
            if(token[i+1] == ' ' || token[i + 1] == '>')
                printf("target found");
        }
        i++;
    }
}
int main()
{
    char *input;
    while(1337)
    {
        input = readline("minishell$ ");
        lexer(input);
    }
}
