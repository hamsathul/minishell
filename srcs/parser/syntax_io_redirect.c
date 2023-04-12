/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:45:53 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/31 22:12:11 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	syntax_io_redirect(t_io_redirect	**io_redirect)
{
	char	*redirect_op;

	*io_redirect = mini_calloc(1, sizeof(t_io_redirect));
	redirect_op = match(T_REDIRECT);
	if (!ft_strncmp(redirect_op, "<", 2))
		(*io_redirect)->redirect_op = R_IN;
	else if (!ft_strncmp(redirect_op, ">", 2))
		(*io_redirect)->redirect_op = R_OUT;
	else if (!ft_strncmp(redirect_op, ">>", 3))
		(*io_redirect)->redirect_op = R_APPEND;
	else if (!ft_strncmp(redirect_op, "<<", 2))
		(*io_redirect)->redirect_op = R_HEREDOC;
	else
		return (ERROR_FLAG);
	free(redirect_op);
	if ((*io_redirect)->redirect_op == R_HEREDOC)
		(*io_redirect)->end_text = get_combined_heredoc_word();
	else
		(*io_redirect)->file_path = get_combined_word();
	if ((*io_redirect)->redirect_op == R_HEREDOC)
		return (SUCCESS_FLAG);
	if (!(*io_redirect)->file_path)
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
