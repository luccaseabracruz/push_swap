/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:04:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/07 15:04:30 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_lisdp
{
	int	max_value;
	int	len;
	int	*dp;
	int	*prev;
}			t_lisdp;

bool	get_lis(t_stack *lis_stack, t_stack *stack)
{
	t_lisdp	lis;
	int		i;
	int		j;

	lis.dp = ft_calloc(stack->len, sizeof(int));
	if (!lis.dp)
		return (0);
	lis.dp = ft_calloc(stack->len, sizeof(int));
	if (!lis.prev)
		return (free_return(lis.dp, 0));
	ft_memset(&lis, 0, sizeof(t_lisdp));
	i = 0;
	// lis.dp[i] = 0;
	lis.prev[i] = -1;
	while (i < stack->len)
	{
		j = 0;
		while (j < i)
		{
			if (stack->arr[j] < stack->arr[i] && lis.dp[j] + 1 > lis.dp[i])

		}
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
