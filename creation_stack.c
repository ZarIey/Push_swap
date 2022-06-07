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

int	check_sorted(t_prog *prog)
{
	t_list *inter;
	inter = prog->stack_a;
	while (inter->next)
	{
//		printf("En AVANT %d\n", inter->content);
		if (inter->content > inter->next->content)
			return (-1);
		inter = inter->next;
	}
//	printf("I'm already sorted step-brother 🥵\n");
//	printf("AH PTAIN JSUIS BLOKE LES GAAW\n");
	return (0);
}

t_list *arg_one(char **argv)
{
	int i;

	i = 0;	
	t_list *stack;
	t_list *inter;
	char **split;

	split = ft_split((argv[1]), ' ');
	stack = ft_lstnew(ft_atoi(split[i]));
	i++;
	while (split[i])
	{
		inter = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack, inter);
		i++;
	}
	errors(split);
	return (stack);
}

t_list *creation_b(void *content)
{
	t_list *inter;

	inter = ft_lstnew(ft_atoi(content));
	return (inter);
}

t_list *creation_stack(int argc, char **argv)
{
	t_list *stack;
	if (argc > 2)
	{
		int i;
		t_list *inter;

		i = 1;
		stack = ft_lstnew(ft_atoi(argv[i]));
		i++;	
		while (i < argc)
		{
			inter = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&stack, inter);
			i++;
		}
		return (stack);
	}
	stack =	arg_one(argv);
	return (stack);
}
