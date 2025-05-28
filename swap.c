/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/28 18:59:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *stack)
{
	int	temp;

	if (stack[0] && stack[1])
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	int	arr[argc - 1];
// 	int	i;
// 	if (argc >=2)
// 	{
// 		i = 0;
// 		printf("Old version: \n");
// 		while (i < argc - 1)
// 		{
// 			arr[i] = atoi(argv[i + 1]);
// 			printf("p[%d]: %d\n", i, arr[i]);
// 			i++;
// 		}
// 		swap(arr);
// 		i = 0;
// 		printf("New version: \n");
// 		while (i < argc - 1)
// 		{
// 			printf("p[%d]: %d\n", i, arr[i]);
// 			i++;
// 		}
// 	}
// }