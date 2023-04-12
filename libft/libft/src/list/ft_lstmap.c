/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:08:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:33:27 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*result;

	result = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear (&result, del);
			return (NULL);
		}
		if (!result)
			result = newnode;
		else
			ft_lstadd_back (&result, newnode);
		lst = lst->next;
	}
	return (result);
}
