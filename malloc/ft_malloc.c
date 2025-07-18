#include "ft_malloc.h"


t_list *ft_global(t_list *ptr, int flag)
{
  static t_list *env;
  static t_list *something;

  if (ptr && flag == 1)
    env = ptr;
  else if (ptr && flag == 2)
      something = ptr;
  if (flag == 1)
    return (env);
  return (something);
}

void *ft_malloc(size_t size, int flag)
{
  void *ptr;
  t_list  *head;

  ptr = malloc(size);
  if (!ptr)
    return (perror("minishell"), ft_clean_up(), NULL);
  head = ft_global(NULL, flag);
  ft_lstadd_back(&head, ft_lstnew(ptr));
  ft_global(head, flag);
  return (ptr);
}
