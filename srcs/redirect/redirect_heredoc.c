/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:05:18 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/09 15:30:41 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

static int	end_of_heredoc(char *line, int fd)
{
	free(line);
	if (close(fd) == -1)
		return (error_exit("close", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}

/* 
this function redirects the input of a shell command to a file specified 
by "heredoc_path" until the end text specified by "end_text" is encountered.
1.	sets up a signal handler to catch the intrerrupt signal
	so the user can interrupt the heredoc input by typing ctrl + c
2.	opens the file specified by heredoc_path with the appropriate flags
3.	enters the loop and reads the input using readline function untill
	the user types the end text specified by the "end_text" or
	inturrupts the input using ctrl + c.
4.	for each line it writes the input to the file using the 
	ft_putendl_fd function.
5.	if end_text is encountered or the user inturrupts the input
	the function calls end_of_heredoc function to free the allocated
	memory and close the file descriptor.
*/
int	redirect_heredoc(char *end_text, char *heredoc_path)
{
	int		fd;
	char	*line;

	heredoc_signal();
	fd = open(heredoc_path, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 00644);
	if (fd < 0)
		error_exit("open", strerror(errno), EXIT_FAILURE);
	while (!g_manager.exit_code)
	{
		line = readline(PS2);
		if (!line || mini_strcmp(line, end_text))
			return (end_of_heredoc(line, fd));
		ft_putendl_fd(line, fd);
		free(line);
	}
	if (close(fd) == -1)
		error_exit("close", strerror(errno), EXIT_FAILURE);
	return (EXIT_FAILURE);
}
