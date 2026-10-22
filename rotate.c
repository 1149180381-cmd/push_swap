/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:11:33 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/21 14:08:16 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	base_rotate(a);
	count_movements(a, OP_RA);
	if (a->bench->print)
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b || !b->top || !b->top->next)
		return ;
	base_rotate(b);
	count_movements(b, OP_RB);
	if (b->bench->print)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next || !b || !b->top || !b->top->next)
		return ;
	base_rotate(a);
	base_rotate(b);
	count_movements(a, OP_RR);
	if (a->bench->print)
		ft_printf("rr\n");
}
