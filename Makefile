# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 21:58:39 by cgleason          #+#    #+#              #
#    Updated: 2018/08/04 21:34:32 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

NAME3 = viz

CC = @gcc

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

DBFLAGS = -g -o debug

CMNSRC = stack_ops.c rappers.c freers.c helpers.c printing.c sorters.c

SRC1 = executor.c

SRC2 = beset.c onset.c anhidrosis.c pile.c threes_company.c

SRC3 = visualizer.c

CMNOBJS = $(CMNSRC:.c=.o)

OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

OBJS3 = $(SRC3:.c=.o);

both: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1) $(CMNOBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS1) $(CMNOBJS) $(LIB) -o $(NAME1)

$(NAME2): $(OBJS2) $(CMNOBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS2) $(CMNOBJS) $(LIB) -o $(NAME2)

$(NAME3): $(SRC3) $(CMNSRC) $(LIB)
	-$(CC) $(CFLAGS) $(SRC3) $(CMNSRC) $(LIB) -o $(NAME3)

$(LIB):
	@cd $(LIBDIR) && make

.PHONY: clean fclean all re both

debug: $(SRC2) $(LIB)
	$(CC) $(CFLAGS) $(DBFLAGS) $(SRC2) $(CMNSRC) $(LIB)

all: $(LIB) $(NAME1) $(NAME2) $(NAME3)

clean:
	@-rm -f $(OBJS1)
	@-rm -f $(OBJS2)
	@-rm -f $(OBJS3)
	@-rm -f $(CMNOBJS)
	@cd $(LIBDIR) && make clean

fclean: clean
	@-rm -f $(NAME1)
	@-rm -f $(NAME2)
	@-rm -f $(NAME3)
	@-rm -rf debug debug.dSYM
	@cd $(LIBDIR) && make fclean

re: fclean all
