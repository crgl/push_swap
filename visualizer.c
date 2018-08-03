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

void	find_extrema(t_dblstck *stck, long *min, long *max)
{
	t_dblstck	*start;

	start = stck;
	*min = (long)stck->num;
	*max = (long)stck->num;
	stck = stck->next;
	while (stck != start)
	{
		if ((long)stck->num < *min)
			*min = (long)stck->num;
		if ((long)stck->num > *max)
			*max = (long)stck->num;
		stck = stck->next;
	}
}

int		color_of(t_dblstck *stck)
{
	static long		min;
	static long		max;
	static t_bool	cached;

	if (!cached)
	{
		find_extrema(stck, &min, &max);
		cached = wahr;
	}
	return (20 + (32 * (stck->num - min)) / (max - min + 1));
}

void	clear_and_print(t_dblstck *astck, t_dblstck *bstck)
{
	t_dblstck	*atop;
	t_dblstck	*btop;
	int			color;
	int			width;

	usleep(5000);
	ft_printf("\033[2J\033[;H\033[?25l\n");
	atop = astck;
	btop = bstck;
	if (astck != NULL)
		astck->prev->next = NULL;
	if (bstck != NULL)
		bstck->prev->next = NULL;
	while (astck != NULL || bstck != NULL)
	{
		if (astck != NULL)
		{
			color = color_of(astck);
			width = 2 * ((color - 20) / 4) + 8;
			ft_printf("%*.i%{t}%{b}%*i\033[0m%*.i\t", (32 - width) / 2, 0, color, color, width,
				astck->num, (32 - width) / 2, 0);
			cleanup();
			astck = astck->next;
		}
		else
			ft_printf("%32.i\t", 0);
		if (bstck != NULL)
		{
			color = color_of(bstck);
			width = 2 * ((color - 20) / 4) + 8;
			ft_printf("%*.i%{t}%{b}%*i\033[0m%*.i\t\n", (32 - width) / 2, 0, color, color, width,
				bstck->num, (32 - width) / 2, 0);
			bstck = bstck->next;
		}
		else
			ft_printf("%12.i\t\t\n", 0);
	}
	if (atop != NULL)
		atop->prev->next = atop;
	if (btop != NULL)
		btop->prev->next = btop;
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
	return (0);
}

int		parse_ops(t_dblstck *astck, t_dblstck *bstck)
{
	int		check;
	char	*op;
	t_bool	rev;
	int		i;

	i = color_of(astck);
	clear_and_print(astck, bstck);
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
		clear_and_print(astck, bstck);
		free(op);
	}
	cleanup();
	return (!check) ? stck_issorted(astck, bstck) : check;
}

int		main(int argc, char **argv)
{
	t_dblstck	*astck;

	astck = NULL;
	if (argc == 1 || (argc == 2 && ft_isint(argv[1])))
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
	return (parse_ops(astck, NULL));
}
