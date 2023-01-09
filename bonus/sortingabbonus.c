/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingabbonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:03:17 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/09 15:12:32 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap_bonus.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_checking(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
