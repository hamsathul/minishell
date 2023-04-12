/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:29:07 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:18:14 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	init_syntax_redirects(t_ast **ast_redirects)
{
	*ast_redirects = mini_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = mini_calloc(1, sizeof(t_redirects));
}

/*
	syntax_redirects
	- check io_redirect syntax error
*/
int	syntax_redirects(t_ast **ast_redirects)
{
	t_redirects	*redirects;

	init_syntax_redirects(ast_redirects);
	redirects = (*ast_redirects)->data;
	if (syntax_io_redirect(&redirects->io_redirect))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}