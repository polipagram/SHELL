#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list{
  void *content;
  struct s_list *next;
  struct s_list *previous;
} t_list;

#endif
