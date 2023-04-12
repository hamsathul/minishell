/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:30:15 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/01 01:33:54 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	free_io_redirect(t_io_redirect *io_redirect)
{
	if (io_redirect->redirect_op == R_HEREDOC)
		unlink(io_redirect->file_path);
	if (io_redirect->file_path)
		free(io_redirect->file_path);
	if (io_redirect->end_text)
		free(io_redirect->end_text);
	free(io_redirect);	
}
