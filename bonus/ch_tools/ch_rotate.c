/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:46:10 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 18:56:05 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ch_rotate_a(t_list **pstack_a)
{
	t_list	*last;
	t_list	*temp;

	if (!*pstack_a || !(*pstack_a)->next)
		return ;
	last = *pstack_a;
	while (last->next)
		last = last->next;
	temp = (*pstack_a);
	*pstack_a = (*pstack_a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ch_rotate_b(t_list **pstack_b)

{
	t_list	*last;
	t_list	*temp;

	if (!*pstack_b || !(*pstack_b)->next)
		return ;
	last = *pstack_b;
	while (last->next)
		last = last->next;
	temp = (*pstack_b);
	*pstack_b = (*pstack_b)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ch_rotate_both(t_checker *checker)
{
	ch_rotate_a(&checker->stack_a);
	ch_rotate_b(&checker->stack_b);
}
