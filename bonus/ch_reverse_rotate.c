/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:10:52 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 18:54:29 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ch_reverse_rotate_a(t_list **pstack_a)
{
	t_list	*swap;
	t_list	*last;

	swap = (*pstack_a);
	while (swap->next != NULL)
	{
		if (swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;
	swap->next = (*pstack_a);
	(*pstack_a) = swap;
}

void	ch_reverse_rotate_b(t_list **pstack_b)
{
	t_list	*swap;
	t_list	*last;

	swap = (*pstack_b);
	while (swap->next != NULL)
	{
		if (swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;
	swap->next = (*pstack_b);
	(*pstack_b) = swap;
}

void	ch_reverse_rotate_both(t_checker *checker)
{
	ch_reverse_rotate_a(&checker->stack_a);
	ch_reverse_rotate_b(&checker->stack_b);
}
