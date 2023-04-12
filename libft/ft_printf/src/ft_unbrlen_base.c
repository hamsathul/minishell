/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:26:12 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/20 20:26:12 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

size_t	ft_unbrlen_base(unsigned long long int nbr, size_t base_len)
{
	size_t	i;

	i = 1;
	while (nbr >= (unsigned long long int)base_len)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}
