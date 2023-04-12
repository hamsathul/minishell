/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:50:51 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 16:56:46 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* 
The function checks if the next token fetched by
"fetch_token" function matches the expected "type"
1.	if it matches, it returns the value of the token.
2.	if it doesnot matc it calls the "error_syntax function
	and returns null." */
char	*match(t_type type)
{
	t_token	token;

	token = fetch_token(UPDATE);
	if (token.type == type)
		return (token.value);
	else
		error_syntax(token);
	return (NULL);
}

/* This function parses the command line and constructs
an abstract syntax tree (AST) from it
1.	fetches a token using fetch_token.
2.	checks if it is T_NULL, if it is retuns a null pointer
3.	if not the function calls syntax_pipe_line function to parse
	the entire command line and build an AST.
*/
t_ast	*syntax_analyzer(void)
{
	t_ast	*ast;
	t_token	token;

	ast = NULL;
	fetch_token(UPDATE);
	token = fetch_token(GET);
	if (token.type == T_NULL)
		return (ast);
	if (syntax_pipe_line(&ast) == SUCCESS_FLAG
		&& g_manager.quote_error == SUCCESS_FLAG)
		g_manager.exit_code = EXIT_SUCCESS;
	return (ast);
}
