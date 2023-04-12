/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:46:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 13:16:49 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSHELL_H
# define SUBSHELL_H

# include "minishell.h"

pid_t	create_subshell(t_pipe_line *pipe_line);
void	wait_subshell(pid_t last_pid);

#endif