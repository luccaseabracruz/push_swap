/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:04:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/08 12:26:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>

static void	parse_tabulation(t_lisdp *lis, t_stack *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->len)
	{
		lis->dp[i] = 1;
		lis->prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a->arr[j] < a->arr[i] && lis->dp[j] + 1 > lis->dp[i])
			{
				lis->dp[i] = lis->dp[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		if (lis->dp[i] > lis->max_len)
		{
			lis->max_len = lis->dp[i];
			lis->lst_i = i;
		}
		i++;
	}
}

static void	parse_lis_stk(t_lisdp *lis, t_stack *lis_stk, t_stack *a)
{
	while (lis->lst_i != -1)
	{
		lis_stk->arr[(lis->max_len - 1) - lis_stk->len] = a->arr[lis->lst_i];
		lis->lst_i = lis->prev[lis->lst_i];
		lis_stk->len++;
	}
}

bool	init_lis(t_stack *lis_stk, t_stack *a)
{
	t_lisdp	lis;

	ft_memset(&lis, 0, sizeof(t_lisdp));
	lis.dp = ft_calloc((size_t)a->len, sizeof(int));
	if (!lis.dp)
		return (0);
	lis.prev = ft_calloc((size_t)a->len, sizeof(int));
	if (!lis.prev)
		return (free_return(lis.dp, 0));
	parse_tabulation(&lis, a);
	lis_stk->arr = ft_calloc((size_t)lis.max_len, sizeof(int));
	if (!lis_stk->arr)
	{
		free(lis.dp);
		return (free_return(lis.prev, 0));
	}
	lis_stk->len = 0;
	parse_lis_stk(&lis, lis_stk, a);
	free(lis.dp);
	free(lis.prev);
	return (1);
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
