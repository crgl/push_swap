/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:49:24 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/04 14:49:34 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int		stck_len(t_dblstck *stck)
{
	int			i;
	t_dblstck	*top;

	top = stck;
	if (top == NULL)
		return (0);
	stck = stck->next;
	i = 1;
	while (stck != top)
	{
		stck = stck->next;
		i++;
	}
	return (i);
}

t_bool	subset_issorted(t_dblstck *stck, int n, t_bool rev)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if ((stck->next->num < stck->num && !rev) ||
			(stck->next->num > stck->num && rev))
			return (falsch);
		i++;
		stck = stck->next;
	}
	return (wahr);
}

int		stck_issorted(t_dblstck *astck, t_dblstck *bstck)
{
	void	*begin;

	if (bstck != NULL)
	{
		ft_putendl("KO");
		free_stck(&astck);
		free_stck(&bstck);
		return (falsch);
	}
	begin = &(*astck);
	while ((void *)(astck->next) != begin)
	{
		if (astck->next->num < astck->num)
		{
			ft_putendl("KO");
			free_stck(&astck);
			return (falsch);
		}
		astck = astck->next;
	}
	ft_putendl("OK");
	free_stck(&astck);
	return (wahr);
}
