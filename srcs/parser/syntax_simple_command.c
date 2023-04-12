/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:07:08 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 22:49:09 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/* This function reallocates memory for a char** buffer
by copying contents of the old buffer to the new one */
static void	*ft_ptrrealloc(void *buf, int before_size, int after_size)
{
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}

/*
1. 	if the simple_command structure is not allocated, it allocates
	memory for it using mini_calloc function and assigns the result to the 
	double pointer.
2.	it gets the executable path using the "get_combined_word function" and
	assigns it to the exec_path field of the structure.
3.	it allocates memory for the argv buffer using mini_calloc with a size
	of *ac + 2, where *ac is the number of elements in the argv buffer.
4.	assigns the exec_path to argv[0] and increments *ac.
5.	if the simple_command struct is already allocated, it assigns the existing 
	argv buffer to a local variable argv and counts the number of elements
	in it using a while loop and *ac variable.
6.	returns the argv buffer
*/
static char **init_simple_command(t_simple_command **simple_command, int *ac)
{
	char	**argv;

	if (*simple_command == NULL)
	{
		*simple_command = mini_calloc(1, sizeof(t_simple_command));
		(*simple_command)->exec_path = get_combined_word();
		argv = mini_calloc((*ac) + 2, sizeof(char *));
		argv[(*ac)++] = (*simple_command)->exec_path;
	}
	else
	{
		argv = (*simple_command)->argv;
		while (argv[(*ac)])
			(*ac)++;
	}
	return (argv);
}

/*
 The function processes a sequence of T_WORD tokens and 
 fills out a t_simple_command struct.
 1.	initalize and assign to argv using init_simple_command function
 2.	enters a loop that fetches the next token using fetch_token with
	an argument GET and checks if the type of token is T_WORD
3.	if it is T_WORD it reallocates memory for the rgv buffer using
	ft_ptrrealloc function with the old size of ac and new size of ac + 2.
4.	assigns the newly fetched T_WORD token to argv[ac] using the
	get_combined_word function and increments ac by 1
5.	if the token is not T_WORD, the loop ends and it assigns 
	NULL to argv[ac].
6.	it assigns the argv buffer to the argv field of the simple_command
	tructure and returns success flag.
*/
int	syntax_simple_command(t_simple_command **simple_command)
{
	int		ac;
	char	**argv;

	ac = 0;
	argv = init_simple_command(simple_command, &ac);
	while (fetch_token(GET).type == T_WORD)
	{
		argv = ft_ptrrealloc(argv, ac, ac + 2);
		argv[ac++] = get_combined_word();
	}
	argv[ac] = NULL;
	(*simple_command)->argv = argv;
	return (SUCCESS_FLAG);
}
