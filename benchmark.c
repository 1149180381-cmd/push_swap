/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:24:25 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/17 14:24:25 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_header(int fd, t_bench *bench, double disorder)
{
	ft_putstr_fd("=== BENCHMARK ===\n", fd);
	ft_putstr_fd("Disorder: ", fd);
	put_percent_2(fd, disorder);
	ft_putstr_fd("Strategy: ", fd);
	ft_putstr_fd(bench->strategy_name, fd);
	ft_putstr_fd(" / ", fd);
	ft_putstr_fd(bench->complexity, fd);
	ft_putstr_fd("\n", fd);
}

static void	print_total(int fd, t_bench *bench)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += bench->op_count[i];
		i++;
	}
	ft_putstr_fd("Total operations: ", fd);
	ft_putnbr_fd(total, fd);
	ft_putstr_fd("\n", fd);
}

static void	print_ops(int fd, t_bench *bench)
{
	char	*names[OP_COUNT];
	int		i;

	i = 0;
	names = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	while (i < OP_COUNT)
	{
		ft_putstr_fd(names[i], fd);
		ft_putstr_fd(": ", fd);
		ft_putnbr_fd(bench->op_count[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}

void	benchmark(t_bench *bench, double disorder)
{
	if (!bench || !bench->enabled)
		return ;
	print_header(2, bench, disorder);
	print_total(2, bench);
	print_ops(2, bench);
}
