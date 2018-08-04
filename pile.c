/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:51:54 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/03 13:52:05 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

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
	i = n / 2 + 1;
	while (i--)
		heap_repair(stck_array, i, n);
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
