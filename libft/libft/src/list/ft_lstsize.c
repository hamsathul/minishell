/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:37:56 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:33:37 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstsize(t_list *list)
{
	int	num;

	num = 0;
	while (list)
	{
		num++;
		list = list->next;
	}
	return (num);
}

/* int main()
{
	t_list *l;
	int actual;
	int expected;

	l = ft_lstnew(ft_strdup("1"));
	l->next = ft_lstnew(ft_strdup("2"));
	l->next->next = ft_lstnew(ft_strdup("3"));
	expected = 3;
	actual = ft_lstsize(l);
	if (actual == expected)
		exit(printf("%d", actual));
	exit(printf("fail"));
} */