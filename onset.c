/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:05:32 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/04 16:05:43 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	sorted_push(t_dblstck **src, t_dblstck **dst, int n, t_bool dstisb)
{
	int	i;

	i = 0;
	if (dstisb)
	{
		while (i < n)
		{
			ft_putendl("pb");
			push(dst, src);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			ft_putendl("pa");
			push(dst, src);
			i++;
		}
	}
}

int		prepush_stck_b(t_dblstck **src, t_dblstck **dst, t_range range)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < SIZE)
	{
		if ((*src)->num >= MIDPT && (*src)->num < range.end)
		{
			ft_putendl("pa");
			push(dst, src);
			j++;
		}
		else
		{
			ft_putendl("rb");
			rotate(src, falsch);
		}
	}
	return (j);
}

void	stck_push_a(t_dblstck **src, t_dblstck **dst, t_range range)
{
	int	j;
	int	k;

	if (SIZE < 4)
		small_stuff(src, dst, range, falsch);
	if (subset_issorted(*src, SIZE, wahr))
		return ;
	j = prepush_stck_b(src, dst, range);
	k = 0;
	while (k++ < SIZE - j)
	{
		ft_putendl("rrb");
		rotate(src, wahr);
	}
	if (SIZE > 1)
		stck_push_a(src, dst, (t_range){range.start, MIDPT});
	stck_push_b(dst, src, (t_range){MIDPT, MIDPT + j});
	sorted_push(dst, src, j, wahr);
}

int		prepush_stck_a(t_dblstck **src, t_dblstck **dst, t_range range)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < SIZE)
	{
		if ((*src)->num < MIDPT && (*src)->num >= range.start)
		{
			ft_putendl("pb");
			push(dst, src);
			j++;
		}
		else
		{
			ft_putendl("ra");
			rotate(src, falsch);
		}
	}
	return (j);
}

void	stck_push_b(t_dblstck **src, t_dblstck **dst, t_range range)
{
	int	j;
	int	k;

	if (SIZE < 4)
		small_stuff(src, dst, range, wahr);
	if (subset_issorted(*src, SIZE, falsch))
		return ;
	j = prepush_stck_a(src, dst, range);
	k = 0;
	while (k++ < SIZE - j)
	{
		ft_putendl("rra");
		rotate(src, wahr);
	}
	if (SIZE > 1)
		stck_push_b(src, dst, (t_range){MIDPT, range.end});
	stck_push_a(dst, src, (t_range){MIDPT - j, MIDPT});
	sorted_push(dst, src, j, falsch);
}
