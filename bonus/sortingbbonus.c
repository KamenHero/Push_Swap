/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingbbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:01:52 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/08 16:45:37 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap_bonus.h"

void	ft_sb(t_list **stackb)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stackb))
		return ;
	if ((*stackb)->next)
	{
		temp2 = (*stackb);
		temp = (*stackb)->next;
		temp2->next = temp2->next->next;
		temp->next = temp2;
		(*stackb) = temp;
	}
}

void	ft_rb(t_list **stackb)
{
	t_list	*temp;

	if (!(*stackb))
		return ;
	if ((*stackb)->next)
	{
		temp = (*stackb);
		(*stackb) = (*stackb)->next;
		ft_lstadd_back(stackb, temp);
		temp->next = NULL;
	}
}

void	ft_rrb(t_list **stackb)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stackb))
		return ;
	temp = (*stackb);
	temp2 = (*stackb);
	if (ft_lstsize(*stackb) == 2)
	{
		ft_sb(stackb);
		return ;
	}
	if ((*stackb)->next)
	{
		while (temp->next)
			temp = temp->next;
		while (temp2->next->next)
			temp2 = temp2->next;
		temp->next = (*stackb);
		(*stackb) = temp;
		temp2->next = NULL;
	}
}

void	ft_pb(t_list **stackb, t_list **stacka)
{
	t_list	*temp;

	if (!(*stacka))
		return ;
	temp = (*stacka)->next;
	(*stacka)->next = (*stackb);
	(*stackb) = (*stacka);
	(*stacka) = temp;
}
