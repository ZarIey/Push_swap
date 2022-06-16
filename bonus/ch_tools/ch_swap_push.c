/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:36:28 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/16 14:21:57 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ch_swap_a(t_list **pstack_a)
{
	t_list	*inter;
	t_list	*last;

	if (!(*pstack_a) || !(*pstack_a)->next)
		return ;
	last = (*pstack_a)->next->next;
	inter = (*pstack_a);
	*pstack_a = (*pstack_a)->next;
	(*pstack_a)->next = inter;
	inter->next = last;
	return ;
}

void	ch_swap_b(t_list **pstack_b)
{
	t_list	*inter;
	t_list	*last;

	if (!(*pstack_b) || !(*pstack_b)->next)
		return ;
	last = (*pstack_b)->next->next;
	inter = (*pstack_b);
	*pstack_b = (*pstack_b)->next;
	(*pstack_b)->next = inter;
	inter->next = last;
	return ;
}

void	ch_swap_both(t_list **pstack_a, t_list **pstack_b)
{
	t_list	*swap;
	int		a;
	int		b;

	a = 0;
	b = 0;
	swap = (*pstack_a);
	a = swap->content;
	b = swap->next->content;
	swap->next->content = a;
	swap->content = b;
	swap = (*pstack_b);
	a = swap->content;
	b = swap->next->content;
	swap->next->content = a;
	swap->content = b;
	return ;
}

void	ch_push_a(t_list **pstack_a, t_list **pstack_b)
{
	t_list	*inter;

	if (!*pstack_b)
		return ;
	inter = *pstack_b;
	*pstack_b = inter->next;
	if (*pstack_a)
		inter->next = (*pstack_a);
	else
		inter->next = NULL;
	*pstack_a = inter;
}

void	ch_push_b(t_list **pstack_a, t_list **pstack_b)
{
	t_list	*inter;

	if (!*pstack_a)
		return ;
	inter = *pstack_a;
	*pstack_a = inter->next;
	if (*pstack_b)
		inter->next = (*pstack_b);
	else
		inter->next = NULL;
	*pstack_b = inter;
}
