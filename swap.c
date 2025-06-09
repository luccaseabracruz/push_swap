/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/29 18:07:10 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static void	swap(t_stack *stack)
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
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	int	arr[argc - 1];
// 	int	i;
// 	if (argc >=2)
// 	{
// 		i = 0;
// 		printf("Old version: \n");
// 		while (i < argc - 1)
// 		{
// 			arr[i] = atoi(argv[i + 1]);
// 			printf("p[%d]: %d\n", i, arr[i]);
// 			i++;
// 		}
// 		swap(arr);
// 		i = 0;
// 		printf("New version: \n");
// 		while (i < argc - 1)
// 		{
// 			printf("p[%d]: %d\n", i, arr[i]);
// 			i++;
// 		}
// 	}
// }