/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:08 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/27 13:50:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @function get_next_line
 * @brief Reads the next line from a file descriptor.
 *
 * Reads a single line from the given file descriptor (`fd`). Uses a static
 * buffer to store leftover data between calls and reads the file in chunks of
 * size `BUFFER_SIZE`. The returned line is dynamically allocated and must be
 * freed by the caller.
 *
 * @param fd File descriptor to read from. Must be valid and open.
 * @return Pointer to a string containing the next line, including the newline
 *         character (`\n`) if present. Returns NULL if:
 *         - The file descriptor is invalid.
 *         - `BUFFER_SIZE` is <= 0.
 *         - An error occurs during reading.
 *         - End of file is reached and no content is left.
 *
 * @note Not thread-safe due to the static buffer. Caller must free the returned
 *       line.
 *
 * @example
 * int fd = open("file.txt", O_RDONLY);
 * char *line;
 * while ((line = get_next_line(fd)))
 * {
 *     printf("%s", line);
 *     free(line);
 * }
 * close(fd);
 */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_bufferlinejoin(NULL, buffer);
	while (!ft_haschr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == '\0')
		{
			free(line);
			ft_cleanbuffer(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_bufferlinejoin(line, buffer);
	}
	ft_cleanbuffer(buffer);
	return (line);
}
