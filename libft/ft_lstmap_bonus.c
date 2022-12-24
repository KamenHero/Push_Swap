/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:01:50 by oryadi            #+#    #+#             */
/*   Updated: 2022/10/30 16:01:51 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*new;
	int		data;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	newlst = 0;
	while (temp)
	{
		data = f(temp->content);
		new = ft_lstnew(data);
		if (!new)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new);
		temp = temp->next;
	}
	return (newlst);
}
