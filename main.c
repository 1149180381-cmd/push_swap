/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:00:38 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/15 12:14:08 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b, t_bench *bench)
{
	a->top = NULL;
	a->bottom = NULL;
	a->total_nodes = 0;
	a->bench = bench;
	b->top = NULL;
	b->bottom = NULL;
	b->total_nodes = 0;
	b->bench = bench;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;

	if (argc < 2)
		write_error();
	init_bench(&bench);
	init_stacks(&a, &b, &bench);
	ft_argv_checker(argc, argv, &bench);
	fill_nodes(argc, argv, &a);
	index_stack(&a);
	flag_orchestator(&a, &b);
	clear_nodes(&a);
	clear_nodes(&b);
	return (0);
}
