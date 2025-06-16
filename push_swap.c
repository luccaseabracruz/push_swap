/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:01:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/16 22:36:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"
#include <stdbool.h>

static void	exec_combined(t_stack *a, t_stack *b, t_moves *moves)
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
}

static void	exec_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	exec_combined(a, b, moves);
	while (!moves->rev_a && moves->ra)
	{
		ra(a);
		moves->ra--;
	}
	while (!moves->rev_b && moves->rb)
	{
		rb(b);
		moves->rb--;
	}
	while (moves->rev_a && moves->rra)
	{
		rra(a);
		moves->rra--;
	}
	while (moves->rev_b && moves->rrb)
	{
		rrb(b);
		moves->rrb--;
	}
}

static void	smaller_to_top(t_stack *a)
{
	int	i;
	int	smaller_pos;

	i = 0;
	smaller_pos = 0;
	while (i < a->len)
	{
		if (a->arr[i] < a->arr[smaller_pos])
			smaller_pos = i;
		i++;
	}
	if (smaller_pos <= a->len / 2)
		while (smaller_pos-- > 0)
			ra(a);
	else
		while (smaller_pos++ < a->len)
			rra(a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_moves	moves;
	t_moves	current_moves;
	int		i;

	push(a, b);
	push(a, b);
	while (a->len > 3)
	{
		moves = calc_moves(a, b, 0);
		i = 1;
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
	retrieve_numbers(a, b);
	smaller_to_top(a);
}
