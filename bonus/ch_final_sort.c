/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_final_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:54:05 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 15:28:17 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	distance_to_top_b(t_prog *prog, int tag)
{
	t_list	*stack_b;
	int		i;
	int		size;

	size = size_list(prog->stack_b);
	stack_b = prog->stack_b;
	i = 0;
	while (stack_b)
	{
		if (stack_b->index == tag)
			break ;
		i++;
		stack_b = stack_b->next;
	}
	if (i >= size / 2)
		i -= size;
	return (i);
}

t_list	*take_fastest_moove(t_prog *prog, t_list *stack_b)
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
			prog->moov = k[0];
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
	int		j;
	int		size;

	i = 0;
	all_in_b(prog);
	stack_b = prog->stack_b;
	while (stack_b)
	{
		init_swap(prog);
		size = size_list(stack_b);
		save_rot(prog);
		save = take_fastest_moove(prog, prog->stack_b);
		keep_rotating(prog, save->rot_a, save->rot_b);
		ch_push_a(&prog->stack_a, &prog->stack_b);
		prog->size++;
		stack_b = prog->stack_b;
	}
	j = distance_to_top(prog, 0);
	if (j >= size_list(prog->stack_a) / 2)
		j -= size_list(prog->stack_a);
	keep_rotating(prog, j, 0);
}
