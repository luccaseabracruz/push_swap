/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:01:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/08 13:27:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>

static void	exec_reverse(t_stack *a, t_stack *b, t_moves *moves)
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
	exec_reverse(a, b, moves);
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

bool	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b, t_stack *lis)
{
	t_moves	moves;
	int		max_len;

	max_len = a->len;
	while (a->len > 3 && b->len < 2 && !is_sorted(a))
	{
		if ((max_len > 5) && is_in_lis(a->arr[0], lis))
			ra(a);
		else
			pb(a, b);
	}
	while (a->len > 3 && !is_sorted(a) && a->len > lis->len)
	{
		moves = find_cheapest(a, b, lis, max_len);
		exec_moves(a, b, &moves);
		pb(a, b);
	}
	if (a->len == 3)
		sort_three(a);
	retrieve_numbers(a, b);
	smaller_to_top(a);
}
