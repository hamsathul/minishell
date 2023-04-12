/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:21:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/03 13:26:16 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	exec_subshell(t_pipe_line *pipe_line)
{
	pid_t	pid;

	pid = create_subshell(pipe_line);
	if (pid == ERROR_FLAG)
		return (ERROR_FLAG);
	if (pipe_line->pipe_line && pipe_line->pipe_line->type == AST_PIPELINE)
		exec_subshell(pipe_line->pipe_line->data);
	else
		wait_subshell(pid);
	return (SUCCESS_FLAG);
}
