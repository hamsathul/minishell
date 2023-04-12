/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_heredoc_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:51:42 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:21:14 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*syntax_heredoc_word(char *token)
{
	char	*word;

	if (*token == U_DOUBLE_QUOTES || *token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = ft_strdup(token);
	free(token);
	return (word);
}