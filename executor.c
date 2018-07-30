/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:48:21 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/27 21:48:23 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

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

int		execute_ops(t_dblstck **astck, t_dblstck **bstck, char *op, t_bool rev)
{
	t_wraptor	ops[4];
	int			ind;

	ind = op[0] - 'p';
	ops[0] = &wrappush;
	ops[1] = NULL;
	ops[2] = &wraprotate;
	ops[3] = &wrapswap;
	if (ind > 3 || ind == 1)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (op[1] == 'a' || (op[1] == op[0] && op[0] != 'p'))
		ops[ind](astck, bstck, rev);
	if (op[1] == 'b' || (op[1] == op[0] && op[0] != 'p'))
		ops[ind](bstck, astck, rev);
	if (ft_strcmp(op, "sa") && ft_strcmp(op, "sb") && ft_strcmp(op, "ss") &&
		ft_strcmp(op, "ra") && ft_strcmp(op, "rb") && ft_strcmp(op, "rr") &&
		ft_strcmp(op, "pa") && ft_strcmp(op, "pb"))
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	return (0);
}

int		parse_ops(t_dblstck *astck, t_dblstck *bstck)
{
	int		check;
	char	*op;
	t_bool	rev;
	int		i;

	while ((check = get_next_line(0, &op)) > 0)
	{
		rev = falsch;
		if (ft_strlen(op) != 2 && ft_strlen(op) != 3)
		{
			ft_putendl_fd("Error", 2);
			free(op);
			return (1);
		}
		i = 0;
		if (op[i] == 'r' && op[i + 1] == 'r' && op[i + 2])
			rev = ++i;
		if (execute_ops(&astck, &bstck, op + i, rev) == -1)
		{
			free(op);
			return (-1);
		}
		free(op);
	}
	return (!check) ? stck_issorted(astck, bstck) : check;
}

int		main(int argc, char **argv)
{
	t_dblstck	*astck;
	t_dblstck	*bstck;

	astck = NULL;
	bstck = NULL;
	if (argc == 1 || (argc == 2 && ft_strisdigits(argv[1])))
	{
		ft_putendl("OK");
		return (0);
	}
	while (--argc)
	{
		if (!ft_strisdigits(argv[argc]))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		add(&astck, dblstck_new(ft_atoi(argv[argc])));
	}
	if (check_dup(astck))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (parse_ops(astck, bstck));
}
