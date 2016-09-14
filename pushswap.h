/*
** pushswap.h for puschswap.h in /home/thirie_a/CPE_2016_Pushswap
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Apr  5 12:02:44 2016 jeremy thiriez
** Last update Sun Apr 24 15:34:36 2016 jeremy thiriez
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list	*prev;
  int		data;
}		t_list;

typedef struct	s_struct
{
  int		space;
  int		i;
  int		j;
}		t_struct;

t_list		*my_sort_algo(t_list *l_a, t_list *l_b);
int		my_put_in_b(t_list **la, t_list **lb, t_struct *in);
int		my_put_in_a(t_list **la, t_list **lb, t_struct *in);
int		my_swap_first_to_last(t_list **list, char c);
int		put_in_b_or_next(t_list **l_a, t_list **l_b, t_struct *in, int j);
int		my_put_in_other_list(t_list **l1, t_list **l2);
t_list		*my_tri_bullshit(t_list *l_a, t_list *l_b);
int		my_put_nbr(int nb);
void		my_putchar(char c);
int		my_putstr(char *str);
t_list		*my_create_node(int data);
int		my_getnbr(char *str);
int		my_check_sort(t_list *l_a);

#endif /* !PUSHSWAP_H_ */
