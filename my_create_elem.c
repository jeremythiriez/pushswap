/*
** my_create_elem.c for my_create_elem.c in /home/thirie_a/CPE_2016_Pushswap
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Apr  5 12:02:04 2016 jeremy thiriez
** Last update Sun Apr 24 23:19:19 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

int		my_print_list(t_list *list)
{
  t_list	*temp;

  if (list)
    {
      if (list->next == NULL)
	{
	  my_put_nbr(list->data);
	  return (0);
	}
      temp = list->prev;
      while (list != temp)
	{
	  my_put_nbr(list->data);
	  my_putchar(' ');
	  list = list->next;
	}
      my_put_nbr(list->data);
      my_putchar('\n');
    }
  return (1);
}

void	my_print_list_b(t_list *list)
{
  while (list)
    {
      my_put_nbr(list->data);
      my_putchar(' ');
      list = list->next;
    }
}

t_list		*my_create_node(int data)
{
  t_list	*node;

  if ((node = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  node->data = data;
  node->next = NULL;
  return (node);
}

t_list		*my_create_list(int ac, char **av)
{
  t_list	*list;
  t_list	*tmp;
  t_list	*node;
  int		i;

  i = 2;
  if ((list = my_create_node(my_getnbr(av[1]))) == NULL)
    return (NULL);
  tmp  = list;
  while (i < ac)
    {
      if ((node = my_create_node(my_getnbr(av[i]))) == NULL)
	return (NULL);
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = node;
      node->prev = tmp;
      i++;
    }
  node->next = list;
  list->prev = node;
  return (list);
}

int		main(int ac, char **av)
{
  t_list	*l_a;
  t_list	*l_b;
  t_list	*tmp;

  if (ac > 2)
    {
      if ((l_a = my_create_list(ac, av)) == NULL)
	return (0);
      l_b = NULL;
      if ((l_a = my_sort_algo(l_a, l_b)) == NULL)
	return (0);
      my_putchar('\n');
      tmp = l_a->prev;
      while (l_a != tmp)
	{
	  l_a = l_a->next;
	  free(l_a->prev);
	}
      free(tmp);
    }
  else
    write(2, "usage:\n./push_swap [numbers]\n", 29);
  return (0);
}
