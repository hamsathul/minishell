/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_combined_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:56:14 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 23:57:58 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* This function is used to read and combine multiple heredoc
words into one single string.
1.	next variable is assigned the character at the current position
	in the command line, which is obtained using the g_manager.rc index
	and the g_manager.command_line array
2.	reading the next token by using fetch_token(GET) and checks if the type
	is word, if it is not it returns NULL
3.	otherwise it calls the syntax_heredoc_word function to parse
	the word and obtain a properly escaped unquoted string.
4.	enters a loop, that continues reading words as long as the
	next character in the input stream is not a whitespace character.
5.	for eachword it calls the "syntax_heredoc_word" to parse it.
6.	appends it to the previously parsed string using the ft_strjoin
	function.
7.	frees word and temp and returns the combined_word string	 */
char	*get_combined_heredoc_word(void)
{
	char	*combined_word;
	char	*word;
	char	*temp;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	if (fetch_token(GET).type != T_WORD)
		return (NULL);
	combined_word = syntax_heredoc_word(match(T_WORD));
	while (!mini_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_heredoc_word(match(T_WORD));
		temp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(temp);
	}
	return (combined_word);
}

/* 
This function is used to read and combine multiple words into one
single string.
1.	next variable is assigned the character at the current position
	in the command line, which is obtained using the g_manager.rc index
	and the g_manager.command_line array
2.	The match function is called with T_WORD as an argument to retrive
	the next token from the command line. if the token is not of
	type T_WORD the function returns NULL.
3.	syntax_word function is called to process the word and return a
	newly allocated string that contains the processed word.
4.	loop is started that continues as long as the next character in the
	command line is not whitespace and the next token is of type "T_WORD"
5.	"next" variable is updated with the next character in the command line
6.	"match" function is called again with "T_WORD" as an argument to retrieve
	the next token.
7.	syntax_word is called with the new token to process the word and return
	a newly allocated string that contains the processed word.
8.	ft_strjoin is called to concatenate "combined_word" and
	"word" into a new string.
9.	"word" and "temp" variables and freed
10.	combined_word string is returned */
char	*get_combined_word(void)
{
	char	*combined_word;
	char	*word;
	char	*token;
	char	*temp;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	combined_word = syntax_word(token);
	while (!mini_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_word(match(T_WORD));
		temp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(temp);
	}
	return (combined_word);
}
