/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:21:33 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/12 12:10:13 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 Extracts the environment variable name from a given
 string.
 1.	allocates memory for the name variable.
 2.	enters a while loop and checks wheather the charecter
	is alpha numeric.
3.	reallocates memory for the "name" string to accomodate 
	the new charecter.
4.	adds the character to the string.
5.	adds null to the end of name
6.	return name.
*/
char	*extract_env_name(char *token)
{
	char	*name;
	int		nc;

	nc = 0;
	name = mini_calloc(1, sizeof(char));
	while (ft_isalnum(*token))
	{
		name = ft_realloc(name, nc + 2);
		name[nc] = *token;
		nc++;
		token++;
	}
	name[nc] = '\0';
	return (name);
}

/* "$?" is a special variable that stores the exit status of
the previously executed command.
1.	checks if the special character to be replaced is '$?'
	if not returns a copy of the input token.
2.	if it is "$?" the function calls the "ft_itoa" function
	to covert the exit code to a string and assigned to the 
	"sc" variable.
3.	function extracts the part of the token that comes before
	the special charecter and assigns it to "prev" variable.
4.	increments the pointer to the special character to skip it
	and assigns the result to "env_ptr" variable.
5.	"word" variable is initialized by joining "pre" and "sc"
6.	calls the "replace_env" function on the part of the token
	that comes after the special character and assigned to next.
7.	word is updated by joining it with next.
8.	word is returned.
*/
char	*replace_env_sc(char *token, char *env_ptr)
{
	char	*sc;
	char	*prev;
	char	*next;
	char	*word;

	if (*(env_ptr + 1) == '?')
		sc = ft_itoa(g_manager.exit_code);
	else
		return (ft_strdup(token));
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(sc);
	word = ft_strjoin(prev, sc);
	free(sc);
	free(prev);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/*
Takes a string and a pointer to the position of the env variable
name as input, and replace it with corresponding env variable value
1.	extracts the name of the env variable using "extract_env_name"
2.	finds the word before the environment variable.
3.	calls get_env to get the value of the environment variable using
	its name.
4.	if the environment variable is found in the variables list, the
	variable name in the "token" string is replaced with its
	value using "ft_strjoin"
5.	calls "replace_env" to check for any other environment
	variables in the updated "token" string.
6.	returns the updated "token" string with all the 
	environment variables replaced by its values
*/
char	*replace_env_name(char *token, char *env_ptr)
{
	char	*name;
	t_env	*env;
	char	*prev;
	char	*next;
	char	*word;

	name = extract_env_name(env_ptr + 1);
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(name);
	env = get_env(name);
	if (env)
	{
		word = ft_strjoin(prev, env->value);
		free(prev);
	}
	else
		word = prev;
	free(name);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/*
 This function takes a string as input and replaces any
 environment variables in it.
 1.	searches for the first occurence of "$" in the "token"
	using "ft_strchr" function.
2.	if "$" is not found it means there are no environment
	variables in the "token" string and returns a copy of "token"
3.	if "$" is found the function checks the character immediately
	following "$". if the character is a "?" it calls the
	"replace_env_sc" function to replace the special environment
	variable "$?" with the exit code of the last executed
	command.
4.	if the character is an alphabet, it calls the "replace_env_name"
	function to replace the "$ENV_VAR_NAME" string with the value
	of the corresponding environment variable.
5.	if the character is not a valid environment variable, the function
	returns a copy of token.
6.	the function returns a pointer to the modified string "word" containing
	the replaced environment variable references.
*/
char	*replace_env(char	*token)
{
	char	*word;
	char	*env_ptr;

	env_ptr = ft_strchr(token, '$');
	while (env_ptr && *(env_ptr + 1) && !(*(env_ptr + 1) == '?'
		|| ft_isalpha(*(env_ptr + 1))))
		env_ptr = ft_strchr(env_ptr + 1, '$');
	if (!env_ptr)
		return (ft_strdup(token));
	if (*(env_ptr + 1) == '?')
		word = replace_env_sc(token, env_ptr);
	else if (ft_isalpha(*(env_ptr + 1)))
		word = replace_env_name(token, env_ptr);
	else
		word = ft_strdup(token);
	return (word);
}

/*
 1.	if the token is a double quoted string it removes the 
	quotation marks and passes the resulting string to 
	replace_env for variable replacement.
2.	if the token is a single quoted string, it removes the 
	quotation marks but doesnot perform any variable 
	replacement.
3.	else, it passes the token to "replace_env" for variable
	replacement.
*/
char	*syntax_word(char *token)
{
	char	*word;
	char	*temp;

	if (*token == U_DOUBLE_QUOTES)
	{
		word = ft_substr(token, 1, ft_strlen(token) - 2);
		temp = word;
		word = replace_env(word);
		free(temp);
	}
	else if (*token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = replace_env(token);
	free(token);
	return (word);
}
