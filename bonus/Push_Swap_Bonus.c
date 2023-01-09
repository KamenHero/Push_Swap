/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:05:05 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/09 16:07:45 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	stacka = ft_linkin(argc, argv);
	ft_checkdup(stacka);
	if (argc == 1)
		return (0);
	line = get_next_line(0);
	while (line)
	{
		ft_condit(line, &stacka, &stackb);
		line = get_next_line(0);
	}
	if (ft_checking(stacka) == 0 && !stackb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_checkdup(t_list *stacka)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stacka;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				ft_exit();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	ft_condit(char *line, t_list **stacka, t_list **stackb)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(stacka);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(stacka);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(stacka);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(stacka, stackb);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(stackb);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(stackb);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(stackb);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(stackb, stacka);
	else
		ft_exit();
	free(line);
}
