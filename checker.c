/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:02:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/26 16:23:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

static bool	exec_single_move(t_stack *a, t_stack *b, char *move)
{
	if (is_equal(move, "pa\n"))
		push(b, a);
	else if (is_equal(move, "pb\n"))
		push(a, b);
	else if (is_equal(move, "sa\n") || is_equal(move, "ss\n"))
		swap(a);
	else if (is_equal(move, "sb\n") || is_equal(move, "ss\n"))
		swap(b);
	else if (is_equal(move, "ra\n") || is_equal(move, "rr\n"))
		rotate(a);
	else if (is_equal(move, "rb\n") || is_equal(move, "rr\n"))
		rotate(b);
	else if (is_equal(move, "rra\n") || is_equal(move, "rrr\n"))
		reverse_rotate(a);
	else if (is_equal(move, "rrb\n") || is_equal(move, "rrr\n"))
		reverse_rotate(b);
	else if (is_equal(move, "\n"))
		return (1);
	else
		return (0);
	return (1);
}

static void	exec_all_moves(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move && move[0])
	{
		if (!exec_single_move(a, b, move))
		{
			free(move);
			free(a->arr);
			free(b->arr);
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		free(move);
		move = get_next_line(0);
	}
	if (move)
		free(move);
}

static bool	verify_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	if (b->len != 0 || b->arr[0] != 0)
		return (0);
	return (1);
}

void	checker(t_stack *a, t_stack *b)
{
	exec_all_moves(a, b);
	if (verify_stacks(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
