/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:44:26 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/10 10:44:28 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	ft_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_freed(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	freen(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	tmp = (*stack)->next;
	while (tmp != NULL && (*stack) != NULL)
	{
		free(*stack);
		(*stack) = tmp;
		tmp = (*stack)->next;
	}
}

void	ft_checkd(char *str, t_list *stack, char **sr)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i && !str[i])
	{
		freen(&stack);
		ft_freed(sr);
		ft_exit();
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			freen(&stack);
			ft_freed(sr);
			ft_exit();
		}
		i++;
	}
}

t_list	*ft_linkin(int argc, char **argv)
{
	char	**str;
	int		j;
	int		i;
	t_list	*stacka;
	t_list	*temp;

	j = 0;
	i = 0;
	stacka = NULL;
	temp = stacka;
	if (argc >= 2)
	{
		while (argc > 1)
		{
			str = ft_split(argv[argc - 1], ' ');
			while (str[j])
				j++;
			while (j > 0)
			{
				ft_checkd(str[j - 1], stacka, str);
				ft_lstadd_front(&stacka, ft_lstnew(ft_atoi(str[j - 1])));
				j--;
			}
			ft_freed(str);
			argc--;
		}
	}
	return (stacka);
}
