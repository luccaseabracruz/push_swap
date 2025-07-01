/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:09:14 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/01 20:54:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

static bool	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), arrlen(argv + 1)))
			return (1);
		if (is_sorted(&a))
			return (0);
		else if (a.len == 2 && a.arr[0] > a.arr[1])
			sa(&a);
		else if (a.len == 3)
			sort_three(&a);
		else if (a.len > 3)
			push_swap(&a, &b);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
