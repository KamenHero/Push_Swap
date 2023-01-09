/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:25:44 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/25 00:25:47 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_laststacka(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(*stacka) == 1)
		ft_pb(stackb, stacka);
}

void	ft_checkstartandend(int *start, int *end, int middle, int offset)
{
	*start -= offset;
	*end += offset;
	if (*start < 0)
		*start = 0;
	if (*end > middle * 2 - 1)
		*end = middle * 2 - 1;
}

int	ft_checkn(t_list **stacka)
{
	int	n;

	if (ft_lstsize(*stacka) <= 10)
		n = 5;
	else if (ft_lstsize(*stacka) <= 150)
		n = 8;
	else
		n = 18;
	return (n);
}

void	ft_condition1(t_list **stacka, int n)
{
	if (n <= ft_lstsize(*stacka) / 2)
	{
		while (n > 0)
		{
			ft_ra(stacka);
			n--;
		}
	}
}

void	ft_condition2(t_list **stacka, int n)
{
	if (n > ft_lstsize(*stacka) / 2)
	{
		while (n < ft_lstsize(*stacka))
		{
			ft_rra(stacka);
			n++;
		}
	}
}
