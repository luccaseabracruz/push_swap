/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:06:58 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 14:59:37 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->len;
	temp = stack->arr[i - 1];
	while (--i > 0)
		stack->arr[i] = stack->arr[i - 1];
	stack->arr[0] = temp;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putstr_fd(RRA, STD_OUT);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putstr_fd(RRB, STD_OUT);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd(RRR, STD_OUT);
}
