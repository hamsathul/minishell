/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:45:25 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 14:50:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
1.	opens the file with diffrent flags
2. use dup2 to redirect the standard output of the process
	to the file descriptor of the opened file.
3.	closes the file descriptor
4.	returns a success flag */
int	redirect_out_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		return (error_general(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (error_general("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (error_general("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
