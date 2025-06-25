/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:02:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 18:43:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	compare_input(char *input, char *operation)
{
	if (!ft_strncmp((const char *)input, (const char *)operation, ft_strlen(input)))
		return (1);
	else
		return (0);
}

static void	exec_single_move(t_stack *a, t_stack *b, char **move)
{
	if (compare_input(*move, "pa\n"))
		push(b, a);
	else if (compare_input(*move, "pb\n"))
		push(a, b);
	else if (compare_input(*move, "sa\n") || compare_input(*move, "ss\n"))
		swap(a);
	else if (compare_input(*move, "sb\n") || compare_input(*move, "ss\n"))
		swap(b);
	else if (compare_input(*move, "ra\n") || compare_input(*move, "rr\n"))
		rotate(a);
	else if (compare_input(*move, "rb\n") || compare_input(*move, "rr\n"))
		rotate(b);
	else if (compare_input(*move, "rra\n") || compare_input(*move, "rrr\n"))
		reverse_rotate(a);
	else if (compare_input(*move, "rrb\n") || compare_input(*move, "rrr\n"))
		reverse_rotate(b);
	else
	{
		ft_putstr_fd("Error\n", 1);
		free(a->arr);
		free(b->arr);
		free(*move);
		exit(0);
	}
}

static void	exec_all_moves(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (compare_input(move, "Error\n"))
		{
			free(a->arr);
			free(b->arr);
			free(move);
			exit(0);
		}
		exec_single_move(a, b, &move);
		free(move);
		move = get_next_line(0);
	}
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
