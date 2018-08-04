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

t_bool	beset_stck_issorted(t_dblstck *astck, t_dblstck *bstck, t_bool rev,
			int n)
{
	t_dblstck	*begin;
	int			i;

	i = 0;
	if (bstck != NULL)
		return (falsch);
	begin = &(*astck);
	while ((void *)(astck->next) != begin && i++ < n)
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

void	sorted_push_b(t_dblstck **src_stck, t_dblstck **dst_stck, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putendl("pb");
		push(dst_stck, src_stck);
		i++;
	}
}

void	sorted_push_a(t_dblstck **src_stck, t_dblstck **dst_stck, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putendl("pa");
		push(dst_stck, src_stck);
		i++;
	}
}

// void	stck_push_b(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
// {
// 	int	i;

// 	i = 0;
// 	if (*src_stck == NULL)
// 		return ;
// 	if (range.end - range.start == 2 && !subset_issorted(*src_stck, 2, falsch))
// 	{
// 		ft_putendl("sa");
// 		swap(src_stck);
// 	}
// 	if (subset_issorted(*src_stck, range.end - range.start, falsch))
// 	{
// 		sorted_push_b(src_stck, dst_stck, range.end - range.start);
// 		return ;
// 	}
// 	while (i < range.end - range.start)
// 	{
// 		if ((*src_stck)->num < range.start + (range.end - range.start) / 2 &&
// 			(*src_stck)->num >= range.start)
// 		{
// 			ft_putendl("pb");
// 			push(dst_stck, src_stck);
// 		}
// 		else
// 		{
// 			ft_putendl("ra");
// 			rotate(src_stck, falsch);
// 		}
// 		i++;
// 	}
// 	while (i-- > (range.end - range.start) / 2)
// 	{
// 		ft_putendl("rra");
// 		rotate(src_stck, wahr);
// 	}
// print_stacks(*src_stck, *dst_stck);
// 	if (!subset_issorted(*src_stck, range.end - range.start, falsch))
// 		stck_push_b(src_stck, dst_stck,
// 			(t_range){(range.end - range.start) / 2 + range.start, range.end});
// 	else
// 		stck_push_a(dst_stck, src_stck,
// 			(t_range){range.start, range.end - (range.end - range.start) / 2});
// 	sorted_push_b(src_stck, dst_stck, range.end - range.start);
// }

// void	stck_push_a(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
// {
// 	int	i;

// 	i = 0;
// 	if (*src_stck == NULL)
// 		return ;
// 	if (range.end - range.start == 2 && !subset_issorted(*src_stck, 2, wahr))
// 	{
// 		ft_putendl("sb");
// 		swap(src_stck);
// 	}
// 	if (subset_issorted(*src_stck, range.end - range.start, wahr))
// 	{
// 		sorted_push_a(src_stck, dst_stck, range.end - range.start);
// 		return ;
// 	}
// 	while (i < range.end - range.start)
// 	{
// 		if ((*src_stck)->num >= range.start + (range.end - range.start) / 2 &&
// 			(*src_stck)->num <= range.end)
// 		{
// 			ft_putendl("pa");
// 			push(dst_stck, src_stck);
// 		}
// 		else
// 		{
// 			ft_putendl("rb");
// 			rotate(src_stck, falsch);
// 		}
// 		i++;
// 	}
// 	while (i-- > (range.end - range.start) / 2)
// 	{
// 		ft_putendl("rrb");
// 		rotate(src_stck, wahr);
// 	}
// print_stacks(*dst_stck, *src_stck);
// 	if (!subset_issorted(*src_stck, range.end - range.start, wahr))
// 		stck_push_a(src_stck, dst_stck,
// 			(t_range){range.start, range.end - (range.end - range.start) / 2});
// 	else
// 		stck_push_b(dst_stck, src_stck,
// 			(t_range){(range.end - range.start) / 2 + range.start, range.end});
// 	sorted_push_a(src_stck, dst_stck, range.end - range.start);
// }

