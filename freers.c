/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:05:09 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/31 18:09:43 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	free_stck(t_dblstck **astck)
{
	t_dblstck	*top;
	t_dblstck	*tmp;
	t_dblstck	*tmp2;

	top = *astck;
	if (top == NULL)
		return ;
	tmp = top->next;
	while (tmp != top)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(*astck);
	*astck = NULL;
}

void	free_stack_ops(t_dblstck **aastck, t_dblstck **abstck, char *op)
{
	free_stck(aastck);
	free_stck(abstck);
	free(op);
}
