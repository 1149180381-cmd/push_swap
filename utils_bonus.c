/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:12:15 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/04 12:12:17 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_zero2nl(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

void	init_bench_bonus(t_bench *bench)
{
	int	i;

	bench->enabled = 1;
	bench->mode = 0;
	bench->strategy_name = "Unknown";
	bench->complexity = "Unknown";
	bench->print = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		bench->op_count[i] = 0;
		i++;
	}
}

int	process_line(char **line, t_stack *a, t_stack *b)
{
	if (!execute_op(*line, a, b))
	{
		free(*line);
		return (0);
	}
	free(*line);
	*line = get_next_line(0);
	return (1);
}

void	starter(int *argc, char ***argv, t_bench *bench)
{
	char	*unsplited;

	unsplited = filter_argv(*argc, *argv);
	*argv = ft_split_mod(unsplited, ' ', argc);
	free(unsplited);
	init_bench_bonus(bench);
	if (!ft_argv_checker(*argc, *argv, bench))
	{
		clear_argv(*argc, *argv);
		write_error();
	}
}
