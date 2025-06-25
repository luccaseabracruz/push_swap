/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:43:52 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 16:40:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), arrlen(argv + 1)))
			return (1);
		checker(&a, &b);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}