/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:46:30 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/21 14:07:52 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->top)
		return ;
	base_push(a, b);
	count_movements(a, OP_PA);
	if (a->bench->print)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top)
		return ;
	base_push(b, a);
	count_movements(a, OP_PB);
	if (a->bench->print)
		ft_printf("pb\n");
}
