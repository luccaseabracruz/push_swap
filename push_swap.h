/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:03:13 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/13 16:15:32 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	char	*name;
	int		*arr;
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

void	push(t_stack *from, t_stack *to);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	push_swap(t_stack *a, t_stack * b);

size_t	arrlen(char **args);
bool	init_stacks(t_stack *a, t_stack *b, char **arr, int len);

#endif