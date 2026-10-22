/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:00:38 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/20 09:55:33 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;

	argv = ft_split_mod(filter_argv(argc, argv), ' ', &argc);
	init_bench(&bench);
	init_stacks(&a, &b, &bench);
	ft_argv_checker(argc, argv, &bench);
	fill_nodes(argc, argv, &a);
	index_stack(&a);
	flag_orchestator(&a, &b);
	clear_argv(argc, argv);
	clear_nodes(&a);
	clear_nodes(&b);
	return (0);
}
