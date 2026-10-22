/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:59:49 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/21 14:08:10 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	base_swap(a);
	count_movements(a, OP_SA);
	if (a->bench->print)
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (!b || !b->top || !b->top->next)
		return ;
	base_swap(b);
	count_movements(b, OP_SB);
	if (b->bench->print)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next)
		return ;
	if (!b || !b->top || !b->top->next)
		return ;
	base_swap(a);
	base_swap(b);
	count_movements(a, OP_SS);
	if (a->bench->print)
		ft_printf("ss\n");
}
