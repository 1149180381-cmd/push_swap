/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                              	        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:09:23 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/04 12:09:24 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "push_swap.h"

void	init_bench_bonus(t_bench *bench);
size_t	ft_zero2nl(char const *str, char c);
char	*get_next_line(int fd);
int		process_line(char **line, t_stack *a, t_stack *b);
int		execute_op(char *line, t_stack *a, t_stack *b);
void	starter(int *argc, char ***argv, t_bench *bench);
#endif
