/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:02:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 18:48:26 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_equal(char *s1, char *s2)
{
	if (!ft_strncmp((const char *)s1, (const char *)s2, ft_strlen(s1)))
		return (1);
	else
		return (0);
}

static void	exec_single_move(t_stack *a, t_stack *b, char *move)
{
	if (is_equal(move, PA))
		push(b, a);
	else if (is_equal(move, PB))
		push(a, b);
	else if (is_equal(move, SA) || is_equal(move, SS))
		swap(a);
	else if (is_equal(move, SB) || is_equal(move, SS))
		swap(b);
	else if (is_equal(move, RA) || is_equal(move, RR))
		rotate(a);
	else if (is_equal(move, RB) || is_equal(move, RR))
		rotate(b);
	else if (is_equal(move, RRA) || is_equal(move, RRR))
		reverse_rotate(a);
	else if (is_equal(move, RRB) || is_equal(move, RRR))
		reverse_rotate(b);
}

static void	exec_all_moves(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(STD_IN);
	while (move && move[0])
	{
		exec_single_move(a, b, move);
		free(move);
		move = get_next_line(STD_IN);
	}
	if (move)
		free(move);
}

static bool	verify_stacks(t_stack *a, t_stack *b, int args_len)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	if (b->len != 0 || a->len != args_len)
		return (0);
	return (1);
}

void	checker(t_stack *a, t_stack *b, int args_len)
{
	exec_all_moves(a, b);
	if (verify_stacks(a, b, args_len))
		ft_putstr_fd(OK, STD_OUT);
	else
		ft_putstr_fd(KO, STD_OUT);
}
