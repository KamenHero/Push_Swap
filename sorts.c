/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:41:19 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/19 20:41:21 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_case3(t_list **stacka)
{
	int	i;
	int	j;
	int	k;

	i = (*stacka)->content;
	j = (*stacka)->next->content;
	k = (*stacka)->next->next->content;
	if (i < j && j > k && i < k)
	{
		ft_rra(stacka);
		ft_sa(stacka);
	}
	else if (i > j && i < k)
		ft_sa(stacka);
	else if (i < j && i > k && j > k)
	{
		ft_rra(stacka);
	}
	else if (i > j && i > k && j < k)
		ft_ra(stacka);
	else if (i > j && i > k && j > k)
	{
		ft_sa(stacka);
		ft_rra(stacka);
	}
}

void	ft_case5(t_list **stacka, t_list **stackb)
{
	int	*str;
	int	i;

	i = 0;
	str = ft_array(*stacka);
	i = 0;
	while (ft_lstsize(*stacka) != 3)
	{
		if (ft_index(*stacka, str[i]) <= 2)
		{
			while ((*stacka)->content != str[i])
				ft_ra(stacka);
		}
		else
			while ((*stacka)->content != str[i])
				ft_rra(stacka);
		ft_pb(stackb, stacka);
		i++;
	}
	ft_case3(stacka);
	while (*stackb)
		ft_pa(stacka, stackb);
}

int	ft_index(t_list *tmp, int i)
{
	int	j;

	j = 0;
	while (tmp->content != i)
	{
		j++;
		tmp = tmp->next;
	}
	return (j);
}

void	ft_othercase(t_list **stacka, t_list **stackb, int *str)
{
	int	middle;
	int	offset;
	int	start;
	int	end;
	int	n;

	middle = ft_lstsize(*stacka) / 2;
	if (ft_lstsize(*stacka) <= 10)
		n = 5;
	else if (ft_lstsize(*stacka) <= 150)
		n = 8;
	else
		n = 18;
	offset = ft_lstsize(*stacka) / n;
	start = middle - offset;
	end = middle + offset;
	while (*stacka)
	{
		if (ft_lstsize(*stacka) == 1)
			ft_pb(stackb, stacka);
		while (*stacka)
		{
			n = ft_search(stacka, str, start, end);
			if (n == ft_lstsize(*stacka))
			{
				start -= offset;
				end += offset;
				if (start < 0)
					start = 0;
				if (end > middle * 2 - 1)
					end = middle * 2 - 1;
				break ;
			}
			if (n <= ft_lstsize(*stacka) / 2)
			{
				while (n > 0)
				{
					ft_ra(stacka);
					n--;
				}
			}
			else
			{
				while (n < ft_lstsize(*stacka))
				{
					ft_rra(stacka);
					n++;
				}
			}
			ft_pb(stackb, stacka);
			if ((*stackb)->next && (*stackb)->content < str[middle])
				ft_rb(stackb);
		}
	}
	ft_backtostacka(stacka, stackb, str);
}

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
