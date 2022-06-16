/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:22:57 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/16 16:31:14 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include "../libft/libft.h"

int	void_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			return (0);
		while (argv[i] && argv[i] == 32)
		{
			if (argv[i] != 32)
			{
				if ((argv[i] >= 48 && argv[i] <= 57))
					return (0);
				return (1);
			}
			i++;
			if (!(argv[i]))
				exit(0);
		}
		if ((argv[i] >= 48 && argv[i] <= 57))
			return (0);
		return (1);
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	if (argc == 2)
	{
		if (void_arg(argv[1]) > 0)
			return (1);
	}
	return (0);
}

void	init_checker(t_checker *checker, int argc, char **argv)
{
	if (argc == 1 || strncmp(argv[1], "\0", 1) == 0)
		exit(0);
	if (check_argv(argc, argv) > 0)
	{
		write (1, "Error\n", 6);
		exit(0);
	}
	errors(argv);
	checker->stack_a = creation_stack(argc, argv);
	checker->stack_b = NULL;
}

int	main(int argc, char **argv)
{
	t_checker	checker;
	int			i;
	int			size;
	char		*str;

	i = 0;
	init_checker(&checker, argc, argv);
	size = ch_size_list(checker.stack_a);
	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (str)
		{
			checker_b_not_empty(&checker, str);
			action_commands(&checker, str);
			free(str);
		}
	}
	sorted_or_not_uh_uh(&checker, size);
	return (0);
}
