/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:58:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/23 21:24:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_print_s(va_list args)
{
	char	*arg;

	arg = va_arg(args, char *);
	if (!arg)
	{
		return (ft_putstr_count("(null)"));
	}
	return (ft_putstr_count(arg));
}
