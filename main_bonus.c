/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:43:52 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/01 15:33:44 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		args_len;

	args_len = arrlen(argv + 1);
	if (argc > 1)
	{
		if (!init_stacks(&a, &b, (argv + 1), args_len))
			return (1);
		checker(&a, &b, args_len);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
