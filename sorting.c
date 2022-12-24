/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:24:34 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/10 18:24:36 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_sa(t_list **stacka)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = (*stacka);
	temp = (*stacka)->next;
	temp2->next = temp2->next->next;
	temp->next = temp2;
	(*stacka) = temp;
	write(1, "sa\n", 3);
}

void	ft_ra(t_list **stacka)
{
	t_list	*temp;

	temp = (*stacka);
	(*stacka) = (*stacka)->next;
	ft_lstadd_back(stacka, temp);
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **stacka)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (*stacka);
	temp2 = (*stacka);
	if (ft_lstsize(*stacka) == 2)
	{
		ft_sa(stacka);
		return ;
	}
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = (*stacka);
	(*stacka) = temp;
	temp2->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_pa(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	temp = (*stackb)->next;
	(*stackb)->next = (*stacka);
	(*stacka) = (*stackb);
	(*stackb) = temp;
	write(1, "pa\n", 3);
}