void	stck_push_a(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
{
	int	i;
	int	j;
	int	k;

	if (range.end - range.start < 1)
		return ;
	if (range.end - range.start == 2 && !subset_issorted(*src_stck, 2, wahr))
	{
		ft_putendl("sb");
		swap(src_stck);
	}
	// if (subset_issorted(*src_stck, range.end - range.start, wahr))
	// {
	// 	sorted_push_a(src_stck, dst_stck, range.end - range.start);
	// 	return ;
	// }
	i = 0;
	j = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num >= range.start + (range.end - range.start) / 2 &&
			(*src_stck)->num < range.end)
		{
			ft_putendl("pa");
			push(dst_stck, src_stck);
			j++;
		}
		else
		{
			ft_putendl("rb");
			rotate(src_stck, falsch);
		}
		i++;
	}
	k = 0;
	while (k++ < i - j)
	{
		ft_putendl("rrb");
		rotate(src_stck, wahr);
	}
	if (j >= 1)
		stck_push_a(src_stck, dst_stck,
			(t_range){range.start, range.start + (range.end - range.start) / 2});
	sorted_push_b(dst_stck, src_stck, j);
	// stck_push_b(dst_stck, src_stck,
	// 	(t_range){range.start + (range.end - range.start) / 2,
	// 	range.start + (range.end - range.start) / 2 + j});
}

void	stck_push_b(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
{
	int	i;
	int	j;
	int	k;

	if (range.end - range.start < 1)
		return ;
	if (range.end - range.start == 2 && !subset_issorted(*src_stck, 2, falsch))
	{
		ft_putendl("sa");
		swap(src_stck);
	}
	// if (subset_issorted(*src_stck, range.end - range.start, falsch))
	// {
	// 	sorted_push_b(src_stck, dst_stck, range.end - range.start);
	// 	return ;
	// }
	i = 0;
	j = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num < range.start + (range.end - range.start) / 2 &&
			(*src_stck)->num >= range.start)
		{
			ft_putendl("pb");
			push(dst_stck, src_stck);
			j++;
		}
		else
		{
			ft_putendl("ra");
			rotate(src_stck, falsch);
		}
		i++;
	}
	k = 0;
	while (k++ < i - j)
	{
		ft_putendl("rra");
		rotate(src_stck, wahr);
	}
	if (j >= 1)
		stck_push_b(src_stck, dst_stck,
			(t_range){range.start + (range.end - range.start) / 2, range.end});
	sorted_push_a(dst_stck, src_stck, j);
	// stck_push_a(dst_stck, src_stck,
	// 	(t_range){range.start + (range.end - range.start) / 2 - j,
	// 	range.start + (range.end - range.start) / 2});
}

void	return_stacks(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
{
	stck_push_a(src_stck, dst_stck, range);
	sorted_push_a(src_stck, dst_stck, range.end - range.start);
	return ;
}

void	dblstck_push_b(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
{
	int	i;
	int	j;

	i = 0;
	if (range.end - range.start == 2 && !subset_issorted(*src_stck, 2, falsch))
	{
		ft_putendl("sa");
		swap(src_stck);
	}
	if (subset_issorted(*src_stck, range.end - range.start, falsch))
		return ;
	j = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num < range.start + (range.end - range.start) / 2 &&
			(*src_stck)->num >= range.start)
		{
			ft_putendl("pb");
			push(dst_stck, src_stck);
			j++;
		}
		else
		{
			ft_putendl("ra");
			rotate(src_stck, falsch);
		}
		i++;
	}
	if (i > 1)
		dblstck_push_b(src_stck, dst_stck,
			(t_range){(range.end - range.start) / 2 + range.start, range.end});
	return_stacks(dst_stck, src_stck, (t_range){range.start + (range.end - range.start) / 2 - j, range.start + (range.end - range.start) / 2});
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
	if (!beset_stck_issorted(start, bstck, falsch, n))
		dblstck_push_b(&astck, &bstck, (t_range){0, n});
};

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
