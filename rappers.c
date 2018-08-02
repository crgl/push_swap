/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:48:35 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/27 21:48:37 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	wrappush(t_dblstck **dst, t_dblstck **src, t_bool rev)
{
	(void)rev;
	push(dst, src);
}

void	wraprotate(t_dblstck **to_rotate, t_dblstck **ignore, t_bool rev)
{
	(void)ignore;
	rotate(to_rotate, rev);
}

void	wrapswap(t_dblstck **to_swap, t_dblstck **ignore, t_bool rev)
{
	(void)ignore;
	(void)rev;
	swap(to_swap);
}
