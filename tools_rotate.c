/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:46:10 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/21 20:34:47 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **pstack_a)

{
	t_list *swap;
	void *save;

	swap = (*pstack_a);
	save = (*pstack_a)->content;
	while (swap->next != NULL)
	{
		swap->content = swap->next->content;
		swap = swap->next;
	}
	swap->content = save;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **pstack_b)

{
	t_list *swap;
	void *save;

	swap = (*pstack_b);
	save = (*pstack_b)->content;
	while (swap->next != NULL)
	{
		swap->content = swap->next->content;
		swap = swap->next;
	}
	swap->content = save;
	ft_putstr_fd("rb\n", 1);
}

void rotate_both(t_list **pstack_a, t_list **pstack_b)
{
	t_list *swap;
	t_list *swap2;
	void *save;
	void *save2;

	swap = (*pstack_a);
	save = (*pstack_a)->content;
	while (swap->next != NULL)
	{
		swap->content = swap->next->content;
		swap = swap->next;
	}
	swap->content = save;

	swap2 = (*pstack_b);
	save2 = (*pstack_b)->content;
	while (swap2->next != NULL)
	{
		swap2->content = swap2->next->content;
		swap2 = swap2->next;
	}
	swap2->content = save2;
	ft_putstr_fd("rr\n", 1);
}