/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toarray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:33 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/13 14:08:38 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	*ft_array(t_list *stacka)
{
	int		*str;
	t_list	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = stacka;
	i = ft_lstsize(stacka);
	tmp = stacka;
	str = malloc(sizeof(int) * i);
	if (!str)
		return (0);
	while (i)
	{
		str[j] = tmp->content;
		tmp = tmp->next;
		j++;
		i--;
	}
	ft_sortarray(str, j);
	if (ft_lstsize(stacka) != 3)
	{
		while (str[i])
		{
			j = 1;
			while (str[j])
			{
				if (str[i] == str[j + i])
					ft_exit();
				j++;
			}
			i++;
		}
	}
	return (str);
}

void	ft_sortarray(int *str, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k)
	{
		j = 0;
		while (j < k)
		{
			if (str[i] < str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
