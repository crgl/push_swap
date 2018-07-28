/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:23:29 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/27 17:23:41 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

t_bool	ft_strisdigits(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (falsch);
		s++;
	}
	return (wahr);
}

int		stck_issorted(t_dblstck *A, t_dblstck *B)
{
	void	*begin;
	if (B != NULL)
		return (falsch);
	begin = &(*A);
	while ((void *)(A->next) - begin)
	{
		if (A->next->num > A->num)
			return (falsch);
		A = A->next;
	}
	return (wahr);
}

void	wrappush(t_dblstck **dst, t_dblstck **src, t_bool rev)
{
	(void)rev;
	push(dst, src);
}

void	wraprotate(t_dblstck **to_rotate, t_dblstck **ignore, t_bool rev)
{
	(void)ignore;
	rotate(to_rotate, rev);
}

void	wrapswap(t_dblstck **to_swap, t_dblstck **ignore, t_bool rev)
{
	(void)ignore;
	(void)rev;
	swap(to_swap);
}
