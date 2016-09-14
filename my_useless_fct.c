/*
** my_useless_fct.c for my_useless_fct.c in /home/thirie_a/tech_1/CPE_2016_Pushswap/moulinette/pushswap
** 
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
** 
** Started on  Wed Apr 20 15:36:30 2016 jeremy thiriez
** Last update Wed Apr 20 15:59:19 2016 jeremy thiriez
*/

#include <unistd.h>
#include "pushswap.h"

int		my_two_swap_first_to_last(t_list **la, t_list **lb)
{
  t_list	*tmp1;
  t_list	*tmp2;

  tmp1 = *la;
  tmp2 = *lb;
  tmp1 = tmp1->next;
  tmp2 = tmp2->next;
  *la = tmp1;
  *lb = tmp2;
  write(1, "rr ", 3);
  return (1);
}

int		my_swap_last_to_first(t_list **list, char c)
{
  t_list	*tmp;

  tmp = *list;
  tmp = tmp->prev;
  *list = tmp;
  if (c == '0')
    write(1, "rra ", 4);
  else
    write(1, "rrb ", 4);
  return (1);
}

int		my_two_swap_last_to_first(t_list **la, t_list **lb)
{
  t_list	*tmp1;
  t_list	*tmp2;

  tmp1 = *la;
  tmp2 = *lb;
  tmp1 = tmp1->prev;
  tmp2 = tmp2->prev;
  *la = tmp1;
  *lb = tmp2;
  write(1, "rrr ", 4);
  return (1);
}

int		my_swap_two_first_elem(t_list **list, char c)
{
  t_list	*tmp;
  t_list	*temp;
  t_list	*last;

  tmp = *list;
  last = tmp->prev;
  temp = tmp->next;
  tmp->next = temp->next;
  temp->next->prev = tmp;
  tmp->prev = temp;
  temp->next = tmp;
  temp->prev = last;
  last->next = temp;
  *list = temp;
  if (c == '0')
    write(1, "sa ", 3);
  else
    write(1, "sb ", 3);
  return (1);
}

int		my_swap_first_to_last(t_list **list, char c)
{
  (*list) = (*list)->next;
  if (c == '0')
    write(1, "ra", 2);
  else
    {
      my_putchar(' ');
      write(1, "ra", 2);
    }
  return (1);
}
