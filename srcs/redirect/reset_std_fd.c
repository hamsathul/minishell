/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:46 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 14:58:22 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
this function resets the standard input, standard output and standar error
file descriptors of a process to their original values */
int	reset_std_fd(int std_fd[3])
{
	if (dup2(std_fd[READ], STDIN_FILENO) == -1)
		return (error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[WRITE], STDOUT_FILENO) == -1)
		return (error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[ERROR], STDERR_FILENO) == -1)
		return (error_exit("dup2", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}
