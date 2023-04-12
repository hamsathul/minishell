/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_find_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:25:53 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/01 02:46:07 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static void	free_path(char	**path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static char	**split_path(void)
{
	char	**path;

	if (get_env(PATHENV))
		path = ft_split(get_env(PATHENV)->value, ':');
	else
	{
		path = (char **)mini_calloc(2, sizeof(char *));
		*path = ft_strdup(".");
	}
	return (path);
}

char	*mini_find_path(char *cmd)
{
	struct stat buf;
	char		**path;
	char		*filename;
	char		*temp;
	int			i;

	i = 0;
	path = split_path();
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		filename = ft_strjoin(temp, cmd);
		free(temp);
		if (stat(filename, &buf) != -1)
			return (filename);
		free(filename);
		i++;
	}
	free_path(path);
	return (ft_strdup(cmd));
}
