/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:58:41 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/16 16:31:57 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	ch_size_list(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	checker_b_not_empty(t_checker *checker, char *commands)
{
	t_list	*stack_b;

	stack_b = checker->stack_b;
	if ((ft_strncmp(commands, "rrr", 3) == 0)
		|| (ft_strncmp(commands, "rrb", 3) == 0)
		|| (ft_strncmp(commands, "rb", 2) == 0)
		|| (ft_strncmp(commands, "pa", 2) == 0))
	{
		if (!(stack_b))
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
}

void	action_commands(t_checker *checker, char *commands)
{
	if (ft_strncmp(commands, "rrr", 3) == 0)
		return (ch_reverse_rotate_both(checker));
	if (ft_strncmp(commands, "rra", 3) == 0)
		return (ch_reverse_rotate_a(&checker->stack_a));
	if (ft_strncmp(commands, "rrb", 3) == 0)
		return (ch_reverse_rotate_b(&checker->stack_b));
	if (ft_strncmp(commands, "ra", 2) == 0)
		return (ch_rotate_a(&checker->stack_a));
	if (ft_strncmp(commands, "rb", 2) == 0)
		return (ch_rotate_b(&checker->stack_b));
	if (ft_strncmp(commands, "rr", 2) == 0)
		return (ch_rotate_both(checker));
	if (ft_strncmp(commands, "pa", 2) == 0)
		return (ch_push_a(&checker->stack_a, &checker->stack_b));
	if (ft_strncmp(commands, "pb", 2) == 0)
		return (ch_push_b(&checker->stack_a, &checker->stack_b));
	if (ft_strncmp(commands, "sa", 2) == 0)
		return (ch_swap_a(&checker->stack_a));
	if (ft_strncmp(commands, "sb", 2 == 0))
		return (ch_swap_b(&checker->stack_b));
	else
	{
		write (1, "Error\n", 6);
		exit(0);
	}
}

void	sorted_or_not_uh_uh(t_checker *checker, int size)
{
	t_list	*stack_a;
	int		resize;

	stack_a = checker->stack_a;
	resize = ch_size_list(stack_a);
	if (resize == size)
	{
		while (stack_a->next)
		{
			if (stack_a->content > stack_a->next->content)
			{
				exit (0);
			}
			stack_a = stack_a->next;
		}
		write (1, "OK\n", 3);
		return ;
	}
	else
	{
		write(1, "KO\n", 3);
	}
}
