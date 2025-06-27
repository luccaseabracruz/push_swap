/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:18 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 14:59:30 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack *from, t_stack *to)
{
	int	i;
	int	value;

	if (from->len <= 0)
		return ;
	value = from->arr[0];
	i = 0;
	from->len--;
	while (i < from->len)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	to->len++;
	i = to->len - 1;
	while (i > 0)
	{
		to->arr[i] = to->arr[i - 1];
		i--;
	}
	to->arr[0] = value;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd(PA, STD_OUT);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd(PB, STD_OUT);
}
