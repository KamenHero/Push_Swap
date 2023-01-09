/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:28:51 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/25 16:29:04 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search(t_list **stacka, int *str, int start, int end)
{
	t_list	*tmp;
	int		j;

	tmp = (*stacka);
	j = 0;
	while (tmp)
	{
		if (tmp->content >= str[start] && tmp->content <= str[end])
			return (j);
		j++;
		tmp = tmp->next;
	}
	return (j);
}
