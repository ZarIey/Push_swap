/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/15 18:12:22 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	if (argc == 1 || strncmp(argv[1], "\0", 1) == 0)
		exit(0);
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

int	new_check_duplicate(t_prog *prog)
{
	t_list	*stack_a;
	t_list	*stack_tag;
	int		i;
	int		j;

	i = 0;
	j = 1;
	stack_a = prog->stack_a;
	stack_tag = prog->stack_a->next;
	while (stack_tag)
	{
		stack_a = prog->stack_a;
		while (i < j)
		{
			if (stack_a->content == stack_tag->content)
				error();
			stack_a = stack_a->next;
			i++;
		}
		stack_tag = stack_tag->next;
		j++;
		i = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_prog	prog;
	t_list	*stack_a;

	if (check_argv(argc, argv) > 0)
		error();
	errors(argv);
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
	new_check_duplicate(&prog);
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
	return (0);
}
