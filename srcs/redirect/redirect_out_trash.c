/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_trash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:26:01 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 14:53:53 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

/* 
this function is used to discard error messages that would
normally be printed to the console */
int	redirect_out_trash(void)
{
	int fd;

	fd = open(TRASH_PATH, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		return (error_general(TRASH_PATH, NULL, strerror(errno)));
	if (dup2(fd, STDERR_FILENO) == -1)
		return (error_general("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (error_general("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
