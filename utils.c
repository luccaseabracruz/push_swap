/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:21:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/29 16:54:49 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"

int	init_stacks(t_stack *a, t_stack *b, char **arr, int len)
{
	int	i;

	a->arr = (int *)ft_calloc(len, sizeof(int));
	if (!a->arr)
		return (0);
	b->arr = (int *)ft_calloc(len, sizeof(int));
	if (!b->arr)
	{
		free(a);
		return (0);
	}
	a->len = len;
	b->len = 0;
	a->name = "a";
	b->name = "b";
	i = 0;
	while (i < len)
	{
		a->arr[i] = ft_atoi(arr[i]);
		i++;
	}
	return (1);
}
