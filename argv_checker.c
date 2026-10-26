/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:37:08 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/20 09:49:56 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_str_is_num(char *str);

static void	parse_mode(char *flag, t_bench *bench, int *matched)
{
	*matched = 1;
	if (!ft_strncmp(flag, "--simple", 42))
		bench->mode = 1;
	else if (!ft_strncmp(flag, "--medium", 42))
		bench->mode = 2;
	else if (!ft_strncmp(flag, "--complex", 42))
		bench->mode = 3;
	else if (!ft_strncmp(flag, "--adaptive", 42))
		bench->mode = 4;
	else
		*matched = 0;
}

static int	parse_flag(char *flag, t_bench *bench, int *dif, int *bflag)
{
	int	matched;

	parse_mode(flag, bench, &matched);
	if (matched)
	{
		(*dif)++;
	}
	else if (!ft_strncmp(flag, "--bench", 42))
	{
		(*bflag)++;
		bench->enabled = 1;
	}
	else
		return (0);
	if (*dif > 1 || *bflag > 1)
		return (0);
	return (1);
}

static int	check_dups(int i, int argc, char **argv)
{
	int	j;

	j = i;
	while (++j < argc)
	{
		if (argv[j][0] == '-' && argv[j][1] == '-' && ft_isalpha(argv[j][2]))
			continue ;
		if (!ft_str_is_num(argv[j]))
			return (0);
		if (ft_atoi_mod(argv[i]) == ft_atoi_mod(argv[j]))
			return (0);
	}
	return (1);
}

int	ft_argv_checker(int argc, char **argv, t_bench *bench)
{
	int	i;
	int	dif_flag;
	int	bench_flag;

	dif_flag = 0;
	bench_flag = 0;
	i = 0;
	while (i++ < (argc - 1))
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
		{
			if (!parse_flag(argv[i], bench, &dif_flag, &bench_flag))
				return (0);
		}
		else
		{
			if (!ft_str_is_num(argv[i]))
				return (0);
			if (!check_dups(i, argc, argv))
				return (0);
		}
	}
	return (1);
}

static int	ft_str_is_num(char *str)
{
	size_t	j;

	j = 0;
	if (str[0] == '\0' || ((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
		return (0);
	while (str[j])
	{
		if ((str[j] == '-' || str[j] == '+') && j == 0)
			j++;
		if (!ft_isdigit(str[j++]))
			return (0);
	}
	return (1);
}
