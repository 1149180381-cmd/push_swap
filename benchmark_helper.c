/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:27:46 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/17 14:27:49 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_strategy(t_bench *bench, const char *name, const char *complexity)
{
	if (!bench)
		return ;
	bench->strategy_name = name;
	bench->complexity = complexity;
}

void	count_movements(t_stack *s, int op_id)
{
	if (!s || !s->bench || op_id < 0 || op_id >= OP_COUNT)
		return ;
	s->bench->op_count[op_id]++;
}

void	put_percent_2(int fd, double disorder)
{
	long	centi;
	long	frac;

	if (disorder < 0.0)
		disorder = 0.0;
	if (disorder > 1.0)
		disorder = 1.0;
	centi = (long)(disorder * 10000.0 + 0.5);
	ft_putnbr_fd(centi / 100, fd);
	write(fd, ".", 1);
	frac = centi % 100;
	if (frac < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(frac, fd);
	write(fd, "%\n", 2);
}

void	init_bench(t_bench *bench)
{
	int	i;

	bench->enabled = 0;
	bench->mode = 0;
	bench->strategy_name = "Unknown";
	bench->complexity = "Unknown";
	bench->print = 1;
	i = 0;
	while (i < OP_COUNT)
	{
		bench->op_count[i] = 0;
		i++;
	}
}
