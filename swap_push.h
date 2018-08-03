/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:48:04 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/27 21:48:08 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_PUSH_H
# define SWAP_PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef enum	e_bool
{
	falsch,
	wahr,
}				t_bool;

typedef struct	s_range
{
	int		start;
	int		end;
}				t_range;

typedef struct	s_dblstck
{
	struct s_dblstck	*next;
	struct s_dblstck	*prev;
	int					num;
}				t_dblstck;

typedef void	(*t_wraptor)(t_dblstck **, t_dblstck **, t_bool);

t_dblstck		*dblstck_new(int num);
void			add(t_dblstck **atop, t_dblstck *to_add);
void			rotate(t_dblstck **atop, t_bool rev);
void			swap(t_dblstck **top);
void			push(t_dblstck **dst_top, t_dblstck **src_top);

void			wrappush(t_dblstck **dst, t_dblstck **src, t_bool rev);
void			wraprotate(t_dblstck **to_rotate, t_dblstck **ignore,
					t_bool rev);
void			wrapswap(t_dblstck **to_swap, t_dblstck **ignore, t_bool rev);

t_bool			ft_isint(char *s);
t_bool			find_int(int *checklist, int to_check, size_t lim);
t_bool			check_dup(t_dblstck *stack);
int				stck_issorted(t_dblstck *astck, t_dblstck *bstck);
int				quiet_stck_issorted(t_dblstck *astck, t_dblstck *bstck,
					t_bool rev);

void			free_stck(t_dblstck **astck);
void			free_stack_ops(t_dblstck **aastck, t_dblstck **abstck,
					char *op);

void			print_stacks(t_dblstck *astck, t_dblstck *bstck);

#endif
