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
#include <stdio.h>

int		beset_stck_issorted(t_dblstck *astck, t_dblstck *bstck, t_bool rev,
			int n)
{
	void	*begin;
	int		i;

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

int		stcklst_len(t_dblstck **stck_array)
{
	int	i;

	i = 0;
	while (stck_array[i] != NULL)
		i++;
	return (i);
}

void	heap_repair(t_dblstck **stck_array, int ind, int n)
{
	int			lind;
	int			rind;
	int			maxind;
	t_dblstck	*tmp;

	lind = 2 * ind + 1;
	rind = 2 * ind + 2;
	maxind = ind;
	if (lind < n)
		if (stck_array[lind]->num > stck_array[maxind]->num)
			maxind = lind;
	if (rind < n)
		if (stck_array[rind]->num > stck_array[maxind]->num)
			maxind = rind;
	if (maxind != ind)
	{
		tmp = stck_array[ind];
		stck_array[ind] = stck_array[maxind];
		stck_array[maxind] = tmp;
		heap_repair(stck_array, maxind, n);
	}
}

void	stck_heapsort(t_dblstck **stck_array)
{
	int			n;
	t_dblstck	*tmp;
	int			i;

	n = stcklst_len(stck_array);
	i = n / 2;
	while (i)
		heap_repair(stck_array, i--, n);
	i = n;
	while (i--)
	{
		tmp = stck_array[i];
		stck_array[i] = stck_array[0];
		stck_array[0] = tmp;
		heap_repair(stck_array, 0, i);
	}
}

int		convert_rank(t_dblstck *stck)
{
	t_dblstck	**stck_array;
	int			i;
	t_dblstck	*top;
	t_dblstck	*tmp;

	top = stck;
	tmp = top->next;
	i = 1;
	while (tmp != top)
	{
		i++;
		tmp = tmp->next;
	}
	stck_array = (t_dblstck **)ft_memalloc((i + 1) * sizeof(t_dblstck *));
	if (stck_array == NULL)
		return (0);
	while (i--)
	{
		stck_array[i] = tmp;
		tmp = tmp->next;
	}
	stck_heapsort(stck_array);
	i = -1;
	while (stck_array[++i] != NULL)
		stck_array[i]->num = i;
	return (i);
}

void	handle_end(t_dblstck **dst_stck, t_dblstck **src_stck, t_range range)
{

	return ;
}

void	sort_and_push_b(t_dblstck **dst_stck, t_dblstck **src_stck, t_range range)
{
	int	i;

	i = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num < range.start + (range.end - range.start) / 2)
		{
			ft_putendl("pb");
			push(dst_stck, src_stck);
		}
		else
		{
			ft_putendl("ra");
			rotate(src_stck, falsch);
		}
		i++;
	}
	i = (range.end - range.start) / 2;
	while (i < range.end - range.start)
	{
		ft_putendl("rra");
		rotate(src_stck, wahr);
		i++;
	}
	if (range.end - range.start <= 6)
		handle_end(dst_stck, src_stck, range);
	else
		sort_and_push_a(src_stck, dst_stck,
			(t_range){(range.end - range.start) / 2, range.end});

}

void	sort_and_push_a(t_dblstck **dst_stck, t_dblstck **src_stck, t_range range)
{
	int	i;

	i = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num < range.start + (range.end - range.start) / 2)
		{
			ft_putendl("pa");
			push(dst_stck, src_stck);
		}
		else
		{
			ft_putendl("rb");
			rotate(src_stck, falsch);
		}
		i++;
	}
	i = (range.end - range.start) / 2;
	while (i < range.end - range.start)
	{
		ft_putendl("rrb");
		rotate(src_stck, wahr);
		i++;
	}
	if (range.end - range.start <= 6)
		handle_end(dst_stck, src_stck, range);
	else
		sort_and_push_b(src_stck, dst_stck,
			(t_range){(range.end - range.start) / 2, range.end});
}

void	dblstck_push_b(t_dblstck **src_stck, t_dblstck **dst_stck, t_range range)
{
	int	i;

	i = 0;
	while (i < range.end - range.start)
	{
		if ((*src_stck)->num < range.start + (range.end - range.start) / 2)
		{
			ft_putendl("pb");
			push(dst_stck, src_stck);
		}
		else
		{
			ft_putendl("ra");
			rotate(src_stck, falsch);
		}
		i++;
	}
	if (i > 0)
		dblstck_push_b(src_stck, dst_stck,
			(t_range){(range.end - range.start) / 2, range.end});
}

void	print_ops(t_dblstck *astck, t_dblstck *bstck, int n)
{
	t_dblstck	*start;
	int			i;

	if (n = 0)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	start = astck;
	if (!beset_stck_issorted(start, bstck, falsch, n))
	{
		dblstck_push_b(&astck, &bstck, (t_range){0, n});
		i = 1;
		while (i < n)
		{
			sort_and_push_a(&astck, &bstck, (t_range){n - i, n - (i / 2)});
			i *= 2;
		}
	}
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
