/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:30:17 by oryadi            #+#    #+#             */
/*   Updated: 2022/10/16 14:30:19 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_checkminmax(int sign, unsigned long result)
{
	if ((long)(sign * result) < INT_MIN || result > INT_MAX)
		ft_exit();
}

void	ft_checklong(int sign, unsigned long result)
{
	if (result > 9223372036854775807 && sign == 1)
		ft_exit();
	else if (result > 9223372036854775807 && sign == -1)
		ft_exit();
}

void	ft_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i++] - '0';
		ft_checklong(sign, result);
	}
	ft_checkminmax(sign, result);
	return (sign * result);
}
