/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:02:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 13:10:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static void	exec_single_move(t_stack *a, t_stack *b, char *move)
{
	if (!ft_strncmp((const char *)move, "pa\n", ft_strlen(move)))
		push(b, a);
	else if (!ft_strncmp((const char *)move, "pb\n", ft_strlen(move)))
		push(a, b);
	else if (!ft_strncmp((const char *)move, "sa\n", ft_strlen(move)))
		sa(a);
	else if (!ft_strncmp((const char *)move, "sb\n", ft_strlen(move)))
		sb(b);
	else if (!ft_strncmp((const char *)move, "ss\n", ft_strlen(move)))
		ss(a, b);
	else if (!ft_strncmp((const char *)move, "ra\n", ft_strlen(move)))
		ra(a);
	else if (!ft_strncmp((const char *)move, "rb\n", ft_strlen(move)))
		rb(b);
	else if (!ft_strncmp((const char *)move, "rr\n", ft_strlen(move)))
		rr(a, b);
	else if (!ft_strncmp((const char *)move, "rra\n", ft_strlen(move)))
		rra(a);
	else if (!ft_strncmp((const char *)move, "rrb\n", ft_strlen(move)))
		rrb(b);
	else if (!ft_strncmp((const char *)move, "rrr\n", ft_strlen(move)))
		rrr(a, b);
}

static void	exec_all_moves(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move && move[0])
	{
		if (!ft_strncmp((const char *)move, "Error\n", ft_strlen(move)))
		{
			free(move);
			exit(1) ;
		}
		exec_single_move(a, b, move);
		move = get_next_line(0);
	}
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
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}
