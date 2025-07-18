/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:31:41 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 17:33:10 by kbouarfa@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_tokens(t_shell *tokens)
// {
// 	while(tokens)
// 	{
// 		printf("value: %s --> and type: %d\n ", tokens->value, tokens->kind);
// 		tokens = tokens->next;
// 	}
// }

void	print_list(t_env *env)
{
	while(env)
	{
		printf("key : %s and value : %s\n", env->key,env->value);
		env = env->next;
	}
}

int		check_quote(char *input)
{
	int i;
	char quote;

	i = 0;
	while(input[i])
	{
		if(input[i] == '\'' || input[i] == '"')
		{
				quote = input[i];
				i++;
		}
		i++;
		if(input[i] && quote)
			return(1);
	}
	return(0);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_shell	*tokens;
	t_env	*vars;

  (void)av;
  (void)ac;
  vars = NULL;
//   copy_env(&env);
	env_to_list(&vars, env);
	print_list(vars);
	while (1)
	{
    	input = readline("minishell$> ");
    	if (!input)
		      break;
		tokens = lexer(input);
		//   expander(input);
		print_tokens(tokens);
		free(input);
	}
	return (0);
}
