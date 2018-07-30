/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:48:35 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/27 21:48:37 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

t_bool	ft_strisdigits(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (falsch);
		s++;
	}
	return (wahr);
}

int		stck_issorted(t_dblstck *astck, t_dblstck *bstck)
{
	void	*begin;

	if (bstck != NULL)
	{
		ft_putendl("KO");
		return (falsch);
	}
	begin = &(*astck);
	while ((void *)(astck->next) != begin)
	{
		if (astck->next->num < astck->num)
		{
			ft_putendl("KO");
			return (falsch);
		}
		astck = astck->next;
	}
	ft_putendl("OK");
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
