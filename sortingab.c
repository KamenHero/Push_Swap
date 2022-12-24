/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:35:04 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/11 13:35:06 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_ss(t_list **stacka, t_list **stackb)
{
	ft_sa(stacka);
	ft_sb(stackb);
}

void	ft_rr(t_list **stacka, t_list **stackb)
{
	ft_ra(stacka);
	ft_rb(stackb);
}

void	ft_rrr(t_list **stacka, t_list **stackb)
{
	ft_rra(stacka);
	ft_rrb(stackb);
}
