/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:54:36 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/07 16:11:28 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXEC_H
# define EXEC_H

# include "minishell.h"

int	exec_builtin(char **argv);
int	exec_general(char **argv);
int	exec_command_line(t_ast **ast);
int	exec_heredoc(t_ast **ast);
int	exec_io_redirect(t_io_redirect *io_redirect);
int	exec_simple_command(t_simple_command *simple_command);
int	exec_ast(t_ast *ast);
int	exec_command(t_command	*command);
int	exec_single_command(t_command *command);
int	exec_subshell(t_pipe_line *pipe_line);

#endif