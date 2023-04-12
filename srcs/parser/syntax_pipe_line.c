/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:14:07 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 17:24:31 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* 
initializes a pipeline node in the syntax tree 
by allocating memory for the node and the data field,
and setting the type of the node to AST_PIPELINE */
static void	init_syntax_pipe(t_ast	**ast_pipe)
{
	*ast_pipe = mini_calloc(1, sizeof(t_ast));
	(*ast_pipe)->type = AST_PIPELINE;
	(*ast_pipe)->data = mini_calloc(1, sizeof(t_pipe_line));
}

/* This function is responsible for parsing a pipeline of
commands seperted by pipe characters and creating an AST node 
representing the pipe line
1.	fetches the next token from the input using fetch_token
2.	checks if it is valid. if the token is not a word or a 
	redirect symbol, an error is returned.
3.	intializes the AST node which creates an AST node with
	type "AST_PIPELINE" and allocates memory for the 
	t_pipe_line struct that contains pointers to the command
	and the next pipeline.
4.	calls the syntax_command function to parse the first
	command in the pipeline and sets the "command" pointer
	of the t_pipe_line struct to the resulting AST node.
5.	if the next token is a pipe character the function matches
	the token using the "match" function and frees the memory
	allocated for the token.
6.	the function then recursively calls itself to parse
	the next pipeline in the sequence and sets the "pipe_line"
	pointer of the t_pipe_line struct to the resulting AST node
 */
int	syntax_pipe_line(t_ast	**ast_pipe)
{
	t_pipe_line	*pipe_line;
	t_token		token;
	char		*pipe;

	token = fetch_token(GET);
	if (!(token.type == T_WORD || token.type == T_REDIRECT))
		return (error_syntax(token));
	init_syntax_pipe(ast_pipe);
	pipe_line = (*ast_pipe)->data;
	if (syntax_command(&pipe_line->command))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_PIPE)
	{
		pipe = match(T_PIPE);
		if (pipe == NULL)
			return (ERROR_FLAG);
		free(pipe);
		if (syntax_pipe_line(&pipe_line->pipe_line))
			return (ERROR_FLAG);
	}
	return (SUCCESS_FLAG);
}
