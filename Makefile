# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 21:58:39 by cgleason          #+#    #+#              #
#    Updated: 2018/08/04 15:21:14 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = checker

EXEC2 = push_swap

VIZ = viz

CC = @gcc

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

DBFLAGS = -g -o debug

CMNSRC = stack_ops.c rappers.c freers.c helpers.c pile.c printing.c sorters.c

SRC1 = executor.c

SRC2 = beset.c onset.c

VIZSRC = visualizer.c

CMNOBJS = $(CMNSRC:.c=.o)

OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

VIZOBJS = $(VIZSRC:.c=.o);

all: $(OBJS1) $(OBJS2) $(CMNOBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS1) $(CMNOBJS) $(LIB) -o $(EXEC1)
	$(CC) $(CFLAGS) $(OBJS2) $(CMNOBJS) $(LIB) -o $(EXEC2)

$(VIZ): $(VIZOBJS) $(LIB)
	$(CC) $(CFLAGS) $(VIZOBJS) $(CMNOBJS) $(LIB) -o $(VIZ)

$(LIB):
	@cd $(LIBDIR) && make

.PHONY: clean fclean all re

debug: $(SRC2) $(LIB)
	$(CC) $(CFLAGS) $(DBFLAGS) $(SRC2) $(CMNSRC) $(LIB)

clean:
	@rm -f $(OBJS1)
	@rm -f $(OBJS2)
	@rm -f $(CMNOBJS)
	@rm -f $(VIZOBJS)
	@cd $(LIBDIR) && make clean

fclean: clean
	@rm -f $(EXEC1)
	@rm -f $(EXEC2)
	@rm -f $(VIZ)
	@rm -rf debug debug.dSYM
	@cd $(LIBDIR) && make fclean

re: fclean all
