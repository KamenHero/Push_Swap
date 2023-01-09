/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:41:19 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/08 21:28:01 by oryadi           ###   ########.fr       */
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
	free (str);
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
	int		offset;
	int		start;
	int		end;
	int		n;
	t_data	data;

	ft_3emr(stacka, &n, &data.middle, &offset);
	data.str = str;
	start = data.middle - offset;
	end = data.middle + offset;
	while (*stacka)
	{
		ft_laststacka(stacka, stackb);
		while (*stacka)
		{
			n = ft_search(stacka, data.str, start, end);
			if (n == ft_lstsize(*stacka))
			{
				ft_checkstartandend(&start, &end, data.middle, offset);
				break ;
			}
			ft_condition(stacka, stackb, n, data);
		}
	}
	ft_backtostacka(stacka, stackb, data.str);
}

void	ft_3emr(t_list **stacka, int *n, int *middle, int *offset)
{
	*middle = ft_lstsize(*stacka) / 2;
	*n = ft_checkn(stacka);
	*offset = ft_lstsize(*stacka) / *n;
}
