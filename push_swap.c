/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:01:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/12 20:47:35 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"
#include <stdbool.h>

// void	optimize_moves(t_moves *moves)
// {
// 	bool	reverse_a;
// 	bool	reverse_b;

// 	reverse_a = moves->ra > moves->rra;
// 	reverse_b = moves->rb > moves->rrb;
// 	if (reverse_a != reverse_b)
// 	{
// 		if (moves->rra >= moves->rb && moves->rra - moves->rrb < moves->rb - moves->ra)
			
// 	}
// 	else
// 	{

// 	}
// }

void	optimize_moves(t_moves *moves)
{
	if (moves->rev_a == moves->rev_b && moves->a > moves->b)
		moves->total = moves->a;
	else if (moves->rev_a == moves->rev_b && moves->a < moves->b)
		moves->total = moves->b;
	else 
		moves->total = moves->a + moves->b;
	if (moves->rev_a)
	{
	}
	else if (moves->rev_b)
	{

	}
}

t_moves	*count_moves(t_stack *a, t_stack *b, int pos)
{
	t_moves *moves;

	ft_bzero(moves, sizeof(*moves));
	moves->a = pos;
	moves->rev_a = pos > (a->len / 2);
	if (moves->rev_a)
		moves->a = a->len - pos;
	while(a->arr[pos] < b->arr[moves->b])
		moves->b++;
	moves->rev_b = (moves->b) > (b->len / 2);
	if (moves->rev_b)
		moves->b = b->len - moves->b;
	
}

void	push_swap(t_stack *a, t_stack * b)
{
	t_moves	*moves;
	t_moves	*current_moves;
	int		i;

	i = 0;
	push(a, b);
	push(a, b);
	if (b->arr[0] < b->arr[1])
		sb(b);
	moves = count_moves(a, b, i);
	while (i < a->len)
	{
		current_moves = count_moves(a, b, i);
		if (moves->total > current_moves->total)
			moves = current_moves;
	}
	return (moves);
}
