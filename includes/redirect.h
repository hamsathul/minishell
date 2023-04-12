/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:30:31 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 12:41:32 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

# define READ 0
# define WRITE 1
# define ERROR 2
# define TRASH_PATH "/dev/null"
# define BACKUP_FD 255

int	redirect_in_file(char *file_path);
int	redirect_out_file(char *file_path);
int	redirect_append_file(char *file_path);
int	redirect_heredoc(char *end_text, char *heredoc_path);
int	redirect_out_trash(void);
int	reset_std_fd(int std_fd[3]);
int	backup_std_fd(int std_fd[3]);

#endif