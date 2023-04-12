/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:42:54 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 16:18:59 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* 
1.	declares the variables for the begining and end pointers of the token,
	the token itself and flag for the lexical analyzer.
2.	intialize the token type as T_NULL and value as NULL
3.	calls the lexical analyzer function to analyze the next token in
	the command line and set the begin and end pointers of the token.
4.	checks whether the end of the command line is reached. if so
	it returns the token as it is.
5.	if the lexical analyzer returns an error_flag a syntax error is returned
6.	allocates memory for the value of the token based on the begin and end 
	pointers of the token
7.	uses the ft_strlcpy function the copy the characters between the begin
	and end pointers into the value field of the token
8.	updates the read cursor to point to the end of this particular token
9.	returns the token with the updated type and value fields. */
t_token	get_token(void)
{
	char	*begin;
	char	*end;
	t_token	token;
	int		flag;

	token.type = T_NULL;
	token.value = NULL;
	flag = lexical_analyzer(&token, &begin, &end);
	if (g_manager.rc >= (int)ft_strlen(g_manager.command_line))
		return (token);
	if (flag == ERROR_FLAG)
		g_manager.exit_code = EXIT_SYNTAXERR;
	token.value = mini_calloc(end - begin + 1, sizeof(char));
	if (!token.value)
		return (token);
	if (!ft_strlcpy(token.value, begin, end - begin + 1))
		return (token);
	g_manager.rc += end - begin;
	return (token);
}

/* This function is used to retrieve tokens 
from the users input command line depending on the
t_fetch_type argument.
1.	declare a static  t_token variable to 
	track the current token.
2.	declare t_token variable prev_token 
	to store the prevoius token
3.	if type is GET the current token is returned
4.	if type is UPDATE, the function updates the token value
	using the get_token() function and stores it in the token
	variable.
5.	the function then returns previous value of token before
	it was updated.
	*/
t_token	fetch_token(t_fetch_type type)
{
	static t_token	token;
	t_token			prev_token;

	prev_token = token;
	if (type == GET)
		return (token);
	else if (type == UPDATE)
		token = get_token();
	return (prev_token);
}
