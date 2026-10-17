/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:46:30 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/15 11:39:48 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->top)
		return ;
	base_push(a, b);
	count_movements(a, OP_PA);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top)
		return ;
	base_push(b, a);
	count_movements(a, OP_PB);
	ft_printf("pb\n");
}
