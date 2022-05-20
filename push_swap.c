/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/19 18:58:00 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_list **pstack_a);

void print_list_a(t_list *stack_a)
{
	int i = 0;
	int j = 1;
	i = ft_lstsize(stack_a);
	printf("\nlist A avec %d arg\n\n", i);

    while(stack_a) 
	{
        printf("lst %d contient %d\n",j ,stack_a->content);
		j++;
        stack_a = stack_a->next;
    }
}

void print_list_b(t_list *stack_b)
{
	int i = 0;
	int j = 1;
	i = ft_lstsize(stack_b);
	printf("\nlist B avec %d arg\n\n", i);
	
    while(stack_b) 
	{
        printf("lst %d contient %d\n",j ,stack_b->content);
		j++;
        stack_b = stack_b->next;
    }
}

void print_list (t_prog *prog)
{
	print_list_a(prog->stack_a);
	print_list_b(prog->stack_b);
}

void	initialise_values(t_prog *prog)
{
	prog->big = find_biggest_asc_order(prog->stack_a, 1);
	prog->size = size_list(prog->stack_a);
	prog->group_count = compare_big(1, (int)(prog->total / 150.0));
	prog->group_size = prog->total / prog->group_count;
}

int main(int argc, char **argv)
{
	t_prog prog;
	t_list *stack_a;
	
	if (argc <= 1)
		return (0);
	errors(argv);
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
//	print_list_a(prog.stack_a);
	print_list(&prog);
	if (check_sorted(&prog) < 0)
	{
		stack_a = (prog.stack_a);
		if (size_list(prog.stack_a) <= 3)
			sort_triple(&prog);
		push_bigger(&stack_a);
		init_rank(stack_a, &prog);
		if (size_list(prog.stack_a) == 5)
			sort_five(&prog);
//		final_sort(&(prog.stack_a));		
	}
	print_list(&prog);
		
//		if (size_list(prog.stack_a) == 5)
//		printf("Oh oh la stack est plus grande que 3 la TDC\n");i
//		print_list(stack_a, stack_b);
//	 	initial_push(pstack_a, pstack_b);
//	 	sort_triple(pstack_a);
//		printf("avant action :\n");
//			sort_quint(&prog);
//		print_list(&prog);
//		sort(pstack_a, pstack_b);
		// printf("mini : %d\n",get_mini(stack_a));
		// printf("maxi : %d\n",get_maxi(stack_a));
//		print_list(stack_a, stack_b);
//		push_a(pstack_a, pstack_b);
//		print_list(stack_a, stack_b);
	return(0);
}
	// already_sorted(stack_a);
	//sort_triple(pstack_a);

//	push_b(pstack_a, pstack_b);
//	push_b(pstack_a, pstack_b);
//	push_a(pstack_a, pstack_b);
//	print_list(stack_a, stack_b);
	
//  system("leaks push_swap");


