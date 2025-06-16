/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:19:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/16 19:51:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"

static void	opt_moves(t_moves *moves)
{
	if (moves->ra >= moves->rb)
		moves->total = moves->rb + (moves->ra - moves->rb);
	else
		moves->total = moves->ra + (moves->rb - moves->ra);
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
	if (moves->rra >= moves->rrb && moves->total > moves->rrb + (moves->rra - moves->rrb))
	{
		moves->total = moves->rrb + (moves->rra - moves->rrb);
		moves->rev_a = 1;
		moves->rev_b = 1;
	}
	if (moves->rrb >= moves->rra && moves->total > moves->rra + (moves->rrb - moves->rra))
	{
			moves->total = moves->rra + (moves->rrb - moves->rra);
			moves->rev_a = 1;
			moves->rev_b = 1;
	}
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
	t_moves moves;

	ft_memset(&moves, 0, sizeof(moves));
	moves.ra = pos;
	moves.rra = a->len - pos;
	moves.rb = find_best_pos(a->arr[pos], b);
	moves.rrb = b->len - moves.rb;
	opt_moves(&moves);
	return (moves);
}

// #include "ft_printf/ft_printf.h"
// int	main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	int	best_pos;

// 	if (argc > 1)
// 	{
// 		if (!init_stacks(&a, &b, (argv + 1), arrlen(argv + 1)))
// 			return (1);
// 		push(&a, &b);
// 		push(&a, &b);
// 		print_stacks(&a, &b);
// 		best_pos = find_best_pos(a.arr[0], &b);
// 		ft_printf("best position for %d is %s[%d]\n", a.arr[0], b.name, best_pos);
// 	}
// }