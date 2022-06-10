/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:28:35 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 17:52:05 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*take_fastest_moove(t_list *stack_b)
{
	t_list	*save_list;
	int		i;
	int		j;
	int		k[2];

	save_list = stack_b;
	k[0] = INT_MAX;
	while (stack_b)
	{
		i = stack_b->rot_a;
		j = stack_b->rot_b;
		k[1] = nega(i) + nega(j);
		if (k[1] < k[0])
		{
			k[0] = k[1];
			save_list = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (save_list);
}

void	save_rot(t_prog *prog)
{
	t_list	*stack_b;
	int		i;
	int		size;

	stack_b = prog->stack_b;
	i = 0;
	size = size_list(stack_b);
	while (stack_b)
	{
		stack_b->rot_a = calcul_rotation_a(prog, prog->stack_a, stack_b);
		stack_b->rot_b = calcul_rotation_b(i, size);
		i++;
		stack_b = stack_b->next;
	}
}

void	final_sort(t_prog *prog)
{
	t_list	*save;
	t_list	*stack_b;
	int		i;

	i = 0;
	all_in_b(prog);
	stack_b = prog->stack_b;
	while (stack_b)
	{
		save_rot(prog);
		save = take_fastest_moove(prog->stack_b);
		keep_rotating(prog, save->rot_a, save->rot_b);
		push_a(&prog->stack_a, &prog->stack_b);
		prog->size++;
		stack_b = prog->stack_b;
	}
	keep_rotating(prog, distance_to_top(prog, 0), 0);
}
