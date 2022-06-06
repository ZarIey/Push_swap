/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:55:25 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/06 17:42:25 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_triple(t_prog *prog)
{
	t_list *swap;
	int	a;
	int	b;
	int	c;
	
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

int still_here(t_list *stack_a, int index)
{
	while (stack_a)
	{
		if (stack_a->index == index)
			return(1);
	stack_a = stack_a->next;
	}
	return (0);
}

int distance_to_top(t_prog *prog, int tag)
{
	int i;
	int size;
	t_list *stack_a;
	
	stack_a = prog->stack_a;
	size = size_list(stack_a);
	i = 0;
	while (stack_a)
	{
		if (stack_a->index == tag)
			break;
		i++;
		stack_a = stack_a->next;
	}
	// if (i > size / 2)
	// 	i -= size;
	return (i);
}


void first_sort_five(t_prog *prog)
{
	t_list *stack_a;
	int rot_a;

	stack_a = prog->stack_a;
	rot_a = distance_to_top(prog, 0);
	if (rot_a > size_list(stack_a) / 2)
		rot_a -= size_list(stack_a);
	keep_rotating(prog, rot_a, 0);
	push_b(&prog->stack_a, &prog->stack_b);
	print_list(prog);
	rot_a = distance_to_top(prog, 1);
	if (rot_a > (size_list(stack_a) / 2))
		rot_a -= size_list(stack_a);
	keep_rotating(prog, rot_a, 0);
	push_b(&prog->stack_a, &prog->stack_b);
}

void sort_five(t_prog *prog)
{
//	t_list *stack_a;
	t_list *stack_b;

	first_sort_five(prog);
	sort_triple(prog);
	print_list(prog);
	stack_b = prog->stack_b;
	while (stack_b)
	{
		if (stack_b->index == 1)
			push_a(&prog->stack_a, &prog->stack_b);
		stack_b = stack_b->next;
		push_a(&prog->stack_a, &prog->stack_b);
	}
	print_list(prog);
}

// void first_sort_five(t_prog *prog)
// {
// 	t_list *swap;
// 	int min;
// 	int atm;
	
// 	while (still_here(prog->stack_a, 0) || still_here(prog->stack_a, 1))
// 	{
// 		swap = prog->stack_a;
// 		min = INT_MAX;
// 		while (swap)
// 		{
// 			if (swap->index == 0 || swap->index == 1)
// 			{
// 				// atm = distance_to_top(prog, swap->index);
// 				// if (nega(atm) < nega(min))
// 				// 	min = atm;	
// 			}
// 			swap = swap->next;
// 		}
//  		if (min == 0)
//  		push_b(&prog->stack_a, &prog->stack_b);
// 		if (min < 0)
// 			reverse_rotate_a(&prog->stack_a);
// 		if (min > 0)
// 			rotate_a(&prog->stack_a);
// 	}
// }