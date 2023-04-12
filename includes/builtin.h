/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:41:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:33:58 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "error.h"
# include "../libft/libft/include/libft.h"
# include "minishell.h"
# include <stdlib.h>

int				check_option(char *argv);
int				ft_cd(char **argv);
int				ft_echo(char **argv);
int				ft_env(char **argv);
int				ft_export(char	**argv);
int				ft_exit(char **argv);
int				ft_pwd(char **argv);
int				ft_unset(char **argv);
int				is_builtin(char *func_name);
unsigned char	check_exit_arg(char *arg);
int				valid_exit_code(const char *s);

#endif