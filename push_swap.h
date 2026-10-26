/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:20:46 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/15 12:32:37 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
};

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int			enabled;
	int			mode;
	int			print;
	long		op_count[OP_COUNT];
	const char	*strategy_name;
	const char	*complexity;
}	t_bench;

typedef struct s_stack
{
	t_node	*bottom;
	t_node	*top;
	int		total_nodes;
	t_bench	*bench;
}	t_stack;

int		ft_atoi_mod(const char *str);
int		is_sorted(t_stack *a);
int		get_bit(int index, int bit);
int		find_index_position(t_stack *stack, int i);
int		ft_argv_checker(int argc, char **argv, t_bench *bench);
char	**ft_split_mod(char const *s, char c, int *argc);
void	clear_argv(int argc, char **argv);
void	init_stacks(t_stack *a, t_stack *b, t_bench *bench);
char	*filter_argv(int argc, char **argv);
void	put_percent_2(int fd, double disorder);
void	small_sort(t_stack *a, t_stack *b);
void	count_movements(t_stack *s, int op_id);
void	clear_n_error(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	selection_sort(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	write_error(void);
void	radix_sort(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	index_stack(t_stack *stack);
void	base_swap(t_stack *stack);
void	base_push(t_stack *dst, t_stack *src);
void	base_rotate(t_stack *stack);
void	base_reverse_rotate(t_stack *stack);
void	benchmark(t_bench *bench, double disorder);
void	flag_orchestator(t_stack *a, t_stack *b);
void	adaptive_sort(t_stack *a, t_stack *b, double disorder);
void	clear_nodes(t_stack *stack);
void	fill_nodes(int argc, char **argv, t_stack *stack);
void	chunk_sort(t_stack *a, t_stack *b);
void	init_bench(t_bench *bench);
void	set_strategy(t_bench *bench, const char *name, const char *complexity);

#endif
