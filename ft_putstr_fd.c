/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:13:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:37:48 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * ft_putchar_fd - Outputs the character 'c' to the given file descriptor.
 * 
 * @param c: The character to output.
 * @param fd: The file descriptor to write to. Should be a valid file descriptor.
 * 
 * This function writes the character 'c' to the file descriptor specified
 * by 'fd'. If 'fd' is invalid (less than 0), the function does nothing.
 */
static void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
	}
}

/**
 * ft_putstr_fd - Outputs a string to the given file descriptor.
 * @param s: The string to output.
 * @param fd: The file descriptor to write to.
 *
 * This function iterates through the string `s` and writes each character
 * to the file descriptor `fd` using the ft_putchar_fd function.
 * If `s` is NULL, the function does nothing.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}