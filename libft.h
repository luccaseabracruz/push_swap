/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:41:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 15:46:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

#endif