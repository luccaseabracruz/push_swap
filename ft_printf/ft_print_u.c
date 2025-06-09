/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:51:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/23 21:30:26 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_print_u(va_list args)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	return (ft_putunbr_count(arg));
}
