/*
** my_sort_algo2.c for my_sort_algo.c in /home/thirie_a/CPE_2016_Pushswap/pushswap
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sat Apr  9 02:56:36 2016 jeremy thiriez
** Last update Sun Apr 24 17:56:44 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

int		my_check_sort(t_list *l_a)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp2 = l_a;
  tmp = l_a->prev;
  while (tmp2 != tmp)
    {
      if (tmp2->data > tmp2->next->data)
	return (0);
      tmp2 = tmp2->next;
    }
  return (1);
}

int		put_in_b_or_next(t_list **l_a, t_list **l_b, t_struct *in, int j)
{
  if ((((((*l_a)->data >> in->i) & 1) == j) && in->i < 31) ||
      (in->i == 31 && ((((*l_a)->data >> in->i) & 1) == 1)))
    {
      if (my_put_in_b(l_a, l_b, in) == 0)
	return (0);
    }
  else if (in->space == 0)
    {
      my_swap_first_to_last(l_a, '0');
      in->space = in->space + 1;
    }
  else
    my_swap_first_to_last(l_a, '1');
  return (1);
}

void		init_count(t_struct *in)
{
  in->space = 0;
  in->i = 0;
}

t_list		*my_sort_algo(t_list *l_a, t_list *l_b)
{
  t_struct	in;
  t_list	*tmp;

  init_count(&in);
  while (my_check_sort(l_a) != 1 && in.i < 32)
    {
      tmp = l_a->prev;
      while (l_a != tmp)
	if (put_in_b_or_next(&l_a, &l_b, &in, 0) == 0)
	  return (NULL);
      if (put_in_b_or_next(&l_a, &l_b, &in, 0) == 0)
	return (NULL);
      while (l_b)
	{
	  if (my_put_in_a(&l_a, &l_b, &in) == 0)
	    return (NULL);
	}
      in.i++;
    }
  return (l_a);
}
