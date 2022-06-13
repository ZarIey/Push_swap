/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:55:25 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 18:54:19 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triple(t_prog *prog)
{
	t_list	*swap;
	int		a;
	int		b;
	int		c;

	swap = prog->stack_a;
	a = swap->content;
	b = swap->next->content;
	c = swap->next->next->content;
	if (a > b && b > c && c < a)
	{
		swap_a(&prog->stack_a);
		reverse_rotate_a(&prog->stack_a);
	}
	if (a > b && b < c && c < a)
		rotate_a(&prog->stack_a);
	if (a < b && b > c && c < a)
		reverse_rotate_a(&prog->stack_a);
	if (a > b && b < c && c > a)
		swap_a(&prog->stack_a);
	if (a < b && b > c && c > a)
	{
		reverse_rotate_a(&prog->stack_a);
		swap_a(&prog->stack_a);
	}
}

int	still_here(t_list *stack_a, int index)
{
	while (stack_a)
	{
		if (stack_a->index == index)
			return (1);
	stack_a = stack_a->next;
	}
	return (0);
}

int	distance_to_top(t_prog *prog, int tag)
{
	t_list	*stack_a;
	int		i;

	stack_a = prog->stack_a;
	i = 0;
	while (stack_a)
	{
		if (stack_a->index == tag)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	push_little_ones(t_prog *prog)
{
	t_list	*stack_a;
	int		rot_a;
	int		size;

	stack_a = prog->stack_a;
	size = 5;
	rot_a = distance_to_top(prog, 0);
	if (rot_a > size / 2)
		rot_a -= size;
	keep_rotating(prog, rot_a, 0);
	push_b(&prog->stack_a, &prog->stack_b);
	size = 4;
	rot_a = distance_to_top(prog, 1);
	if (rot_a > (size / 2))
		rot_a -= size;
	keep_rotating(prog, rot_a, 1);
	push_b(&prog->stack_a, &prog->stack_b);
}

void	sort_five(t_prog *prog)
{
	t_list	*stack_b;

	push_little_ones(prog);
	sort_triple(prog);
	stack_b = prog->stack_b;
	while (stack_b)
	{
		if (stack_b->index == 1)
			push_a(&prog->stack_a, &prog->stack_b);
		stack_b = stack_b->next;
		push_a(&prog->stack_a, &prog->stack_b);
	}
}
