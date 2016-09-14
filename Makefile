##
## Makefile for Makefile in /home/thirie_a/rendu/Piscine_C_J10
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Mar 11 15:30:08 2016 jeremy thiriez
## Last update Sun Apr 24 18:48:27 2016 jeremy thiriez
##

CC	= gcc

O	= -o

RM	= rm -rf

NAME	= push_swap

SRCS	= my_create_elem.c \
	  my_getnbr.c \
	  my_put_nbr.c \
	  my_sort_algo.c \
	  my_swap_list.c \
	  my_useless_fct.c \
	  my_putchar.c \
	  my_putstr.c \

CFLAGS	+= -W -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

NAMEH	= my.h

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(O) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
