/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_inc_seq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:04:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/03 19:45:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_lis(t_stack *stack, int pos)
{
	int	cur_num;
	int	count;

	cur_num = stack->arr[pos];
	count = 1;
	while (++pos < stack->len)
	{
		if (stack->arr[pos] > cur_num)
		{
			cur_num = stack->arr[pos];
			count++;
		}
	}
	return (count);
}

int	*get_lis(t_stack *stack)
{
	int	i;
	int	lis_start;
	int	lis_count;
	int	cur_count;

	i = 0;
	lis_start = 0;
	lis_count = count_lis(stack, i);
	while (++i < stack->len)
	{
		cur_count = count_lis(stack, i);
	}
	return (0);
}
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
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	pos;
	int	lis_count;

	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), (argc - 1)))
			return (1);
		print_stack(&a);
		pos = 0;
		lis_count = count_lis(&a, pos);
		printf("p[%d]: %d\nLIS: %d\nstack len: %d\n", pos, a.arr[pos], lis_count, a.len);
	}
}