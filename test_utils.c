/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:53:39 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/16 18:09:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("A\n");
	ft_printf("-\n");
	while (i < stack->len)
	{
		ft_printf("%d\n", stack->arr[i]);
		i++;
	}
	ft_printf("\n\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("A | B\n");
	ft_printf("-----\n");
	while (i < a->len || i < b->len)
	{
		if (i < a->len)
			ft_printf("%d", a->arr[i]);
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (i < b->len)
			ft_printf("%d", b->arr[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}
