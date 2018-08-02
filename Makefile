# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 21:58:39 by cgleason          #+#    #+#              #
#    Updated: 2018/08/01 16:34:13 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = checker

EXEC2 = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

DBFLAGS = -g -o debug

SRC1 = stack_ops.c executor.c rappers.c freers.c helpers.c

SRC2 = foray.c rappers.c stack_ops.c freers.c helpers.c

OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

LIB = $(LIBDIR)/libft.a

LIBDIR = libft

all: $(OBJS1) $(OBJS2) $(LIB)
	$(CC) $(CFLAGS) $(OBJS1) $(LIB) -o $(EXEC1)
	$(CC) $(CFLAGS) $(OBJS2) $(LIB) -o $(EXEC2)

$(LIB):
	@cd $(LIBDIR) && make

.PHONY: clean fclean all re

debug: $(SRC2) $(LIB)
	$(CC) $(DBFLAGS) $(SRC2) $(LIB)

clean:
	@rm -f $(OBJS1)
	@rm -f $(OBJS2)
	@cd $(LIBDIR) && make clean

fclean:
	@rm -f $(EXEC1)
	@rm -f $(EXEC2)

re: fclean all
