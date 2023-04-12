/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:09:09 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 17:05:04 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "token.h"

typedef struct s_command		t_command;
typedef struct s_simple_command	t_simple_command;
typedef struct s_redirects		t_redirects;
typedef struct s_io_redirect	t_io_redirect;

/*  represent different types of nodes in the syntax tree, */
typedef enum e_ast_type
{
	AST_NULL,
	AST_PIPELINE,
	AST_COMMAND,
	AST_REDIRECTS
}								t_ast_type;

/* defines the basic structure of a syntax tree node,
 which consists of a type and a data field that 
 points to the actual data of the node. 
*/
typedef struct s_ast
{
	t_ast_type					type;
	void						*data;
}								t_ast;

/* defines a structure that represents a 
pipeline of shell commands. It consists of 
a pointer to the first command in the pipeline (command) 
and a pointer to the next pipeline (pipe_line) */
typedef struct s_pipe_line
{
	t_ast						*command;
	t_ast						*pipe_line;
}								t_pipe_line;

/* defines a structure that represents a shell command. 
It consists of a pointer to the simple command (simple_command) 
and a pointer to the list of input/output redirections (redirects).
*/
typedef struct s_command
{
	struct s_simple_command		*simple_command;
	t_ast						*redirects;
}								t_command;

/* defines a structure that represents a simple shell command.
 It consists of the path to the executable (exec_path) 
 and a list of arguments (argv). */
typedef struct s_simple_command
{
	char						*exec_path;
	char						**argv;
}								t_simple_command;

/*  defines a structure that represents a list of 
input/output redirections for a shell command. 
It consists of a pointer to the first redirection (io_redirect) 
and a pointer to the next redirection in the list (redirects) 
if there is any. */
typedef struct s_redirects
{
	struct s_io_redirect		*io_redirect;
	t_ast						*redirects;
}								t_redirects;

/* defines a structure that represents an input/output redirection.
It consists of the type of redirection (redirect_op), 
the path to the file to redirect to/from (file_path), 
and the end text to redirect to/from (end_text). */
typedef struct s_io_redirect
{
	t_redirect_op				redirect_op;
	char						*file_path;
	char						*end_text;
}								t_io_redirect;

#endif