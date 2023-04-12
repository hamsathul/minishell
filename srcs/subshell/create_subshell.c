/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:46:03 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/08 14:37:53 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/subshell.h"

/* closes both read and write file descriptors */
void	close_pipe_fd(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
		error_exit("close", strerror(errno), EXIT_FAILURE);
	if (close(pipe_fd[1]) == -1)
		error_exit("close", strerror(errno), EXIT_FAILURE);
}

/* this function duplicates the file descriptors depending on
the pipe_type which is either READ or WRITE and close both file
descriptors*/
void	connect_pipe(int pipe_fd[2], int pipe_type)
{
	if (dup2(pipe_fd[pipe_type], pipe_type) == -1)
		error_exit("dup2", strerror(errno), EXIT_FAILURE);
	close_pipe_fd(pipe_fd);
}

/* 
1. function takes a pointer to a t_pipe_line struct which
	contains a command to be executed and flag indicating wether
	it is a part of a pipeline.
2.	creates a pipe by calling the pipe function and setsup
	an array of two file descriptors to represent the read and 
	write end of the pipe.
3.	if the pipe is successful a new process is forked using fork
4.	the child process then executes the command by calling exec_ast
	with the commands abstract syntax tree(AST).
5.	if the command is part of a pipeline the child process calls
	the connect_pipe with the wrte end of the pipe to connect it to
		the standard input of the new process.
6.	otherwise it calls close_pipe-fd to close both ends of the pipe
7.	the parent process calls connect pipe with the read end of the 
	pipe to connect it to the standard output of the new process
8.	returns the PID of the new process.  */
pid_t	create_subshell(t_pipe_line *pipe_line)
{
	static int	pipe_fd[2];
	pid_t		pid;

	if (pipe(pipe_fd) == -1)
	{
		error_general("pipe", NULL, strerror(errno));
		return (ERROR_FLAG);
	}
	change_signal();
	pid = fork();
	if (pid < 0)
		error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		if (pipe_line->pipe_line)
			connect_pipe(pipe_fd, WRITE);
		else
			close_pipe_fd(pipe_fd);
		exec_ast(pipe_line->command);
		exit(g_manager.exit_code);
	}
	connect_pipe(pipe_fd, READ);
	return (pid);
}
