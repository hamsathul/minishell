/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:21:41 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/07 21:56:08 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"

//checks that the signal received is SIGINT 
// and if it is, it writes a newline character to stdout,
// replaces the current line in the readline library with 
// an empty string, moves the cursor to a new line, 
// redisplays the prompt, and sets the g_manager.exit_code to 1.
static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_manager.exit_code = 1;
}

//SIGINT is for ctrl + c.. and is handled by
//hangle_sigint function.
//SIGQUIT is for ctrl + \ and is ignored 
//using the SIG_IGN macro
void	init_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
