/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:17:40 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/01 16:10:28 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->len > 1)
	{
		temp = stack->arr[0];
		i = 0;
		while (i < (stack->len - 1))
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[i] = temp;
	}
}

void	ra(t_stack *a)
{
	if (a->len > 1)
	{
		rotate(a);
		ft_putstr_fd(RA, STD_OUT);
	}
}

void	rb(t_stack *b)
{
	if (b->len > 1)
	{
		rotate(b);
		ft_putstr_fd(RB, STD_OUT);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->len > 1)
		rotate(a);
	if (b->len > 1)
		rotate(b);
	if (a->len > 1 || b->len > 1)
		ft_putstr_fd(RR, STD_OUT);
}
