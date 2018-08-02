# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:26:27 by cgleason          #+#    #+#              #
#    Updated: 2018/08/01 16:38:01 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRC = mem1.c mem2.c ft_strlen.c copycat.c strfind.c strcomp.c \
	  ft_atoi.c numtoa.c ft_toupper.c ft_tolower.c char_checks.c \
	  strlife.c striter_over.c strfresh.c ft_strsplit.c \
	  put_stuff.c put_stuff_fd.c \
	  lstlife.c lstiter_over.c \
	  vecs.c \
	  get_next_line.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	@ar -rc libft.a $(OBJS)
	@ranlib libft.a

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all
