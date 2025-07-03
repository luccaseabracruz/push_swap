/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:53:39 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/03 12:40:12 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("A\n");
	printf("-\n");
	while (i < stack->len)
	{
		printf("%d\n", stack->arr[i]);
		i++;
	}
	printf("\n\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("A | B\n");
	printf("-----\n");
	while (i < a->len || i < b->len)
	{
		if (i < a->len)
			printf("%d", a->arr[i]);
		else
			printf(" ");
		printf(" | ");
		if (i < b->len)
			printf("%d", b->arr[i]);
		printf("\n");
		i++;
	}
	printf("\n\n");
}
