/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 16:02:30 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - Sets a block of memory to zero.
 * @param s: Pointer to the memory block to zero out.
 * @param n: The number of bytes to set to zero.
 *
 * This function is equivalent to calling ft_memset with a value of 0.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
