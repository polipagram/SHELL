/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:31:41 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 02:38:25 by kbouarfa@st      ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	// char	*input;
	// t_shell	*tokens;
	t_env	*vars;

  (void)av;
  (void)ac;
  vars = NULL;
//   copy_env(&env);
	env_to_list(&vars, env);
	print_list(vars);
	// while (1)
	// {
    // 		input = readline("minishell$ ");
    // 		if (!input)
	// 		      break;
	// 	  tokens = lexer(input);
	// 	print_tokens(tokens);
	// 	free(input);
	// }
	return (0);
}
