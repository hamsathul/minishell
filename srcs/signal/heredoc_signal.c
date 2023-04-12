/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:53:41 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/08 12:00:13 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"

/* This function has the effect of terminaing any ongoing
	here-document input as it insets a newline character
	into the input stream.
1.	checks to see if the  signal is actually SIGINT
	if not the function returns without doing anything
2.	if the signal is SIGINT the ioctl() function is called
	with three arguments.
	a.	STDIN_FILENO - is the file descriptor of standard input
	b.	TIOCSTI - is an ioctl command that inserts a single 
		charecter into the input stream.
	c.	"\n" is the character to be inserted*/
static void	handle_sigint_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_manager.exit_code = 1;
	return ;
}

/* 
function is used to handle the SIGINT signal in 
the context of a shell script that is using a 
here-document input. */
void	heredoc_signal(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
