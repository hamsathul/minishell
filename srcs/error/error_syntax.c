/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:32:54 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/30 12:40:39 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

int	error_syntax(t_token token)
{
	ft_putstr_fd("minishell: syntax error newar unexpected token `", 2);
	if (token.type == T_PIPE)
		ft_putstr_fd(token.value, STDERR_FILENO);
	else
		ft_putstr_fd("newline", STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	g_manager.exit_code = EXIT_SYNTAXERR;
	return (ERROR_FLAG);
}
