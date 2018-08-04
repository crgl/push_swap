/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:40:02 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/01 20:40:41 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	return_stacks(t_dblstck **src, t_dblstck **dst, t_range range)
{
	stck_push_a(src, dst, range);
	sorted_push(src, dst, SIZE, falsch);
	return ;
}

void	dblstck_push_b(t_dblstck **src, t_dblstck **dst, t_range range)
{
	int	j;

	if (SIZE == 2 && !subset_issorted(*src, 2, falsch))
	{
		ft_putendl("sa");
		swap(src);
	}
	if (subset_issorted(*src, SIZE, falsch))
		return ;
	j = prepush_stck_a(src, dst, range);
	if (SIZE > 1)
		dblstck_push_b(src, dst, (t_range){SIZE / 2 + range.start, range.end});
	return_stacks(dst, src, (t_range){MIDPT - j, MIDPT});
}

void	print_ops(t_dblstck *astck, t_dblstck *bstck, int n)
{
	t_dblstck	*start;

	if (n == 0)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	start = astck;
	if (!subset_issorted(start, n, falsch))
		dblstck_push_b(&astck, &bstck, (t_range){0, n});
}

int		main(int argc, char **argv)
{
	t_dblstck	*astck;
	int			size;

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
	size = convert_rank(astck);
	print_ops(astck, NULL, size);
	free_stck(&astck);
	return (0);
}
