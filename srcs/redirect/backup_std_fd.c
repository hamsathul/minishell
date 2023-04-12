/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_std_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:26:34 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 15:36:22 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
this function backsup the standard input, standard output
and error file descriptors */
int	backup_std_fd(int std_fd[3])
{
	std_fd[READ] = dup2(STDIN_FILENO, BACKUP_FD);
	std_fd[WRITE] = dup(STDOUT_FILENO);
	std_fd[ERROR] = dup(STDERR_FILENO);
	if (std_fd[READ] == -1 || std_fd[WRITE] == -1 || std_fd[ERROR] == -1)
		error_exit("dup", strerror(errno), EXIT_FAILURE);
	return (SUCCESS_FLAG);
}
