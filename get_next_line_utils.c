/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:29 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 13:55:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>
#include <stdlib.h>

/**
 * @function ft_calloc
 * @brief Allocates and initializes memory to zero.
 *
 * Allocates memory for an array of `nmemb` elements, each of size `size`,
 * and initializes all bytes in the allocated memory to zero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return Pointer to the allocated memory, or `NULL` if allocation fails or
 *         if the requested size exceeds the maximum allowable size.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

/**
 * @function ft_linelen
 * @brief Calculates the length of a line in a string.
 *
 * Computes the length of a line in the given string `s`, stopping at the
 * first newline character (`\n`) or the null terminator. If a newline is
 * encountered, it is included in the count.
 *
 * @param s The string to calculate the line length from.
 * @return The length of the line, including the newline if present.
 */
size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

/**
 * @function ft_bufferlinejoin
 * @brief Joins a line and a buffer into a single string.
 *
 * Concatenates the contents of `line` and `buffer` into a newly allocated
 * string. The result includes all characters from both inputs and is
 * null-terminated. The caller must free the result.
 *
 * @param line The first string to join. Can be `NULL`.
 * @param buffer The second string to join. Can be `NULL`.
 * @return Pointer to the new string, or `NULL` if allocation fails.
 */
char	*ft_bufferlinejoin(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	size_t	i;
	char	*res;

	line_len = ft_linelen(line);
	buffer_len = ft_linelen(buffer);
	res = ft_calloc(line_len + buffer_len + 1, sizeof(char));
	if (!res)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < line_len)
	{
		res[i] = line[i];
		i++;
	}
	i--;
	while (++i < line_len + buffer_len)
		res[i] = buffer[i - line_len];
	free(line);
	return (res);
}

/**
 * @function ft_haschar
 * @brief Checks if a character exists in a string.
 *
 * Checks if the character `c` exists in the string `s`. Returns `1` if
 * found, otherwise returns `0`.
 *
 * @param s The string to search in. Must be null-terminated.
 * @param c The character to locate.
 * @return `1` if found, `0` if not.
 */
int	ft_haschr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

/**
 * @function ft_cleanbuffer
 * @brief Cleans up a buffer after extracting a line.
 *
 * Removes the characters of the current line, including the newline
 * character (`\n`), from the buffer. Shifts the remaining characters to
 * the beginning and fills the rest with null terminators.
 *
 * @param buffer The buffer to clean. Must be a null-terminated string.
 *
 * @note If the buffer is `NULL`, the function does nothing. Modifies the
 *       buffer in place.
 */
void	ft_cleanbuffer(char *buffer)
{
	int		i;
	int		j;

	if (!buffer)
		return ;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	while (buffer[j])
	{
		buffer[j] = '\0';
		j++;
	}
}
