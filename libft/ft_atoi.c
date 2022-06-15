/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:06:26 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/15 18:08:46 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checker_atoi(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		i++;
	}
}

long long int	ft_atoi(char *str)
{
	int				i;	
	long long int	nombre;
	int				sign;

	i = 0;
	nombre = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	checker_atoi(str, str[i]);
	while (str[i] >= 48 && str[i] <= 57)
	{
		nombre = nombre * 10 + str[i] - 48;
		i++;
	}
	return (nombre * sign);
}
