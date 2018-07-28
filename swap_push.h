/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:05:15 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/25 22:31:57 by cgleason         ###   ########.fr       */
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

int				stck_issorted(t_dblstck *A, t_dblstck *B);

t_bool			ft_strisdigits(char *s);
void			wrappush(t_dblstck **dst, t_dblstck **src, t_bool rev);
void			wraprotate(t_dblstck **to_rotate, t_dblstck **ignore, t_bool rev);
void			wrapswap(t_dblstck **to_swap, t_dblstck **ignore, t_bool rev);

#endif
