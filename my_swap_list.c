/*
** my_swap_list.c for my_swap_list.c in /home/thirie_a/CPE_2016_Pushswap/pushswap
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Apr  5 16:04:58 2016 jeremy thiriez
** Last update Sun Apr 24 15:33:47 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

void		my_display_pa(t_struct *in)
{
  if (in->space == 0)
    {
      write(1, "pa", 2);
      in->space++;
    }
  else
    write(1, " pa", 3);
}

int		my_put_in_a(t_list **la, t_list **lb, t_struct *in)
{
  t_list	*tmp1;
  t_list	*lasta;

  tmp1 = *lb;
  *lb = (*lb)->next;
  if (*la == NULL)
    {
      tmp1->next = tmp1;
      tmp1->prev = tmp1;
      *la = tmp1;
    }
  else
    {
      lasta = (*la)->prev;
      tmp1->next = *la;
      (*la)->prev = tmp1;
      lasta->next = tmp1;
      tmp1->prev = lasta;
      *la = tmp1;
    }
  my_display_pa(in);
  return (1);
}

void		my_display_pb(t_struct *in)
{
  if (in->space == 0)
    {
      write(1, "pb", 2);
      in->space++;
    }
  else
    write(1, " pb", 3);
}

void		my_empty_la(t_list *tmp1, t_list *tmp2, t_list *last1, t_list **la)
{
  if (tmp1 == tmp2)
    *la = NULL;
  else
    {
      tmp2->prev = last1;
      last1->next = tmp2;
      *la = tmp2;
    }
}

int		my_put_in_b(t_list **la, t_list **lb, t_struct *in)
{
  t_list	*tmp1;
  t_list	*tmp2;
  t_list	*last1;

  tmp1 = *la;
  tmp2 = tmp1->next;
  last1 = (*la)->prev;
  if (*lb == NULL)
    {
      *lb = tmp1;
      (*lb)->next = NULL;
      (*lb)->prev = NULL;
    }
  else
    {
      tmp1->next = *lb;
      tmp1->prev = NULL;
      *lb = tmp1;
    }
  my_empty_la(tmp1, tmp2, last1, la);
  my_display_pb(in);
  return (1);
}
