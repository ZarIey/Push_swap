/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:25:29 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 15:03:06 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_prog *prog)
{
	t_list	*inter;

	inter = prog->stack_a;
	while (inter->next)
	{
		if (inter->content > inter->next->content)
			return (-1);
		inter = inter->next;
	}
	return (0);
}

t_list	*arg_one(char **argv)
{
	t_list	*stack;
	t_list	*inter;
	char	**split;
	int		i;

	i = 0;
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

t_list	*creation_b(void *content)
{
	t_list	*inter;

	inter = ft_lstnew(ft_atoi(content));
	return (inter);
}

t_list	*creation_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*inter;
	int		i;

	if (argc > 2)
	{
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
	stack = arg_one(argv);
	return (stack);
}
