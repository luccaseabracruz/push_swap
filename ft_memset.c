/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:01:03 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:37:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * ft_memset - Fills a block of memory with a specified value.
 * @param s: Pointer to the memory block to fill.
 * @param c: The value to set.
 * @param n: The number of bytes to fill.
 *
 * @return A pointer to the memory block.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
