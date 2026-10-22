/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:25:40 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/21 14:25:42 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	execute_op2(char *line, t_stack *a, t_stack *b);

static int	execute_op(char *line, t_stack *a, t_stack *b)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (!ft_strncmp(line, "sa", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb", 3))
		sb(b);
	else if (!ft_strncmp(line, "ss", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb", 3))
		pb(a, b);
	else if (execute_op2(line, a, b) == 0)
		return (0);
	return (1);
}

static int	execute_op2(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "ra", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static void	clear_n_free_bonus(char *line, t_stack *a, t_stack *b)
{
	free(line);
	clear_nodes(a);
	clear_nodes(b);
	write_error();
	exit(1);
}

static void	finishing(t_stack *a, t_stack *b, int argc, char **argv)
{
	if (is_sorted(a) && b->total_nodes == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_argv(argc, argv);
	clear_nodes(a);
	clear_nodes(b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*line;

	argv = ft_split_mod(filter_argv(argc, argv), ' ', &argc);
	ft_argv_checker(argc, argv, &bench);
	init_bench_bonus(&bench);
	init_stacks(&a, &b, &bench);
	fill_nodes(argc, argv, &a);
	index_stack(&a);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!execute_op(line, &a, &b))
			clear_n_free_bonus(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	finishing(&a, &b, argc, argv);
	return (0);
}
