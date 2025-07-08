/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:02:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/08 14:14:44 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_equal(char *s1, char *s2)
{
	if (!ft_strncmp((const char *)s1, (const char *)s2, ft_strlen(s1)))
		return (1);
	else
		return (0);
}

static void	exec_combined(t_stack *a, t_stack *b, char *move)
{
	if (is_equal(move, SS))
	{
		swap(a);
		swap(b);
	}
	else if (is_equal(move, RR))
	{
		rotate(a);
		rotate(b);
	}
	else if (is_equal(move, RRR))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

static bool	exec_single_move(t_stack *a, t_stack *b, char *move)
{
	if (is_equal(move, PA))
		push(b, a);
	else if (is_equal(move, PB))
		push(a, b);
	else if (is_equal(move, SA))
		swap(a);
	else if (is_equal(move, SB))
		swap(b);
	else if (is_equal(move, RA))
		rotate(a);
	else if (is_equal(move, RB))
		rotate(b);
	else if (is_equal(move, RRA))
		reverse_rotate(a);
	else if (is_equal(move, RRB))
		reverse_rotate(b);
	else if (is_equal(move, SS) || is_equal(move, RR) || is_equal(move, RRR))
		exec_combined(a, b, move);
	else
		return (0);
	return (1);
}

static void	exec_all_moves(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(STD_IN);
	while (move && move[0])
	{
		if (!exec_single_move(a, b, move))
		{
			free(move);
			free(a->arr);
			free(b->arr);
			print_error(NULL);
			exit(1);
		}
		free(move);
		move = get_next_line(STD_IN);
	}
	if (move)
		free(move);
}

void	checker(t_stack *a, t_stack *b, int args_len)
{
	int	i;

	exec_all_moves(a, b);
	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
		{
			ft_putstr_fd(KO, STD_OUT);
			return ;
		}
		i++;
	}
	if (b->len != 0 || a->len != args_len)
		ft_putstr_fd(KO, STD_OUT);
	else
		ft_putstr_fd(OK, STD_OUT);
}
