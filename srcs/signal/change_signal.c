/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:58:31 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/08 11:30:13 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"

/* this function is used to handle the case where the user 
	presses the CTRL+C key combination to interrupt the program.
1.	takes an integer parameter signum, which represents the signal number
2.	If signum is not equal to SIGINT, the function simply 
	returns without doing anything. 
3.	Otherwise, it writes a newline character to standard output 
*/
static void	handle_sigint_change(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

/* this function is used to handle the case where the user 
	presses the CTRL+\ key combination to interrupt the program.
1.	takes an integer parameter signum, which represents the signal number
2.	If signum is not equal to SIGINT, the function simply 
	returns without doing anything. */
static void	handle_sigquit_change(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	change_signal(void)
{
	signal(SIGINT, handle_sigint_change);
	signal(SIGQUIT, handle_sigquit_change);
}
