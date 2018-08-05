/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:51:28 by cgleason          #+#    #+#             */
/*   Updated: 2018/08/01 20:51:44 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int		execute_ops(t_dblstck **astck, t_dblstck **bstck, char *op, t_bool rev)
{
	t_wraptor	ops[4];
	int			ind;

	ind = op[0] - 'p';
	ops[0] = &wrappush;
	ops[2] = &wraprotate;
	ops[3] = &wrapswap;
	if (ind > 3 || ind == 1 || ind < 0)
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
	clear_and_print(*astck, *bstck);
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
			free_stack_ops(&astck, &bstck, op);
			return (1);
		}
		i = 0;
		if (op[i] == 'r' && op[i + 1] == 'r' && op[i + 2])
			rev = ++i;
		if (execute_ops(&astck, &bstck, op + i, rev) == -1)
		{
			free_stack_ops(&astck, &bstck, op);
			return (-1);
		}
		free(op);
	}
	return (!check) ? stck_issorted(astck, bstck) : check;
}

int		main(int argc, char **argv)
{
	t_dblstck	*astck;

	astck = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && ft_isint(argv[1]))
	{
		ft_putendl("OK");
		return (0);
	}
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
	(void)color_of(astck);
	return (parse_ops(astck, NULL));
}
