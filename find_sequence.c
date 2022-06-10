/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:26:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 18:15:56 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_sequence(t_prog *prog, t_list *stack_a)
{
	t_list	*stack_first;
	t_list	*stack_save;
	int		i;

	stack_first = stack_a;
	prog->strike = -1;
	while (stack_a->next)
	{
		i = 0;
		while (stack_a->next && stack_a->content < stack_a->next->content)
		{
			if (i == 0)
				stack_first = stack_a;
			i++;
			stack_a = stack_a->next;
		}
		if (prog->strike <= i)
		{
			prog->strike = i;
			stack_save = stack_first;
		}
		if (i == 0)
			stack_a = stack_a->next;
	}
	return (stack_save);
}

int	secure_sequence(t_prog *prog)
{
	t_list	*stack_a;
	t_list	*stack_save;
	int		distance;
	int		i;
	int		j;

	stack_save = NULL;
	stack_a = prog->stack_a;
	i = 0;
	j = 0;
	stack_save = init_sequence(prog, prog->stack_a);
	distance = distance_to_top(prog, stack_save->index);
	while (stack_a)
	{
		while (i++ < distance)
			stack_a = stack_a->next;
		secure_stay(prog);
		while (stack_a && j++ <= prog->strike)
		{
			stack_a->stay = 1;
			stack_a = stack_a->next;
		}
		break ;
	}
	return (i);
}

void	all_reverse(t_prog *prog, t_list *stack_a)
{
	int	l;

	l = size_list(stack_a);
	while (l > 0)
	{
		push_b(&prog->stack_a, &prog->stack_b);
		l--;
	}
	l = size_list(prog->stack_b);
	while (l > 0)
	{
		rotate_b(&prog->stack_b);
		l--;
	}
	push_a(&prog->stack_a, &prog->stack_b);
	push_a(&prog->stack_a, &prog->stack_b);
	swap_a(&prog->stack_a);
	while (size_list(prog->stack_b) > 0)
	{
		push_a(&prog->stack_a, &prog->stack_b);
		rotate_a(&prog->stack_a);
	}
	exit(0);
}

void	clean_order(t_prog *prog, int i, int j, int k)
{
	if (k > i)
	{
		while (j >= 0)
		{
			rotate_a(&prog->stack_a);
			j--;
		}
		return ;
	}
	while (k > 1)
	{
		reverse_rotate_a(&prog->stack_a);
		k--;
	}
}

void	rotate_sequence(t_prog *prog)
{
	t_list	*stack_a;
	t_list	*stack_save;
	int		i;
	int		j;
	int		k;

	stack_a = prog->stack_a;
	stack_save = init_sequence(prog, prog->stack_a);
	i = distance_to_top(prog, stack_save->index);
	j = i + prog->strike;
	k = prog->size - j;
	secure_sequence(prog);
	if (check_if_sequence(prog) == 0)
		all_reverse(prog, prog->stack_a);
	clean_order(prog, i, j, k);
}
