/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:55:25 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/20 16:39:54 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void already_sorted(t_list *stack_a)
{	
	(void)stack_a;
}

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

int nega(int content)
{
	if (content < 0)
		return (content *= -1);
	return (content);
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
	if (i > size / 2)
		i -= size;
	return (i);
}

void sort_five(t_prog *prog)
{
	t_list *swap;
	int min;
	int atm;
	
	while (still_here(prog->stack_a, 0) || still_here(prog->stack_a, prog->total - 1))
	{
		swap = prog->stack_a;
		min = 2147483647;
		while (swap)
		{
			if (swap->index == 0 || swap->index == prog->total - 1)
			{
				atm = distance_to_top(prog, swap->index);
				if (nega(atm) < nega(min))
					min = atm;	
			}
			swap = swap->next;
		}
		if (min == 0)
			push_b(&prog->stack_a, &prog->stack_b);
		if (min < 0)
			reverse_rotate_a(&prog->stack_a);
		if (min > 0)
			rotate_a(&prog->stack_a);
	}
	// sort_triple(prog);
	// push_a(&prog->stack_a, &prog->stack_b);
	// push_a(&prog->stack_a, &prog->stack_b);
	// rotate_a(&prog->stack_a);
}
