/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:55:55 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/11 20:55:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_list(t_list **previous_next, t_list *last)
{
	t_list	*swap;

	swap = *previous_next;
	*previous_next = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*previous_next)->next_sort = swap;
}

void	ghost_sorting(t_list **pstack_a)
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

void	init_rank(t_list *stack_a, t_prog *prog)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i++;
		stack_a = stack_a->next_sort;
	}
	prog->total = i;
}
