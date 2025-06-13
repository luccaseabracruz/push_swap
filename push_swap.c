/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:01:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/13 18:05:28 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"
#include <stdbool.h>

void	opt_moves(t_moves *moves)
{
	if (moves->ra >= moves->rb)
		moves->total = moves->ra + (moves->ra - moves->rb);
	else
		moves->total = moves->rb + (moves->rb - moves->ra);
	if (moves->total > moves->ra + moves->rrb)
	{
		moves->total = moves->ra + moves->rrb;
		moves->rev_b = 1;
	}
	if (moves->total > moves->rra + moves->rb)
	{
		moves->total = moves->rra + moves->rb;
		moves->rev_a = 1;
		moves->rev_b = 0;
	}
	if (moves->rra >= moves->rrb && moves->total > moves->rra + (moves->rra - moves->rrb))
	{
		moves->total = moves->rra + (moves->rra - moves->rrb);
		moves->rev_a = 1;
		moves->rev_b = 1;
	}
	if (moves->rrb >= moves->rra && moves->total > moves->rrb + (moves->rrb - moves->rra))
	{
			moves->total = moves->rrb + (moves->rrb - moves->rra);
			moves->rev_a = 1;
			moves->rev_b = 1;
	}
}

t_moves	calc_moves(t_stack *a, t_stack *b, int pos)
{
	t_moves moves;

	ft_memset(&moves, 0, sizeof(moves));
	moves.ra = pos;
	moves.rra = a->len - pos;
	while((moves.rb <= b->len) && (a->arr[pos] < b->arr[moves.rb]))
		moves.rb++;
	moves.rrb = b->len - moves.rb;
	if (moves.rrb == 0)
		moves.rb = 0;
	opt_moves(&moves);
	return (moves);
}

void	exec_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	while ((!moves->rev_a && !moves->rev_b) && (moves->ra && moves->rb))
	{
		rr(a, b);
		moves->ra--;
		moves->rb--;
	}
	while ((moves->rev_a && moves->rev_b) && (moves->rra && moves->rrb))
	{
		rrr(a, b);
		moves->rra--;
		moves->rrb--;
	}
	while (!moves->rev_a && moves->ra > 0)
	{
		ra(a);
		moves->ra--;
	}
	while (!moves->rev_b && moves->rb > 0)
	{
		rb(a);
		moves->rb--;
	}
	while (moves->rev_a && moves->rra > 0)
	{
		rra(a);
		moves->rra--;
	}
	while (moves->rev_b && moves->rrb > 0)
	{
		rrb(a);
		moves->rrb--;
	}
}

void	push_swap(t_stack *a, t_stack * b)
{
	t_moves	moves;
	t_moves	current_moves;
	int		i;

	push(a, b);
	push(a, b);
	while (a->len > 3)
	{
		moves = calc_moves(a, b, 0);
		i = 0;
		while (i < a->len)
		{
			current_moves = calc_moves(a, b, i);
			if (moves.total > current_moves.total)
				moves = current_moves;
			i++;
		}
		exec_moves(a, b, &moves);
		push(a, b);
	}
	sort_three(a);
}
