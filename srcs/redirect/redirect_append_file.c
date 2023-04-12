/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_append_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:56:45 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 15:33:43 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
this function redirects the standard output of a shell command to
a file specified by "file_path" in append mode */
int	redirect_append_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd < 0)
		return (error_general(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (error_general("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (error_general("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
