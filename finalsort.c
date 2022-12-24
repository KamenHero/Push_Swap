/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:14:45 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/22 18:14:47 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_backtostacka(t_list **stacka, t_list **stackb, int *str)
{
	int	i;

	i = ft_lstsize(*stackb) - 1;
	while ((*stackb))
	{
		if (ft_index (*stackb, str[i]) < (i + 1) / 2)
		{
			while ((*stackb)->content != str[i])
			{
				if (i >= 1 && (*stackb)->content == str[i - 1])
					ft_pa(stacka, stackb);
				else
					ft_rb(stackb);
			}
		}
		else
		{
			while ((*stackb)->content != str[i])
			{
				if (i > 1 && (*stackb)->content == str[i - 1])
					ft_pa(stacka, stackb);
				else
					ft_rrb(stackb);
			}
		}
		ft_pa(stacka, stackb);
		if ((*stacka)->next && (*stacka)->content > (*stacka)->next->content)
		{
			ft_sa(stacka);
			i--;
		}
		i--;
	}
	free (str);
}

void	ft_exit(void)
{
	ft_putendl_fd("Error", 2);
	system("leaks push_swap");
	exit(-1);
}
