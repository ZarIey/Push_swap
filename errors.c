/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:17:49 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/14 14:04:37 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	no_param(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	if (i <= 1)
		exit(0);
} 

int check_letter(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] >= 97 && argv[i][j] <= 122) || (argv[i][j] >= 65 && argv[i][j] <= 90))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int check_int_scale(char **argv)
{
	int i;
	long int c;

	i = 1;
	while (argv[i])
	{
		c = ft_atoi(argv[i]);
		if ((c > 2147483647) || (c < -2147483648))
			return (-1);
		i++;
	}
	return (0);
}

int check_duplicate(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (j < i)
		{
			if (ft_strncmp(argv[j], argv[i], 11) == 0)
				return(-1);
			j++;
		}
		i++;
		j = 0;
	}
	return(0);
}

int errors(char **argv)
{
	no_param(argv);
	if ((check_letter(argv) == -1) || (check_int_scale(argv) == -1) || (check_duplicate(argv) == -1))
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	return (0);
}
