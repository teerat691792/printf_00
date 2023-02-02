# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:03:31 by tkulket           #+#    #+#              #
#    Updated: 2023/02/02 19:18:04 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Werror -Wextra

NAME	= ft_printf.a

SRC		=		ft_printf.c\
				libft/ft_strlen.c\
				libft/ft_strchr.c\
				libft/ft_strnstr.c\
				libft/ft_isprint.c\
				libft/ft_putchar_fd.c\
				libft/ft_itoa.c\
				libft/ft_utoa.c\
				libft/ft_htoa.c\
				libft/ft_address.c\
				libft/ft_toupper_h.c\
				libft/ft_putstr_fd.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
		gcc $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

c: re
		gcc -std=c99 -g $(FLAGS) main.c -L. -lftprintf
g:
		gdb a.out
l:
		ar -t $(NAME)
o:
		./a.out | cat -e

re: fclean all

.PHONY : all clean fclean re c g l o
