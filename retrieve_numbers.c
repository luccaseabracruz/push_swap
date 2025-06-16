/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:24:14 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/16 20:27:13 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_best_pos(int n, t_stack *stack)
{
	int	i;
	int	best_pos;
	int	smallest_pos;

	best_pos = 0;
	smallest_pos = 0;
	i = 1;
	while (i < stack->len)
	{
		while ((best_pos < stack->len) && (stack->arr[best_pos] < n))
			best_pos++;
		if (stack->arr[i] < stack->arr[smallest_pos])
			smallest_pos = i;
		if (stack->arr[i] > n && stack->arr[i] < stack->arr[best_pos])
			best_pos = i;
		i++;
	}
	if (best_pos == stack->len)
		return (smallest_pos);
	return (best_pos);
}

void retrieve_numbers(t_stack *a, t_stack *b)
{
	int	best_pos;
	int	i;
	
	while (b->len > 0)
	{
		best_pos = find_best_pos(b->arr[0], a);
		i = 0;
		if (best_pos <= (a->len / 2))
		{
			while (i++ < best_pos)
				ra(a);
		}
		else
		{
			while (i++ < a->len - best_pos)
				rra(a);
		}
		push(b, a);
	}
}
