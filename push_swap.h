/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:03:13 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/08 14:31:42 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stddef.h>

# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# define ERROR "Error"

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

typedef struct s_stack
{
	int		*arr;
	int		len;
}			t_stack;

typedef struct s_lisdp
{
	int	max_len;
	int	lst_i;
	int	*dp;
	int	*prev;
}			t_lisdp;

typedef struct moves
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	bool	rev_a;
	bool	rev_b;
	int		total;
}			t_moves;

bool	init_stacks(t_stack *a, t_stack *b, char **arr, int len);
long	ft_atol(const char *nptr);
void	push(t_stack *from, t_stack *to);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
t_moves	find_cheapest(t_stack *a, t_stack *b, t_stack *lis, int max_len);
size_t	arrlen(char **args);
void	sort_three(t_stack *a);
void	push_swap(t_stack *a, t_stack *b, t_stack *lis);
void	retrieve_numbers(t_stack *a, t_stack *b);
bool	free_strarr(char **arr, bool boolean);
bool	free_return(void *ptr, bool boolean);
void	print_error(char *message);
bool	is_sorted(t_stack *a);
bool	is_in_lis(int pos, t_stack *lis);
bool	init_lis(t_stack *lis, t_stack *a);

#endif