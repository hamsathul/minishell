/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multishell_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:35:53 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:35:57 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/mini_signal.h"

static void	handle_sigint_multishell(int signum)
{
	if (signum != SIGINT)
		return ;
}

static void	handle_sigquit_multishell(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	multishell_signal(void)
{
	signal(SIGINT, handle_sigint_multishell);
	signal(SIGQUIT, handle_sigquit_multishell);
}