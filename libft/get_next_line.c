/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:27:39 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/03 21:54:05 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_fd(int fd, char *content)
{
	int		read_bytes;
	char	*buff;

	read_bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!strchr_locate_nl(content, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		content = strjoin_content_buf(content, buff);
	}
	free(buff);
	return (content);
}

char	*current_line(char *content)
{
	unsigned int	i;
	char			*line;

	i = 0;
	if (!*content)
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_previous_line(char *content)
{
	unsigned int	i;
	unsigned int	j;
	char			*remainder;

	i = 0;
	j = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\0')
	{
		free(content);
		return (NULL);
	}
	remainder = malloc(str_length(content) + 1 - i);
	if (!remainder)
		return (NULL);
	i++;
	while (content[i])
		remainder[j++] = content[i++];
	remainder[j] = '\0';
	free(content);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char		*content[1024];
	char			*line;

	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = read_fd(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	line = current_line(content[fd]);
	content[fd] = clear_previous_line(content[fd]);
	return (line);
}
