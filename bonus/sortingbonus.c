/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingbonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:59:33 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/09 16:03:10 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <libft.h>

void	ft_sa(t_list **stacka)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stacka))
		return ;
	if ((*stacka)->next)
	{
		temp2 = (*stacka);
		temp = (*stacka)->next;
		temp2->next = temp2->next->next;
		temp->next = temp2;
		(*stacka) = temp;
	}
	else
		return ;
}

void	ft_ra(t_list **stacka)
{
	t_list	*temp;

	if (!(*stacka))
		return ;
	if ((*stacka)->next)
	{
		temp = (*stacka);
		(*stacka) = (*stacka)->next;
		ft_lstadd_back(stacka, temp);
		temp->next = NULL;
	}
}

void	ft_rra(t_list **stacka)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stacka))
		return ;
	temp = (*stacka);
	temp2 = (*stacka);
	if (ft_lstsize(*stacka) == 2)
	{
		ft_sa(stacka);
		return ;
	}
	if ((*stacka)->next)
	{
		while (temp->next)
			temp = temp->next;
		while (temp2->next->next)
			temp2 = temp2->next;
		temp->next = (*stacka);
		(*stacka) = temp;
		temp2->next = NULL;
	}
}

void	ft_pa(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	if (!(*stackb))
		return ;
	temp = (*stackb)->next;
	(*stackb)->next = (*stacka);
	(*stacka) = (*stackb);
	(*stackb) = temp;
}
