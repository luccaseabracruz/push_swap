/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:30:32 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/09 13:59:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("A | B\n");
	ft_printf("-----\n");
	while (i < a->len || i < b->len)
	{
		if (i < a->len)
		ft_printf("%d", a->arr[i]);
		else
		ft_putchar_fd(' ', 1);
		ft_printf(" | ");
		if (i < b->len)
		ft_printf("%d", b->arr[i]);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_printf("\n\n");
}

// static void	print_stack(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("A\n");
// 	ft_printf("-\n");
// 	while (i < stack->len)
// 	{
// 		ft_printf("%d\n", stack->arr[i]);
// 		i++;
// 	}
// 	ft_printf("\n\n");
// }

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (!init_stacks(&a, &b, (argv + 1), (argc - 1)))
		return (1);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	print_stacks(&a, &b);
	rra(&a); //operation to be tested
	print_stacks(&a, &b);
	rrb(&b);
	print_stacks(&a, &b);
	rrr(&a, &b); //operation to be tested
	print_stacks(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}