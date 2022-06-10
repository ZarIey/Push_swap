/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:46:10 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/09 17:22:10 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fake_rotate_a(t_list **pstack_a)

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

void	fake_rotate_b(t_list **pstack_b)

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

void	rotate_a(t_list **pstack_a)
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
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **pstack_b)

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
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_prog *prog, int rot_a, int rot_b)
{
	(void)rot_a;
	(void)rot_b;
	fake_rotate_a(&prog->stack_a);
	fake_rotate_b(&prog->stack_b);
	ft_putstr_fd("rr\n", 1);
}
