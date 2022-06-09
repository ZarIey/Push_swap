/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/09 15:59:53 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_prog prog;
	t_list *stack_a;
	
	if (argc <= 1)
		return (0);
	errors(argv);
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
	prog.size = size_list(prog.stack_a);
	if (check_sorted(&prog) < 0)
	{
		stack_a = (prog.stack_a);
		if (argc == 3 && check_sorted(&prog) < 0)
		{
			swap_a(&prog.stack_a);
			exit(0);
		}
		if (argc == 4)
			{
				sort_triple(&prog);
				return (0);
			}
		ghost_sorting(&stack_a);
		init_rank(stack_a, &prog);
		if (size_list(prog.stack_a) == 5)
		{
			sort_five(&prog);		
			return (0);
		}
		rotate_sequence(&prog);		
		final_sort(&prog);	
	}
 //	system("leaks push_swap");
	return(0);
}

