/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:03:13 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:27:28 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	char	*name;
	long	*arr;
	int		len;
}			t_stack;

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
t_moves	calc_moves(t_stack *a, t_stack *b, int pos);
size_t	arrlen(char **args);
void	sort_three(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	retrieve_numbers(t_stack *a, t_stack *b);

//Test functions
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);

#endif