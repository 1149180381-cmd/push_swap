/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_vol2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:23:03 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/08 13:23:05 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(int res, int nb);
static int	check_underflow(int res, int nb);

int	ft_atoi_mod(const char *str)
{
	int	res;
	int	neg;
	int	nb;

	res = 0;
	neg = 1;
	nb = 0;
	if (*str == '-')
	{
		neg = -neg;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		nb = *str - '0';
		if (neg == 1)
			res = check_overflow(res, nb);
		else
			res = check_underflow(res, nb);
		str++;
	}
	return (res);
}

static int	check_overflow(int res, int nb)
{
	if (res > (INT_MAX - nb) / 10)
		write_error();
	res = res * 10 + nb;
	return (res);
}

static int	check_underflow(int res, int nb)
{
	if (res < (INT_MIN + nb) / 10)
		write_error();
	res = res * 10 - nb;
	return (res);
}
