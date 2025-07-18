#include "ft_malloc.h"

void ft_free(void *ptr, int flag)
{
  t_list *tmp;

  tmp = ft_global(NULL, flag);
  while (tmp->content != ptr)
    tmp = tmp->next;
  if (tmp->next)
  {
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
  }
  else
  {
    tmp->previous->next = NULL;
  }
  free(tmp->content);
  free(tmp);
}

void ft_free_all(t_list *ptr)
{
  t_list *tmp;
  
  tmp = ptr->next;
  while (ptr)
  {
    free(ptr->content);
    free(ptr);
    ptr = tmp;
    tmp = tmp->next;
  }
}

void  ft_clean_up(void)
{
  ft_free_all(ft_global(NULL, 1));
  ft_free_all(ft_global(NULL, 2));
}
