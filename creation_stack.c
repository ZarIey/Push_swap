/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:25:29 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/19 16:44:43ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prendre les arguments, les lier entre eux en liste

#include "push_swap.h"

t_list *arg_one(char **argv)
{
	int i;

	i = 0;	
	t_list *stack;
	t_list *inter;
	char **split;

	split = ft_split(argv[1], ' ');
	stack = ft_lstnew(split[i]);
	i++;
	while (split[i])
	{
		inter = ft_lstnew(split[i]);
		ft_lstadd_back(&stack, inter);
		i++;
	}
	return (stack);
}

t_list *creation_stack(int argc, char **argv)
{
	t_list *stack;
	if (argc > 2)
	{
		int i;
		t_list *inter;
	//	t_head head;

		i = 1;
		stack = ft_lstnew(argv[i]);
	//	head.head = stack;
		i++;	
		while (i < argc)
		{
			inter = ft_lstnew(argv[i]);
			ft_lstadd_back(&stack, inter);
			i++;
		}
		return (stack);
	}
	stack =	arg_one(argv);
	return (stack);
}
/*#include <stdio.h>


int main (int argc, char **argv)
{
	int i = 0;
	int j = 1;
	t_list *test;
//	t_head head;
	
	test = creation_stack(argc, argv);
	i = ft_lstsize(test);
	printf("list a %d arg\n", i);
// 	printf("head %s\n", head.head->content);

    while(test) 
	{
        printf("lst %d contient %s\n",j, test->content);
		j++;
        test = test->next;
    }
}*/