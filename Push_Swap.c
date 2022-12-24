/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:53:29 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/13 15:53:31 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		*str;
	int		i;

	i = 0;
	stacka = NULL;
	stackb = NULL;
	stacka = ft_linkin(argc, argv);
	str = ft_array(stacka);
	if (ft_lstsize(stacka) == 2 && stacka->content > stacka->next->content)
		ft_ra(&stacka);
	if (ft_lstsize(stacka) == 3)
		ft_case3(&stacka);
	if (ft_lstsize(stacka) == 5 || ft_lstsize(stacka) == 4)
		ft_case5(&stacka, &stackb);
	if (ft_lstsize(stacka) > 5)
		ft_othercase(&stacka, &stackb, str);
}
