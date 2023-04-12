/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_isspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:26:30 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/30 10:31:45 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	mini_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

// int main()
// {
// 	if (mini_isspace('a') == 1)
// 		printf("there is space");
// 	else
// 		printf("there is no space");
// }