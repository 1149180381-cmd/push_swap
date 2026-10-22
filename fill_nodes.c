/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:04:52 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/19 10:23:00 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_nodes(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
	}
	stack->bottom = NULL;
	stack->total_nodes = 0;
}

static t_node	*ft_nodenew(int value, t_stack *stack)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		clear_nodes(stack);
		write_error();
	}
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static void	put_to_stack(t_node *node, t_stack *stack)
{
	stack->bottom->next = node;
	stack->bottom = node;
}

void	fill_nodes(int argc, char **argv, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i++ < (argc - 1))
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
			continue ;
		tmp = ft_nodenew(ft_atoi_mod(argv[i]), stack);
		if (!stack->top)
		{
			stack->top = tmp;
			stack->bottom = tmp;
		}
		else
			put_to_stack(tmp, stack);
		stack->total_nodes++;
	}
}
