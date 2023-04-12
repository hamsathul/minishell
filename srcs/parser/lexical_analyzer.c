/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:08:16 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 16:47:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* This function is called when a quoted string is encountered
1.	sets token type to T_WORD
2.	searches for the matching quote charecter
3.	if it is not found it sets an error flag and sets
	"end" pointer to the end of the command line string.
4.	otherwise it increments the "end" pointer to the position
	after the closing quote character */
static void	get_quote(t_token *token, char **end)
{
	token->type = T_WORD;
	*end = ft_strchr(*end + 1, **end);
	if (!end)
	{
		error_general("syntax error", NULL, "unexpected end of file");
		*end = g_manager.command_line + ft_strlen(g_manager.command_line);
		g_manager.quote_error = 1;
	}
	else
		(*end)++;
}

/*This function is called when a redirect operator is encountered
1.	sets the token type to T_REDIRECT
2.	checks if the operator is double operator("<<", ">>")
	if so increments the "end" pointer by 2 otherwise it 
	increments the "end" pointer by 1
*/
static void	get_redirect_op(t_token *token, char **end)
{
	token->type = T_REDIRECT;
	if (**end == U_IN && *(*end + 1) == U_IN)
		*end += 2;
	else if (**end == U_OUT && *(*end + 1) == U_OUT)
		*end += 2;
	else if (**end == U_IN)
		(*end)++;
	else if (**end == U_OUT)
		(*end)++;
}

/* This function is called when a pipe operator is encountered
1.	sets the token type to T_PIPE
2.	increments the "end" pointer by 1
*/
static void get_pipe(t_token *token, char **end)
{
	token->type = T_PIPE;
	(*end)++;
}

/*This function is called when a regular word is encountered
1.	sets the token type to T_WORD
2.	iterates throught the command line string untill a 
	whitespace, redirection or pipe character is encountered.
3.	sets the end pointer to the position of the last character in
	the word
 */
static void	get_word(t_token *token, char **end)
{
	token->type = T_WORD;
	while (**end && (!mini_isspace(**end)) && !ft_strchr("<>|\"'", **end))
		(*end)++;
}

/* 
This function is responsible for analyzing the command line string
and extracting tokens from it. it takes a t_token structure as input
and updates it with the appropriate type and value of the token
that is extracted
1.	checks for whitespaces in the begining untill a non whitespace
	charecter is encountered.
2.	sets the begin pointer to the current position in the command line
3.	initializes the end pointer to the same position.
4.	if the current position is at the end of the command line 
	an error flag is returned.
5.	checks the type of the charecter at the "begin" position in 
	the command line string.
6.	if it is double quote or single quote charecter it calls the
	"get_quote" function to extract a quoted string token.
7.	if it is a redirection operator charecter, it calls the 
	get_redirect_op function to extract redirection operation token.
8.	if it is a pipe operator charecter, it calls the get_pipe function
	to extract a pipe operator token.
9.	otherwise it calls the "get_word" function to extract a regular
	word token.
 */
int	lexical_analyzer(t_token *token, char **begin, char **end)
{
	while (mini_isspace(g_manager.command_line[g_manager.rc]))
		g_manager.rc++;
	*begin = &g_manager.command_line[g_manager.rc];
	*end = *begin;
	if (g_manager.rc >= (int)ft_strlen(g_manager.command_line))
		return (ERROR_FLAG);
	if (**begin == U_DOUBLE_QUOTES || **begin == U_SINGLE_QUOTES)
		get_quote(token, end);
	else if (**begin == U_IN || **begin == U_OUT)
		get_redirect_op(token, end);
	else if (**begin == U_PIPE)
		get_pipe(token, end);
	else
		get_word(token, end);
	if (g_manager.quote_error)
		return (ERROR_FLAG);
	else
		return (SUCCESS_FLAG);
}
