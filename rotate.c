/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:17:40 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/30 13:48:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->arr[0];
	i = 0;
	while (i < (stack->len - 1))
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = temp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd(RA, STD_OUT);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd(RB, STD_OUT);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd(RR, STD_OUT);
}
