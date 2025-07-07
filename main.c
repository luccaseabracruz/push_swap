/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:09:14 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/07 22:40:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	lis_stk;

	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), arrlen(argv + 1)))
			return (1);
		if (!init_lis(&lis_stk, &a))
		{
			free(a.arr);
			return (free_return(b.arr, 1));
		}
		if (is_sorted(&a))
			return (0);
		else if (a.len == 2 && a.arr[0] > a.arr[1])
			sa(&a);
		else if (a.len == 3)
			sort_three(&a);
		else if (a.len > 3)
			push_swap(&a, &b, &lis_stk);
		free(a.arr);
		free(b.arr);
		free(lis_stk.arr);
	}
}
