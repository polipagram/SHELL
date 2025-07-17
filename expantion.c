/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa@student.1337.ma <kbouarfa>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:07:00 by kbouarfa          #+#    #+#             */
/*   Updated: 2025/07/17 02:39:53 by kbouarfa@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int   ft_tablen(char **table)
{
  int i;

  i = 0;
  while (table[i])
    i++;
  return (i);
}

static t_env *add_back_env(t_env **head, t_env *node)
{
  t_env *tmp;

  if (!head || !node)
    return (NULL);
  if(!*head)
    return (*head = node, node);
  tmp = *head;
  while(tmp->next)
  {
    tmp = tmp->next;
  }
  tmp->next = node;
  return(node);
}

static char  *get_key(char *str)
{
  int i;
  char *key;

  i = 0;
  while (str[i] != '=')
    i++;
  key = malloc(i + 1);
  if (!key)
    return (NULL);
  i = 0;
  while(str[i] != '=')
  {
    key[i] = str[i];
    i++;
  }
  key[i] = '\0';
  return (key);
}
// 10

// H O M E = / h o m e \0

// 0 1 2 3 4 5 6 7 8 9 10


static char *get_value(char *str)
{
  char *value;
  int i;

  i = ft_strlen(str);
  while (str[i] != '=')
    i--;
  value = malloc(ft_strlen(str) - i);
  if (!value)
    return(NULL);
  str += i + 1;
  i = 0;
  while (*str)
  {
    value[i] = *str;
    str++;
    i++;
  }
  value[i] = '\0';
  return (value);
}

static t_env *new_node_env(char *env)
{
  t_env *new;

  new = malloc(sizeof(t_env));
  if(!new)
    return NULL;
  new->key = get_key(env);
  new->value = get_value(env);
  new->next = NULL;
  return (new);
}

void clear_env(t_env **head)
{
  t_env *tmp;

  tmp = (*head)->next;
  while (tmp)
  {
    (*head) = (*head)->next;
    free(tmp);
    tmp = (*head);
  }
}

void *env_to_list(t_env **head, char **env)
{
  int i;

  i = 0;
  while (env[i])
  {
    if (!add_back_env(head, new_node_env(env[i])))
      return (clear_env(head), NULL);
    i++;
  }
  return ((void *)1);
}



// char  **cpy_env(char **env)
// {
//   int i;
//   char **dest;

//   dest = malloc(ft_tablelen(env) + 1);
//   if (!dest)
//     return (NULL);
//   i = 0;
//   while(env[i])
//   {
//     dest[i] = ft_strdup(env[i]);
//     if (!dest)
//       return (ft_free(table), NULL);
//     i++;
//   }
//   dest[i] = NULL;
//   return(dest);
// }
