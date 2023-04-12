/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:46:39 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 17:54:55 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* Initilizes the AST node for a command */
static void	init_syntax_command(t_ast **ast_command)
{
	*ast_command = mini_calloc(1, sizeof(t_ast));
	(*ast_command)->type = AST_COMMAND;
	(*ast_command)->data = mini_calloc(1, sizeof(t_command));
}

/* The function analyzes the syntax of a command and generates
an AST node for it
1.	"init_syntax_command" is called to create an empty AST node.
2.	t_command pointer is assigned to hold the data for commands
3.	t_ast pointer is used to hold the data for redirects.
4.	receives the next token using "fetch_token"
5.	enters a loop that processes tokens untill it encounters
	something other than a word or a redirect.
6.	for each token it checks whether it is a word or a redirect
7.	if it is a word, syntax_simple_command is called to analyze
	the syntax of the simple command and generates an AST node for it.
8.	if it is a redirect it calls syntax_redirects to analyze the 
	syntax of the redirect and generate an AST node for it.
9.	advances the ast_redirects pointer to point to the t_resirects
	struct in the AST node for the redirect, so that the next
	redirect can be added to the list.
10.	retreives the next token and repeats the loop untill it
	encounters a non-word or non-redirect token.
 */
int	syntax_command(t_ast **ast_command)
{
	t_command	*command;
	t_ast		**ast_redirects;
	t_token		token;

	init_syntax_command(ast_command);
	command = (*ast_command)->data;
	ast_redirects = &command->redirects;
	token = fetch_token(GET);
	while (token.type == T_WORD || token.type == T_REDIRECT)
	{
		if (token.type == T_WORD)
		{
			if (syntax_simple_command(&command->simple_command))
				return (ERROR_FLAG);
		}
		else if (token.type == T_REDIRECT)
		{
			if (syntax_redirects(ast_redirects))
				return (ERROR_FLAG);
			ast_redirects = &((t_redirects *)(*ast_redirects)->data)->redirects;
		}
		token = fetch_token(GET);
	}
	return (SUCCESS_FLAG);
}
