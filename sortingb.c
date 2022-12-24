/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:31:17 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/11 13:31:19 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_sb(t_list **stackb)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = (*stackb);
	temp = (*stackb)->next;
	temp2->next = temp2->next->next;
	temp->next = temp2;
	(*stackb) = temp;
	write(1, "sb\n", 3);
}

void	ft_rb(t_list **stackb)
{
	t_list	*temp;

	temp = (*stackb);
	(*stackb) = (*stackb)->next;
	ft_lstadd_back(stackb, temp);
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **stackb)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (*stackb);
	temp2 = (*stackb);
	if (ft_lstsize(*stackb) == 2)
	{
		ft_sb(stackb);
		return ;
	}
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = (*stackb);
	(*stackb) = temp;
	temp2->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_pb(t_list **stackb, t_list **stacka)
{
	t_list	*temp;

	temp = (*stacka)->next;
	(*stacka)->next = (*stackb);
	(*stackb) = (*stacka);
	(*stacka) = temp;
	write(1, "pb\n", 3);
}
