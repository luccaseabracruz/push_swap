/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:58:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/04 20:01:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>

bool	free_return(void *ptr, bool boolean)
{
	free(ptr);
	ptr = NULL;
	return (boolean);
}

bool	free_strarr(char **arr, bool boolean)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	return (free_return(arr, boolean));
}

void	print_error(char *message)
{
	ft_putstr_fd(ERROR, STD_ERR);
	if (message)
	{
		ft_putstr_fd(": ", STD_ERR);
		ft_putstr_fd(message, STD_ERR);
	}
	ft_putstr_fd("\n", STD_ERR);
}
