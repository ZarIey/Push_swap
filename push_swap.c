/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/07 20:05:36 by ctardy           ###   ########.fr       */
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
        printf("---- lst %d contient %d\n",j ,stack_a->content);
 //       printf("elle est en stay %d\n",stack_a->stay);
 //       printf("avec l'index %d\n",stack_a->index);
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
        printf("---- lst %d contient %d\n",j ,stack_b->content);
  //      printf("elle est en stay %d\n",stack_b->stay);
 //       printf("avec l'index %d\n",stack_b->index);
		j++;
        stack_b = stack_b->next;
    }
}

void print_list (t_prog *prog)
{
	print_list_a(prog->stack_a);
	print_list_b(prog->stack_b);
}

void print_one_list(t_list **stack_a, t_list *list)
{
	t_list *inter;

	inter = *stack_a;
	while (inter && inter != list)
	{
		inter = inter->next;
	}
	printf("valeur de la list choisis : %d\n", inter->content);
}

void	set_up(t_prog *prog)
{
//	prog->strike = find_biggest_asc_order(prog->stack_a, 1);
	prog->size = size_list(prog->stack_a);
	prog->group_count = compare_big(1, (int)(prog->size / 150.0));
	prog->group_size = prog->size / prog->group_count;
}

int main(int argc, char **argv)
{
	t_prog prog;
	t_list *stack_a;
//	t_list *start_strike;
	
	if (argc <= 1)
		return (0);
	errors(argv);
	prog.stack_a = creation_stack(argc, argv);
	prog.stack_b = NULL;
//	print_list(&prog);
	if (check_sorted(&prog) < 0)
	{
		stack_a = (prog.stack_a);
		if (size_list(prog.stack_a) <= 3)
			{
				sort_triple(&prog);
				return (0);
			}
		ghost_sorting(&stack_a);
		init_rank(stack_a, &prog);
		if (size_list(prog.stack_a) == 5)
		{
			sort_five(&prog);
		//	print_list(&prog);		
			return (0);
		}
		set_up(&prog);
//		start_strike = init_sequence(&prog);
//		print_one_list(&prog.stack_a, start_strike);
		rotate_sequence(&prog);
//		printf("YO\n");
//		print_list(&prog);		
		final_sort(&prog);
		print_list(&prog);
//		printf ("stack trie avec mouvements 🥵\n\n");		
	}
 	// system("leaks push_swap");
	 
	return(0);
}

