/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anhidrosis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 12:35:45 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/05 12:35:55 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	small_stuff(t_dblstck **src, t_dblstck **dst, t_range range,
			t_bool dstisb)
{
	if (subset_issorted(*src, SIZE, !dstisb))
		return ;
	if (SIZE == stck_len(*src))
	{
		dbl_small_stuff(src, dst, range, dstisb);
		return ;
	}
	if (SIZE == 2)
	{
		(dstisb) ? ft_putendl("sa") : ft_putendl("sb");
		swap(src);
	}
	else if (SIZE == 3)
	{
		if (dstisb)
			three(src, range);
		else
			three_dstisntb(src, range);
	}
}

void	dbl_small_stuff(t_dblstck **src, t_dblstck **dst, t_range range,
			t_bool dstisb)
{
	(void)dst;
	if (subset_issorted(*src, SIZE, !dstisb))
		return ;
	if (SIZE == 2)
	{
		(dstisb) ? ft_putendl("sa") : ft_putendl("sb");
		swap(src);
	}
	else if (SIZE == 3)
	{
		if (dstisb)
			dbl_three(src, range);
		else
			dbl_three_dstisntb(src, range);
	}
}
