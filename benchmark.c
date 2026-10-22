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
	ft_putstr_fd("[bench] disorder:  ", fd);
	put_percent_2(fd, disorder);
	ft_putstr_fd("[bench] strategy:  ", fd);
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
	ft_putstr_fd("[bench] total_ops:  ", fd);
	ft_putnbr_fd(total, fd);
	ft_putstr_fd("\n", fd);
}

static void	printer_ops(const char **names, int *i, int fd, t_bench *bench)
{
	ft_putstr_fd(names[*i], fd);
	ft_putstr_fd(":  ", fd);
	ft_putnbr_fd(bench->op_count[*i], fd);
	ft_putstr_fd("  ", fd);
	*i += 1;
}

static void	print_ops(int fd, t_bench *bench)
{
	const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"
	};
	int			i;

	i = 0;
	ft_putstr_fd("[bench] ", fd);
	while (i < 5)
		printer_ops(names, &i, fd, bench);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("[bench] ", fd);
	while (i < OP_COUNT)
		printer_ops(names, &i, fd, bench);
	ft_putstr_fd("\n", fd);
}

void	benchmark(t_bench *bench, double disorder)
{
	if (!bench || !bench->enabled)
		return ;
	print_header(2, bench, disorder);
	print_total(2, bench);
	print_ops(2, bench);
}
