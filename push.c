/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:18 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/28 19:58:20 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	push(int *src, int *dst, int len)
{
	int	i;
	int	element;
	int	temp;

	element = src[0];
	while(src[i] && i < len)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i] = NULL;
	i = 0;
	temp = dst[0];
	dst[0] = element;
	while (dst[i + 1] && i < len)
	{
		
	}
}