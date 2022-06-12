/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:25:32 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/11 20:57:19 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fake_swap_a(t_list **pstack_a)
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

void	fake_swap_b(t_list **pstack_b)
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

void	swap_test_a(t_prog *prog, t_list *x)
{
	t_list	*stack_b;
	int		fake_rot_a;
	int		size;

	stack_b = prog->stack_b;
	size = size_list(stack_b);
	while (stack_b)
	{
		fake_swap_a(&prog->stack_a);
		fake_rot_a = calcul_rotation_a(prog, prog->stack_a, x);
		if (x->rot_a > fake_rot_a)
			x->swap_a = 1;
		fake_swap_a(&prog->stack_a);
		stack_b = stack_b->next;
	}
}
