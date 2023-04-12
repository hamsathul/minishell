/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:24:36 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/21 09:24:36 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_uputnbr_base(unsigned long long int nbr, const char *base)
{
	unsigned long long int	base_len;
	int						nbr_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_uputnbr_base(nbr / base_len, base);
		ft_uputnbr_base(nbr % base_len, base);
	}
	else
		write(1, &base[nbr], 1);
	nbr_len += ft_unbrlen_base(nbr, base_len);
	return (nbr_len);
}
