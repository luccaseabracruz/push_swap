/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 14:59:46 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->arr[0] && stack->arr[1])
	{
		temp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = temp;
	}
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd(SA, STD_OUT);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd(SB, STD_OUT);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd(SS, STD_OUT);
}
