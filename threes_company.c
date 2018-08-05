/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threes_company.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:46:30 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/05 15:46:40 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	three_dstisntb(t_dblstck **src, t_range range)
{
	if ((*src)->num < (*src)->next->num)
	{
		ft_putendl("sb");
		swap(src);
	}
	if (subset_issorted(*src, SIZE, wahr))
		return ;
	ft_putendl("rb");
	rotate(src, falsch);
	ft_putendl("sb");
	swap(src);
	ft_putendl("rrb");
	rotate(src, wahr);
	if ((*src)->num < (*src)->next->num)
	{
		ft_putendl("sb");
		swap(src);
	}
}

void	three(t_dblstck **src, t_range range)
{
	if ((*src)->num > (*src)->next->num)
	{
		ft_putendl("sa");
		swap(src);
	}
	if (subset_issorted(*src, SIZE, falsch))
		return ;
	ft_putendl("ra");
	rotate(src, falsch);
	ft_putendl("sa");
	swap(src);
	ft_putendl("rra");
	rotate(src, wahr);
	if ((*src)->num > (*src)->next->num)
	{
		ft_putendl("sa");
		swap(src);
	}
}

void	dbl_three_dstisntb(t_dblstck **src, t_range range)
{
	if (subset_issorted(*src, SIZE, wahr))
		return ;
	if ((*src)->num == range.end - 1)
	{
		ft_putendl("rb");
		rotate(src, falsch);
		ft_putendl("sb");
		swap(src);
		ft_putendl("rrb");
		rotate(src, wahr);
		return ;
	}
	if ((((*src)->num == range.start && (*src)->next->num != range.end - 1) ||
		((*src)->num != range.start && (*src)->next->num == range.end - 1)))
	{
		ft_putendl("sb");
		swap(src);
	}
	if (subset_issorted(*src, SIZE, wahr))
		return ;
	((*src)->next->num == range.end - 1) ? ft_putendl("rb") : ft_putendl("rrb");
	rotate(src, (*src)->prev->num == range.end - 1);
}

void	dbl_three(t_dblstck **src, t_range range)
{
	if (subset_issorted(*src, SIZE, falsch))
		return ;
	if ((*src)->num == range.start)
	{
		ft_putendl("ra");
		rotate(src, falsch);
		ft_putendl("sa");
		swap(src);
		ft_putendl("rra");
		rotate(src, wahr);
		return ;
	}
	if (((*src)->num == range.end - 1 && (*src)->next->num != range.start) ||
		((*src)->num != range.end - 1 && (*src)->next->num == range.start))
	{
		ft_putendl("sa");
		swap(src);
	}
	if (subset_issorted(*src, SIZE, falsch))
		return ;
	((*src)->next->num == range.start) ? ft_putendl("ra") : ft_putendl("rra");
	rotate(src, (*src)->prev->num == range.start);
}
