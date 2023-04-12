/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:32:49 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 14:46:18 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
1. opens a file
2. uses dup2 function to replace the stdin file descriptor
	with the file descriptor of the file we jusy opened so any
	subsequent input read by the command will come from the file
	insted of the users keyboard
3. closes the file descriptor
4. returns a status code */
int	redirect_in_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY, 00644);
	if (fd < 0)
		return (error_general(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (error_general("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (error_general("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
