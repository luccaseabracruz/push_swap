/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:01:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/07 20:59:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <limits.h>

static t_moves	find_cheapest(t_stack *a, t_stack *b, t_stack *lis)
{
	t_moves	moves;
	t_moves	current_moves;
	int		i;

	i = -1;
	moves.total = INT_MAX;
	while (++i < a->len)
	{
		if (is_in_lis(a->arr[i], lis))
			continue ;
		current_moves = calc_moves(a, b, i);
		if (moves.total > current_moves.total)
			moves = current_moves;
	}
	return (moves);
}

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

#include <stdio.h>
void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("A | LIS\n");
	printf("-----\n");
	while (i < a->len || i < b->len)
	{
		if (i < a->len)
			printf("%d", a->arr[i]);
		else
			printf(" ");
		printf(" | ");
		if (i < b->len)
			printf("%d",  b->arr[i]);
		printf("\n");
		i++;
	}
	printf("\n\n");
}

void	push_swap(t_stack *a, t_stack *b, t_stack *lis)
{
	t_moves	moves;

	while (a->len > 3 && b-> len < 2 && !is_sorted(a) && a->len > lis->len)
	{
		if (is_in_lis(a->arr[0], lis))
			ra(a);
		else
			pb(a, b);
	}
	while (a->len > 3 && !is_sorted(a) && a->len > lis->len)
	{
		moves = find_cheapest(a, b, lis);
		exec_moves(a, b, &moves);
		pb(a, b);
	}
	if (a->len == 3)
		sort_three(a);
	retrieve_numbers(a, b);
	smaller_to_top(a);
}
