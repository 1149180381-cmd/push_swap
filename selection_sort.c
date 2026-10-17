/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:21:49 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/15 10:04:49 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	pos;

	i = 0;
	while (a->top != NULL)
	{
		pos = find_index_position(a, i);
		if (a->top->index != i && (a->total_nodes / 2) >= pos)
			ra(a);
		else if (a->top->index != i && (a->total_nodes / 2) < pos)
			rra(a);
		else
		{
			pb(a, b);
			i++;
		}
	}
	while (b->top != NULL)
		pa(a, b);
	return ;
}
