/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:34:15 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/22 13:34:19 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_disorder(t_node *cur, int *mistakes, int *total)
{
	t_node	*ptr;
	int		m;
	int		t;

	m = 0;
	t = 0;
	ptr = cur->next;
	while (ptr)
	{
		if (cur->index > ptr->index)
			m++;
		t++;
		ptr = ptr->next;
	}
	*mistakes += m;
	*total += t;
}

static double	ft_disorder(t_stack *a)
{
	int		total_pairs;
	int		mistakes;
	t_node	*current;

	total_pairs = 0;
	mistakes = 0;
	current = a->top;
	while (current)
	{
		count_disorder(current, &mistakes, &total_pairs);
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

static void	dispatch_mode(t_stack *a, t_stack *b, double disorder)
{
	t_bench	*bench;

	bench = a->bench;
	if (bench->mode == 1)
	{
		set_strategy(bench, "Simple", "O(n^2)");
		selection_sort(a, b);
	}
	else if (bench->mode == 2)
	{
		set_strategy(bench, "Medium", "O(n*sqrt(n))");
		chunk_sort(a, b);
	}
	else if (bench->mode == 3)
	{
		set_strategy(bench, "Complex", "O(n*log(n))");
		radix_sort(a, b);
	}
	else
		adaptive_sort(a, b, disorder);
}

void	flag_orchestator(t_stack *a, t_stack *b)
{
	double	disorder;

	disorder = ft_disorder(a);
	if (disorder == 0.0)
	{
		set_strategy(a->bench, "None (already sorted)", "O(1)");
		benchmark(a->bench, disorder);
		return ;
	}
	if (a->total_nodes <= 5 && (a->bench->mode == 0 || a->bench->mode == 4))
	{
		set_strategy(a->bench, "Adaptive", "O(n^2)");
		small_sort(a, b);
	}
	else
		dispatch_mode(a, b, disorder);
	benchmark(a->bench, disorder);
}

void	adaptive_sort(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
	{
		set_strategy(a->bench, "Adaptive", "O(n^2)");
		selection_sort(a, b);
	}
	else if (disorder < 0.5)
	{
		set_strategy(a->bench, "Adaptive", "O(n*sqrt(n))");
		chunk_sort(a, b);
	}
	else
	{
		set_strategy(a->bench, "Adaptive", "O(n*log(n))");
		radix_sort(a, b);
	}
}
