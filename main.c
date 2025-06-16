/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:09:14 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/16 19:06:29 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), arrlen(argv + 1)))
			return (1);
		// print_stacks(&a, &b);
		if (a.len == 1)
			return (0);
		else if (a.len == 2 && a.arr[0] > a.arr[1])
			sa(&a);
		else if (a.len == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
		// print_stacks(&a, &b);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
