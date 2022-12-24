/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:52:22 by oryadi            #+#    #+#             */
/*   Updated: 2022/12/14 13:52:26 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	ft_sa(t_list **stacka);
void	ft_ra(t_list **stacka);
void	ft_rra(t_list **stacka);
void	ft_pa(t_list **stacka, t_list **stackb);
void	ft_sb(t_list **stackb);
void	ft_rb(t_list **stackb);
void	ft_rrb(t_list **stackb);
void	ft_pb(t_list **stackb, t_list **stacka);
t_list	*ft_linkin(int argc, char **argv);
int		*ft_array(t_list *stacka);
void	ft_sortarray(int *str, int k);
void	ft_swap(int *a, int *b);
void	ft_checkd(char *str, t_list *stack, char **sr);
void	ft_freed(char **str);
void	freen(t_list **stack);
void	ft_case3(t_list **stacka);
void	ft_case5(t_list **stacka, t_list **stackb);
int		ft_index(t_list *tmp, int i);
void	ft_othercase(t_list **stacka, t_list **stackb, int *str);
int		ft_search(t_list **stacka, int *str, int start, int end);
void	ft_backtostacka(t_list **stacka, t_list **stackb, int *str);

#endif
