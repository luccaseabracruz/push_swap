/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/01 16:14:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len > 1)
	{
		temp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = temp;
	}
}

void	sa(t_stack *a)
{
	if (a->len > 1)
	{
		swap(a);
		ft_putstr_fd(SA, STD_OUT);
	}
}

void	sb(t_stack *b)
{
	if (b->len > 1)
	{
		swap(b);
		ft_putstr_fd(SB, STD_OUT);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->len > 1)
		swap(a);
	if (b->len > 1)
		swap(b);
	if (a->len > 1 || b->len > 1)
		ft_putstr_fd(SS, STD_OUT);
}
