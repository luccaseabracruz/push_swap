/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:29:31 by lseabra-         ###   ########.fr       */
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
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
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