/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:04:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/04 17:18:23 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	get_lis(t_stack *lis, t_stack *stack)
{
	int		i;
	int		j;

	lis->arr[0] = 0;
	lis->len = 1;
	i = 0;
	while (++i < stack->len)
	{
		if (stack->arr[i] > stack->arr[lis->arr[lis->len - 1]])
			lis->arr[lis->len++] = i;
		else
		{
			j = 0;
			while (j < lis->len && stack->arr[i] > stack->arr[lis->arr[j]])
				j++;
			lis->arr[j] = i;
			lis->len = j + 1;
		}
	}
	i = 0;
	while (i < lis->len)
	{
		lis->arr[i] = stack->arr[lis->arr[i]];
		i++;
	}
}

bool	is_in_lis(int n, t_stack *lis)
{
	int	i;

	i = 0;
	while (i < lis->len)
	{
		if (n == lis->arr[i])
			return (1);
		i++;
	}
	return (0);
}
