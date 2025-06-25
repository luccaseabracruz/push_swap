/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:19:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:53:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	opt_rr(t_moves *moves)
{
	int	cost;

	cost = moves->rrb + (moves->rra - moves->rrb);
	if (moves->rra >= moves->rrb && moves->total > cost)
	{
		moves->total = cost;
		moves->rev_a = 1;
		moves->rev_b = 1;
	}
	cost = moves->rra + (moves->rrb - moves->rra);
	if (moves->rrb >= moves->rra && moves->total > cost)
	{
		moves->total = cost;
		moves->rev_a = 1;
		moves->rev_b = 1;
	}
}

static void	opt_moves(t_moves *moves)
{
	int	cost;

	if (moves->ra >= moves->rb)
		moves->total = moves->rb + (moves->ra - moves->rb);
	else
		moves->total = moves->ra + (moves->rb - moves->ra);
	cost = moves->ra + moves->rrb;
	if (moves->total > cost)
	{
		moves->total = cost;
		moves->rev_b = 1;
	}
	cost = moves->rra + moves->rb;
	if (moves->total > cost)
	{
		moves->total = cost;
		moves->rev_a = 1;
		moves->rev_b = 0;
	}
	opt_rr(moves);
}

static int	find_best_pos(int n, t_stack *stack)
{
	int	i;
	int	best_pos;
	int	biggest_pos;

	best_pos = 0;
	biggest_pos = 0;
	i = 1;
	while (i < stack->len)
	{
		while ((best_pos < stack->len) && (stack->arr[best_pos] > n))
			best_pos++;
		if (stack->arr[i] > stack->arr[biggest_pos])
			biggest_pos = i;
		if ((stack->arr[i] < n) && (stack->arr[i] > stack->arr[best_pos]))
			best_pos = i;
		i++;
	}
	if (best_pos == stack->len)
		return (biggest_pos);
	return (best_pos);
}

t_moves	calc_moves(t_stack *a, t_stack *b, int pos)
{
	t_moves	moves;

	ft_memset(&moves, 0, sizeof(moves));
	moves.ra = pos;
	moves.rra = a->len - pos;
	moves.rb = find_best_pos(a->arr[pos], b);
	moves.rrb = b->len - moves.rb;
	opt_moves(&moves);
	return (moves);
}
