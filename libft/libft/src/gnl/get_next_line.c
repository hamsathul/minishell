/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:55:21 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/22 12:55:21 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_string_till_newline(char *static_buff)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!static_buff[i])
		return (NULL);
	while (static_buff[i] && static_buff[i] != '\n')
		i++;
	buffer = (char *)malloc(sizeof(char) * (i + 2));
	if (!buffer)
		return (NULL);
	i = 0;
	while (static_buff[i] && static_buff[i] != '\n')
	{
		buffer[i] = static_buff[i];
		i++;
	}
	if (static_buff[i] == '\n')
	{
		buffer[i] = static_buff[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_remaining_string_after_nextline(char *static_buff)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	while (static_buff[i] && static_buff[i] != '\n')
		i++;
	if (!static_buff[i] || (static_buff[i] == '\n' && !static_buff[i + 1]))
	{
		free(static_buff);
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(static_buff) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (static_buff[i])
		buffer[j++] = static_buff[i++];
	buffer[j] = '\0';
	free(static_buff);
	return (buffer);
}

char	*ft_read_and_append(int fd, char *static_buff)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!gnl_strchr(static_buff, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		static_buff = gnl_strjoin(static_buff, buffer);
	}
	free(buffer);
	return (static_buff);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (0);
	static_buff = ft_read_and_append(fd, static_buff);
	if (!static_buff)
		return (NULL);
	line = ft_next_string_till_newline(static_buff);
	static_buff = ft_remaining_string_after_nextline(static_buff);
	return (line);
}

/* int main(void)
{
	char *line;
	int fd;

	fd = open("file1.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		free(line);
	}
	
} */