/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:06:38 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/08 13:09:47 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/subshell.h"

/* This function is used to set the exit code for the shell program
 based on the status of a child process. The function takes an
 integer argument status, which is the status of the child process
 returned by the waitpid() function. 
 1.	checks if the child process exited normally using the 
	WIFEXITED() macro. if it did the exit code is set to the
	exit status of the child process using the WEXITSTATUS() macro
2.	if the child process did not exit normally the function
	checks if it was terminated by a signal using the WIFSIGNALED macro.
	if this was true, the exit code is set to 128 plus the signal number
	using the WTERMSIG macro becuase when a process is terminated
	by a signal the exit status is set to 128 + signal number.
3.	if the child process neither exited normally nor was terminated
	by a signal, the exit status is set to exit_failure
 */
void	set_exit_code(int status)
{
	if (WIFEXITED(status))
		g_manager.exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_manager.exit_code = 128 + WTERMSIG(status);
		if (g_manager.exit_code == 131)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
	}
	else
		g_manager.exit_code = EXIT_FAILURE;
}

/* this function is used to wait for the child processes
to exit
1.	takes in last_pid which is the process ID of the last
	child process.
2.	function calls waitpid() repeatedly with the 
	a.	-1 argument	to wait for any child process to exit
	b.	status is used to store the exit status of the 
		child process
	c.	 WUNTRACED, which indicates that the function 
		should also return if a child process is stopped 
3.	updates the exit code using set_exit_code() when 
	the process with ID last_pid exits.*/
void	wait_subshell(pid_t last_pid)
{
	pid_t	pid;
	int		status;

	pid = 0;
	while (pid != ERROR_FLAG)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (pid == last_pid)
			set_exit_code(status);
	}
}
