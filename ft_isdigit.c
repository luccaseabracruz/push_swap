/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:49:45 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:35:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isdigit - Checks if the given character is a digit (0-9).
 * 
 * @param c: The character to check, represented as an integer.
 * 
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
