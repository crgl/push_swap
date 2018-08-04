/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:58:24 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/03 13:58:37 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	find_extrema(t_dblstck *stck, long *min, long *max)
{
	t_dblstck	*start;

	start = stck;
	*min = (long)stck->num;
	*max = (long)stck->num;
	stck = stck->next;
	while (stck != start)
	{
		if ((long)stck->num < *min)
			*min = (long)stck->num;
		if ((long)stck->num > *max)
			*max = (long)stck->num;
		stck = stck->next;
	}
}

int		color_of(t_dblstck *stck)
{
	static long		min;
	static long		max;
	static t_bool	cached;

	if (!cached)
	{
		find_extrema(stck, &min, &max);
		cached = wahr;
	}
	return (20 + (32 * (stck->num - min)) / (max - min + 1));
}

void	print_line(t_dblstck **stck)
{
	int			color;
	int			width;

	if (*stck != NULL)
	{
		color = color_of(*stck);
		width = 2 * ((color - 20) / 2) + 2;
		ft_printf("%*.i%{b}%*.i\033[0m%*.i\t", (32 - width) / 2, 0, color,
			width, 0, (32 - width) / 2, 0);
		cleanup();
		*stck = (*stck)->next;
	}
	else
		ft_printf("%32.i\t", 0);
}

void	clear_and_print(t_dblstck *astck, t_dblstck *bstck)
{
	t_dblstck	*atop;
	t_dblstck	*btop;

	usleep(10000);
	ft_printf("\033[2J\033[;H\033[?25l\n\n");
	atop = astck;
	btop = bstck;
	if (astck != NULL)
		astck->prev->next = NULL;
	if (bstck != NULL)
		bstck->prev->next = NULL;
	while (astck != NULL || bstck != NULL)
	{
		print_line(&astck);
		print_line(&bstck);
		ft_printf("\n");
	}
	if (atop != NULL)
		atop->prev->next = atop;
	if (btop != NULL)
		btop->prev->next = btop;
}
