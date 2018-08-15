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

char	**maybe_split(char **argv, int *aargc)
{
	int		count;
	char	**out;

	count = 0;
	if (*aargc > 2)
	{
		out = ft_memalloc((*aargc) * sizeof(char *));
		while (++count < *aargc)
			out[count - 1] = ft_strdup(argv[count]);
		count--;
	}
	else
	{
		out = ft_strsplit(argv[1], ' ');
		while (out[count])
			count++;
	}
	*aargc = count;
	return (out);
}

void	free_av(char **av)
{
	char	**tmp;

	tmp = av;
	while (*tmp)
		free(*tmp++);
	free(av);
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

t_bool	find_int(int *checklist, int to_check, size_t lim)
{
	size_t	i;

	i = 0;
	while (i < lim)
	{
		if (checklist[i] == to_check)
		{
			free(checklist);
			return (wahr);
		}
		i++;
	}
	return (falsch);
}

t_bool	check_dup(t_dblstck *stack)
{
	t_dblstck	*begin;
	int			*checklist;
	size_t		i;

	if ((begin = stack) == NULL)
		return (wahr);
	stack = stack->next;
	i = 0;
	while (++i && stack != begin)
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
	free(checklist);
	return (falsch);
}
