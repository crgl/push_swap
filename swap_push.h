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

# define SIZE (range.end - range.start)
# define MIDPT range.start + SIZE / 2

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
t_bool			subset_issorted(t_dblstck *stck, int n, t_bool rev);
int				stck_len(t_dblstck *stck);

void			sorted_push(t_dblstck **src, t_dblstck **dst, int n,
					t_bool dstisb);
void			stck_push_a(t_dblstck **src, t_dblstck **dst, t_range range);
void			stck_push_b(t_dblstck **src, t_dblstck **dst, t_range range);
int				prepush_stck_a(t_dblstck **src, t_dblstck **dst,
					t_range range);
void			dbl_small_stuff(t_dblstck **src, t_dblstck **dst,
					t_range range, t_bool dstisb);
void			small_stuff(t_dblstck **src, t_dblstck **dst,
					t_range range, t_bool dstisb);
void			dbl_three(t_dblstck **src, t_range range);
void			dbl_three_dstisntb(t_dblstck **src, t_range range);
void			three(t_dblstck **src, t_range range);
void			three_dstisntb(t_dblstck **src, t_range range);

char			**maybe_split(char **argv, int *aargc);
void			free_stck(t_dblstck **astck);
void			free_stack_ops(t_dblstck **aastck, t_dblstck **abstck,
					char *op);
void			free_av(char **av);

int				stcklst_len(t_dblstck **stck_array);
void			heap_repair(t_dblstck **stck_array, int ind, int n);
void			stck_heapsort(t_dblstck **stck_array);
int				convert_rank(t_dblstck *stck);

void			print_stacks(t_dblstck *astck, t_dblstck *bstck);
void			find_extrema(t_dblstck *stck, long *min, long *max);
int				color_of(t_dblstck *stck);
void			clear_and_print(t_dblstck *astck, t_dblstck *bstck);

#endif
