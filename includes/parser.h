/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:08:31 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/01 01:44:04 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "token.h"
# include "ast.h"

typedef enum e_fetch_type
{
	GET,
	UPDATE
}	t_fetch_type;

int		lexical_analyzer(t_token *token, char **begin, char **end);
t_token	fetch_token(t_fetch_type type);
t_ast	*syntax_analyzer(void);
char	*match(t_type type);
int		syntax_pipe_line(t_ast	**ast_pipe);
int		syntax_command(t_ast **ast_command);
int		syntax_simple_command(t_simple_command **simple_command);
int		syntax_redirects(t_ast **ast_redirects);
int		syntax_io_redirect(t_io_redirect	**io_redirect);
char	*replace_env(char	*token);
char	*syntax_heredoc_word(char *token);
char	*syntax_word(char *token);
char	*get_combined_word(void);
char	*get_combined_heredoc_word(void);
void	free_ast(t_ast *ast);
void	free_io_redirect(t_io_redirect *io_redirect);
void	free_simple_command(t_simple_command *simple_command);

#endif