/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:17:05 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/30 06:18:33 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list **previous_next, t_list *last)
{
	t_list	*swap;

	swap = *previous_next;
	*previous_next = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*previous_next)->next_sort = swap;
}

void	push_bigger(t_list **pstack_a)
{
	t_list	*last;
	t_list	*prev;

	prev = NULL;
	last = *pstack_a;
	while (last && last->next_sort)
	{
		if (last->content - last->next_sort->content > 0)
		{
			if (prev == NULL)
				swap_list(pstack_a, last);
			else
				swap_list(&(prev->next_sort), last);
			last = *pstack_a;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

int	index_asc_order(t_list *list, t_list *start, int set)
{
	t_list	*asc_ord;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	asc_ord = start;
	while (asc_ord)
	{
		if (set)
			asc_ord->keep = 0;
		if (asc_ord->index > max_tag)
		{
			max_tag = asc_ord->index;
			count++;
			if (set)
				asc_ord->keep = 1;
		}
		asc_ord = asc_ord->next;
		if (asc_ord == NULL)
			asc_ord = list;
		if (asc_ord == start)
			break ;
	}
	return (count);
}

int	find_biggest_asc_order(t_list *start, int set)
{
	t_list	*t;
	int		max;
	int		count;
	t_list	*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = index_asc_order(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
	{
		index_asc_order(start, max_keep, 1);
		printf("Helloooo\n");
	}
	return (max);
}

void	init_rank(t_list *stack_a, t_prog *prog)
{
	int i;
	i = 0;
	while (stack_a)
	{
		stack_a->index = i++;
		stack_a = stack_a->next_sort;
	}
	prog->total = i;
}
