/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 17:42:20 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int void_arg (char *argv)
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
				return(1);
			}
			i++;
		}
		if ((argv[i] >= 48 && argv[i] <= 57))
			return (0);
		return(1);
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	(void)argv;
	
	if (argc == 2)
	{
	//	write(1, "ya\n", 3);
		if (void_arg(argv[1]) > 0)
			return (1);
	}
//	printf("all fine\n");
	return(0);
}

int main(int argc, char **argv)
{
	t_prog prog;
	t_list *stack_a;
	
	if (check_argv(argc, argv) > 0)
	{
	//	write(1, "1", 1);
		exit(0);
	}
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
	// system("leaks push_swap");
	errors(argv);
	prog.size = size_list(prog.stack_a);
	if (check_sorted(&prog) < 0 && prog.size > 1)
	{
		stack_a = (prog.stack_a);
		if (prog.size == 2 && check_sorted(&prog) < 0)
		{
			swap_a(&prog.stack_a);
		//	system("leaks push_swap");
			exit(0);
		}
		if (prog.size == 3 && check_sorted(&prog) < 0)
			{
				sort_triple(&prog);
			//	system("leaks push_swap");
				return (0);
			}
		ghost_sorting(&stack_a);
		init_rank(stack_a, &prog);
		if (size_list(prog.stack_a) == 5)
		{
			sort_five(&prog);
		//	system("leaks push_swap");		
			return (0);
		}
		rotate_sequence(&prog);		
		final_sort(&prog);	
	}
	// system("leaks push_swap");
	return(0);
}

