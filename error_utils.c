/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:58:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 13:54:33 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	ft_putstr_fd("Error", 1);
	if (message)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(message, 1);
	}
	ft_putstr_fd("\n", 1);
}
