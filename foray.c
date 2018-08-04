/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:32:55 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/30 16:33:27 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int		quiet_stck_issorted(t_dblstck *astck, t_dblstck *bstck, t_bool rev)
{
	void	*begin;

	if (bstck != NULL)
		return (falsch);
	begin = &(*astck);
	while ((void *)(astck->next) != begin)
	{
		if (!rev)
		{
			if (astck->next->num < astck->num)
				return (falsch);
			astck = astck->next;
		}
		else
		{
			if (astck->next->num > astck->num)
				return (falsch);
			astck = astck->next;
		}
	}
	return (wahr);
}

void	stck_align(t_dblstck *current, t_dblstck *target, t_bool is_b)
{
	int			fwd;
	int			rev;
	t_dblstck	*tmp;

	fwd = 0;
	rev = 0;
	tmp = current;
	while (tmp != target)
	{
		tmp = tmp->next;
		fwd++;
	}
	tmp = current;
	while (tmp != target)
	{
		tmp = tmp->prev;
		rev++;
	}
	if (rev < fwd)
		while (rev--)
			(is_b) ? ft_putendl("rrb") : ft_putendl("rra");
	else
		while (fwd--)
			(is_b) ? ft_putendl("rb") : ft_putendl("ra");
}

void	push_sorted(t_dblstck **adst, t_dblstck **asrc)
{
	t_dblstck	*dst_top;

	dst_top = *adst;
	while (*asrc)
	{
		if ((*asrc)->num > dst_top->prev->num)
		{
			ft_putendl("pa");
			push(&dst_top, asrc);
		}
		else
		{
			ft_putendl("rra");
			rotate(&dst_top, wahr);
		}
	}
	stck_align(dst_top, *adst, falsch);
}

void	push_unsorted_b(t_dblstck **adst, t_dblstck **asrc)
{
	t_dblstck	*atop;
	int			comparor;

	if (quiet_stck_issorted(*asrc, NULL, wahr))
		return ;
	atop = *asrc;
	comparor = atop->num;
	ft_putendl("rb");
	rotate(asrc, falsch);
	while (*asrc != atop)
	{
		if ((*asrc)->num > comparor)
		{
			ft_putendl("pa");
			ft_putendl("ra");
			push(adst, asrc);
			rotate(adst, falsch);
		}
		else
		{
			comparor = (*asrc)->num;
			ft_putendl("rb");
			rotate(asrc, falsch);
		}
	}
}

void	clean_b(t_dblstck **astck, t_dblstck **bstck)
{
	int			max;
	t_dblstck	*loc_max;
	t_dblstck	*start;

	start = *bstck;
	loc_max = start;
	max = start->num;
	rotate(bstck, falsch);
	while (*bstck != loc_max)
	{
		if ((*bstck)->num > max)
		{
			max = (*bstck)->num;
			loc_max = *bstck;
		}
		rotate(bstck, falsch);
	}
	stck_align(start, loc_max, wahr);
	push_unsorted_b(astck, &loc_max);
}

void	push_unsorted_a(t_dblstck **adst, t_dblstck **asrc)
{
	t_dblstck	*atop;
	int			comparor;

	atop = *asrc;
	comparor = atop->num;
	ft_putendl("ra");
	rotate(asrc, falsch);
	while (*asrc != atop)
	{
		if ((*asrc)->num < comparor)
		{
			ft_putendl("pb");
			push(adst, asrc);
		}
		else
		{
			comparor = (*asrc)->num;
			ft_putendl("ra");
			rotate(asrc, falsch);
		}
	}
}

void	print_ops(t_dblstck *astck, t_dblstck *bstck)
{
	int			min;
	t_dblstck	*loc_min;
	t_dblstck	*start;

	start = astck;
	loc_min = astck;
	min = astck->num;
	astck = astck->next;
	while (astck != loc_min)
	{
		if (astck->num < min)
		{
			min = astck->num;
			loc_min = astck;
		}
		astck = astck->next;
	}
	stck_align(start, loc_min, falsch);
	while (!quiet_stck_issorted(loc_min, bstck, falsch))
	{
		push_unsorted_a(&bstck, &loc_min);
		clean_b(&loc_min, &bstck);
		push_sorted(&loc_min, &bstck);
	}
}

int		main(int argc, char **argv)
{
	t_dblstck	*astck;

	astck = NULL;
	if (argc == 1 || (argc == 2 && ft_isint(argv[1])))
		return (0);
	while (--argc)
	{
		if (!ft_isint(argv[argc]))
			break ;
		add(&astck, dblstck_new(ft_atoi(argv[argc])));
	}
	if (check_dup(astck) || argc)
	{
		ft_putendl_fd("Error", 2);
		free_stck(&astck);
		return (1);
	}
	print_ops(astck, NULL);
	free_stck(&astck);
	return (0);
}
