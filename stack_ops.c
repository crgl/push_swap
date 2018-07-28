/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:12:59 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/25 22:31:36 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

t_dblstck	*dblstck_new(int num)
{
	t_dblstck	*new_ds;

	new_ds = (t_dblstck *)malloc(sizeof(t_dblstck));
	if (!new_ds)
		return (NULL);
	new_ds->next = new_ds;
	new_ds->prev = new_ds;
	new_ds->num = num;
	return (new_ds);
}

void	add(t_dblstck **atop, t_dblstck *to_add)
{
	if (*atop == NULL)
		*atop = to_add;
	to_add->next = *atop;
	to_add->prev = (*atop)->prev;
	(*atop)->prev = to_add;
	if ((*atop)->next == *atop)
		(*atop)->next = to_add;
	*atop = to_add;
}

void	rotate(t_dblstck **atop, t_bool rev)
{
	if (rev)
		*atop = (*atop)->prev;
	else
		*atop = (*atop)->next;
}

void	swap(t_dblstck **top)
{
	t_dblstck	*first;
	t_dblstck	*second;

	first = *top;
	if (first == NULL)
		return ;
	second = first->next;
	second->prev = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	*top = second;
}

void	push(t_dblstck **dst_top, t_dblstck **src_top)
{
	t_dblstck	*tmp;

	if (*src_top == NULL)
		return ;
	tmp = *src_top;
	*src_top = (*src_top)->next;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	if (tmp->next == tmp)
		*src_top = NULL;
	if (*dst_top == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		*dst_top = tmp;
	}
	else
		add(dst_top, tmp);
}
