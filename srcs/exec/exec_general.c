/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:19:34 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/02 12:40:17 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

static int	get_count()
{
	t_env	*ptr;
	int		count;

	ptr = g_manager.env;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

static char	**get_string_env(void)
{
	t_env	*ptr;
	char	**ret;
	char	*temp;
	int		count;
	int		i;

	ptr = g_manager.env;
	count = get_count();
	ret = (char **)mini_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr && ptr->value)
	{
		temp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(temp, ptr->value);
		free(temp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}

static int	error_execve(char	*argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT)
	{
		exit_code = EXIT_ENOENT;
		error_general(argv, NULL, "command not found");
	}
	else if (errno == EACCES)
	{
		exit_code = EXIT_EACCES;
		error_general(argv, NULL, strerror(errno));
	}
	return (exit_code);
}

int	exec_general(char **argv)
{
	char	**envp;
	char	*filename;

	envp = get_string_env();
	if (ft_strchr(*argv, '/') == NULL)
	{
		if (get_env(PATHENV))
			filename = mini_find_path(*argv);
	}
	else
		filename = ft_strdup(*argv);
	if (!argv[0][0])
		error_exit(argv[0], "command not found", EXIT_ENOENT);
	execve(filename, argv, envp);
	return (error_execve(*argv));
}
