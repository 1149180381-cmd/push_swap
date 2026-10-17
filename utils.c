/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:07:26 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/08 13:07:28 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	int		i;
	t_node	*ptr;

	i = 0;
	ptr = a->top;
	while (ptr)
	{
		if (ptr->index != i)
			return (0);
		i++;
		ptr = ptr->next;
	}
	return (1);
}

int	find_index_position(t_stack *stack, int i)
{
	int		finder;
	t_node	*ptr;

	finder = 0;
	ptr = stack->top;
	while (ptr)
	{
		if (ptr->index == i)
			return (finder);
		finder++;
		ptr = ptr->next;
	}
	return (-1);
}

void	clear_n_error(t_stack *a)
{
	clear_nodes(a);
	write_error();
}

int	get_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}
