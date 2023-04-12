/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:21:17 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/22 12:21:17 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[gnl_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	joined = (char *)malloc(sizeof(char)
			* (gnl_strlen(line) + gnl_strlen(buff) + 1));
	if (!joined)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i])
			joined[i] = line[i];
	while (buff[j])
		joined[i++] = buff[j++];
	joined[gnl_strlen(line) + gnl_strlen(buff)] = '\0';
	free (line);
	return (joined);
}
