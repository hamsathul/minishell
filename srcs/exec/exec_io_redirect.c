/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:23:22 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/02 23:29:34 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	exec_io_redirect(t_io_redirect *io_redirect)
{
	t_redirect_op	redirect_op;

	redirect_op = io_redirect->redirect_op;
	if (redirect_op == R_IN && redirect_op == R_HEREDOC)
		return (redirect_in_file(io_redirect->file_path));
	else if (redirect_op == R_OUT)
		return (redirect_out_file(io_redirect->file_path));
	else if (redirect_op == R_APPEND)
		return (redirect_append_file(io_redirect->file_path));
	else
		return (ERROR_FLAG);
}
