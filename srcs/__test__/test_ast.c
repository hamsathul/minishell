/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:23:35 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 23:24:20 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test.h"

void	print_simple_command(t_simple_command *simple_command)
{
	int	ac;

	printf("===simple_command===\n");
	printf("exec_path: %s\n", simple_command->exec_path);
	ac = 0;
	while (simple_command->argv[ac])
	{
		printf("argv[%d]: %s\n", ac, simple_command->argv[ac]);
		ac++;
	}
}

void	print_io_redirect(t_io_redirect *io_redirect)
{
	char	*redirect_op;

	printf("===io_redirect===\n");
	if (io_redirect->redirect_op == R_IN)
		redirect_op = "<";
	else if (io_redirect->redirect_op == R_OUT)
		redirect_op = ">";
	else if (io_redirect->redirect_op == R_APPEND)
		redirect_op = ">>";
	else if (io_redirect->redirect_op == R_HEREDOC)
	{
		redirect_op = "<<";
		printf("end_text: %s\n", io_redirect->end_text);
	}
	else
		redirect_op = "redirect_op error";
	printf("redirect_op: %s\n", redirect_op);
	printf("file_path: %s\n", io_redirect->file_path);
}

void	print_redirects(t_ast *ast)
{
	t_redirects	*redirects;

	if (ast->type == AST_REDIRECTS)
	{
		printf("===redirects===\n");
		redirects = ast->data;
		if (redirects->io_redirect)
			print_io_redirect(redirects->io_redirect);
		if (redirects->redirects)
			print_redirects(redirects->redirects);
	}
}

void	print_command(t_ast *ast)
{
	t_command	*command;

	if (ast->type == AST_COMMAND)
	{
		printf("===command===\n");
		command = ast->data;
		if (command->simple_command)
			print_simple_command(command->simple_command);
		if (command->redirects)
			print_redirects(command->redirects);
	}
}

void	test_ast(t_ast *ast)
{
	t_pipe_line	*pipe_line;

	printf("*****test_ast*****\n");
	if (ast && ast->type == AST_PIPELINE)
	{
		printf("===pipe_line===\n");
		pipe_line = ast->data;
		if (pipe_line->command)
			print_command(pipe_line->command);
		if (pipe_line->pipe_line)
			test_ast(pipe_line->pipe_line);
	}
	printf("*****************\n");
}
