/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/21 20:35:30 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list_a(t_list *stack_a)
{
					int i = 0;
					int j = 1;
					i = ft_lstsize(stack_a);
					printf("\nlist A avec %d arg\n\n", i);
				
				    while(stack_a) 
					{
				        printf("lst %d contient %s\n",j ,stack_a->content);
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
				        printf("lst %d contient %s\n",j ,stack_b->content);
						j++;
				        stack_b = stack_b->next;
				    }
}

void print_list (t_list *stack_a, t_list *stack_b)
{
	print_list_a(stack_a);
	print_list_b(stack_b);
}


int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list **pstack_a;
	t_list **pstack_b;
	
	errors(argv);
	stack_a = creation_stack(argc, argv);
	stack_b = NULL;
	//stack_b = creation_stack(argc, argv);
	print_list(stack_a, stack_b);
	pstack_a = &stack_a;
	pstack_b = &stack_b;
	push_b(pstack_a, pstack_b);
	push_b(pstack_a, pstack_b);
	push_b(pstack_a, pstack_b);
	print_list(stack_a, stack_b);
//	rotate_a(pstack_a);
//	rotate_b(pstack_b);
	rotate_both(pstack_a, pstack_b);
	print_list(stack_a, stack_b);
	
// system("leaks push_swap");	
}


