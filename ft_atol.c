/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:55:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/30 18:18:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/**
 * @brief Converts a string to an long.
 *
 * The ft_atol function parses the initial portion of the string pointed to by
 * nptr, ignoring leading whitespace characters, and converts it to an long
 * value. It handles optional '+' or '-' signs to determine the sign of the
 * result. The conversion stops when a non-digit character is encountered, and
 * the function returns the long value converted up to that point.
 *
 * @param nptr Pointer to the null-terminated string to be converted.
 * @return The converted long value.
 */
long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}
