/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:25:24 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:47:05 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	max_pos;
	int	i;

	max_pos = 0;
	i = 0;
	while (i < 3)
	{
		if (a->arr[i] > a->arr[max_pos])
			max_pos = i;
		i++;
	}
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	if (a->arr[0] > a->arr[1])
		sa(a);
}
