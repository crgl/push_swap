/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:15:35 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/01 12:15:46 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	print_stacks(t_dblstck *astck, t_dblstck *bstck)
{
	t_dblstck	*atop;
	t_dblstck	*btop;

	atop = astck;
	btop = bstck;
	if (atop == NULL)
		ft_putendl("(NULL)");
	else
	{
		ft_putnbr(astck->num);
		astck = astck->next;
		while (astck != atop)
		{
			ft_putchar('\n');
			ft_putnbr(astck->num);
			astck = astck->next;
		}
	}
	ft_putendl("\nA\n");
	if (btop == NULL)
		ft_putendl("(NULL)");
	else
	{
		ft_putnbr(bstck->num);
		bstck = bstck->next;
		while (bstck != btop)
		{
			ft_putchar('\n');
			ft_putnbr(bstck->num);
			bstck = bstck->next;
		}
	}
	ft_putendl("\nB\n");
}

t_bool	ft_isint(char *s)
{
	char	*shouldbes;

	shouldbes = ft_itoa(ft_atoi(s));
	if (!ft_strequ(shouldbes, s))
	{
		free(shouldbes);
		return (falsch);
	}
	free(shouldbes);
	return (wahr);
}

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

int		stck_issorted(t_dblstck *astck, t_dblstck *bstck)
{
	void	*begin;

	if (bstck != NULL)
	{
		ft_putendl("KO");
		free_stck(&astck);
		free_stck(&bstck);
		return (falsch);
	}
	begin = &(*astck);
	while ((void *)(astck->next) != begin)
	{
		if (astck->next->num < astck->num)
		{
			ft_putendl("KO");
			free_stck(&astck);
			return (falsch);
		}
		astck = astck->next;
	}
	ft_putendl("OK");
	free_stck(&astck);
	return (wahr);
}

t_bool	find_int(int *checklist, int to_check, size_t lim)
{
	size_t	i;

	i = 0;
	while (i < lim)
	{
		if (checklist[i] == to_check)
			return (wahr);
		i++;
	}
	return (falsch);
}

t_bool	check_dup(t_dblstck *stack)
{
	void	*begin;
	int		*checklist;
	size_t	i;

	begin = &(*stack);
	stack = stack->next;
	i = 0;
	while (++i && (void *)stack != begin)
		stack = stack->next;
	checklist = (int *)malloc((i) * sizeof(int));
	if (checklist == NULL)
		return (wahr);
	checklist[0] = stack->num;
	stack = stack->next;
	i = 1;
	while ((void *)stack != begin)
	{
		if (find_int(checklist, stack->num, i))
			return (wahr);
		checklist[i++] = stack->num;
		stack = stack->next;
	}
	return (falsch);
}
