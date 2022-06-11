/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/11 19:19:52 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	void_arg(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

void	little_arg(t_prog prog)
{
	if (prog.size == 5 && check_sorted(&prog) < 0)
	{
		sort_five(&prog);
		exit (0);
	}
	if (prog.size == 3 && check_sorted(&prog) < 0)
	{
		sort_triple(&prog);
		exit (0);
	}
	if (prog.size == 2 && check_sorted(&prog) < 0)
	{
		swap_a(&prog.stack_a);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_prog	prog;
	t_list	*stack_a;

	if (check_argv(argc, argv) > 0 || argc == 1)
		error();
	errors(argv);
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
	prog.size = size_list(prog.stack_a);
	stack_a = (prog.stack_a);
	ghost_sorting(&stack_a);
	init_rank(stack_a, &prog);
	if (check_sorted(&prog) < 0)
	{
		little_arg(prog);
		rotate_sequence(&prog);
		final_sort(&prog);
	}
//	system ("leaks push_swap");
	return (0);
}
