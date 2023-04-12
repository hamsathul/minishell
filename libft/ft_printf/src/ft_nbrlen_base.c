/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/20 20:08:19 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_nbrlen_base(long long int nbr, size_t base_len)
{
	size_t	i;

	i = 1;
	while (nbr >= (long long int) base_len)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}
