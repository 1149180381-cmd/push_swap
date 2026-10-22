/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:11:00 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/20 09:57:15 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	base_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (!first->next)
		stack->bottom = first;
}

void	base_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || !dst || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	if (!src->top)
		src->bottom = NULL;
	tmp->next = dst->top;
	dst->top = tmp;
	if (!tmp->next)
		dst->bottom = tmp;
	src->total_nodes -= 1;
	dst->total_nodes += 1;
}

void	base_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->bottom;
	last->next = first;
	stack->top = first->next;
	first->next = NULL;
	stack->bottom = first;
}

void	base_reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	stack->bottom = prev;
}
