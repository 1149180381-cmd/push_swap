/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:50:57 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/22 14:50:59 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b, t_bench *bench)
{
	a->top = NULL;
	a->bottom = NULL;
	a->total_nodes = 0;
	a->bench = bench;
	b->top = NULL;
	b->bottom = NULL;
	b->total_nodes = 0;
	b->bench = bench;
}

static char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = ft_strlen(s1) + 1 + ft_strlen(s2) + 1;
	i = 0;
	dest = malloc(len);
	if (!dest)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	dest[i++] = ' ';
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*filter_argv(int argc, char **argv)
{
	int		i;
	char	*new_argv;
	char	*tmp;

	i = 0;
	new_argv = ft_strjoin_mod(argv[i], "");
	i++;
	while (i < argc)
	{
		tmp = new_argv;
		new_argv = ft_strjoin_mod(new_argv, argv[i]);
		free(tmp);
		i++;
	}
	return (new_argv);
}

void	clear_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
