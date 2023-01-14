/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:57:18 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/14 17:40:39 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <libft.h>
# include "get_next_line.h"

typedef struct data
{
	int				middle;
	int				*str;
}					t_data;

t_list	*ft_linkin(int argc, char **argv);
void	ft_checkd(char *str, t_list *stack, char **sr);
void	ft_freed(char **str);
void	freen(t_list **stack);
void	ft_sa(t_list **stacka);
void	ft_ra(t_list **stacka);
void	ft_rra(t_list **stacka);
void	ft_pa(t_list **stacka, t_list **stackb);
void	ft_sb(t_list **stackb);
void	ft_rb(t_list **stackb);
void	ft_rrb(t_list **stackb);
void	ft_pb(t_list **stackb, t_list **stacka);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_checking(t_list *stacka);
void	ft_checkdup(t_list *stacka);
void	ft_condit(char *line, t_list **stacka, t_list **stackb);
void	ft_ss(t_list **stacka, t_list **stackb);
void	ft_rr(t_list **stacka, t_list **stackb);
void	ft_rrr(t_list **stacka, t_list **stackb);

#endif
