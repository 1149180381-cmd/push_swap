/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:39:26 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/15 11:44:28 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	base_reverse_rotate(a);
	count_movements(a, OP_RRA);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (!b || !b->top || !b->top->next)
		return ;
	base_reverse_rotate(b);
	count_movements(b, OP_RRB);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next || !b || !b->top || !b->top->next)
		return ;
	base_reverse_rotate(a);
	base_reverse_rotate(b);
	count_movements(a, OP_RRR);
	ft_printf("rrr\n");
}
