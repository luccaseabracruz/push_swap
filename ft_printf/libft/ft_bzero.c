/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/04/18 11:42:28 by lseabra-         ###   ########.fr       */
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
/*
int	main(void)
{
	char	str[] = "Lucca";
	char	*ptr = str;
	printf("str: %s\n", str);
	ft_bzero(str, 2);
	ptr += 2;
	printf("str: %s\n", ptr);
}
*/
