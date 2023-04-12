/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:40:22 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/30 12:40:47 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"
# include "token.h"
# include "../libft/libft/include/libft.h"

//Error code 255: exit status outof range
# define EXIT_MAX 255
//Error code 258: syntax error
# define EXIT_SYNTAXERR 258
//Error code 126: command invoked cannot execute
//missing execute permissions
# define EXIT_EACCES 126
//Error code 127: command not found
//command doesnot exist in the path
// or wrong command name
# define EXIT_ENOENT 127
# define ERROR_FLAG -1
# define SUCCESS_FLAG 0

int	error_usage(char *cmd, char *argv);
int	error_exit(char *cmd, char *err, int exit_code);
int	error_general(char *cmd, char *argv, char *err_msg);
int	error_env(char *cmd, char *argv);
int	error_syntax(t_token token);

#endif