/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:46:10 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/19 16:59:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fake_rotate_a(t_list **pstack_a)

{
	t_list *swap;
	t_list *temp;
	
	temp = (*pstack_a);
	*pstack_a = (*pstack_a)->next;
	swap = (*pstack_a)->next;
	while (swap->next)
		swap = swap->next;	
	swap->next = temp;
	temp->next = NULL;
	
}

void	fake_rotate_b(t_list **pstack_b)

{
	t_list *swap;
	t_list *temp;
	
	temp = (*pstack_b);
	*pstack_b = (*pstack_b)->next;
	swap = (*pstack_b)->next;
	while (swap->next)
		swap = swap->next;	
	swap->next = temp;
	temp->next = NULL;
	
}

void	rotate_a(t_list **pstack_a)

{
	t_list *swap;
	t_list *temp;
	
	temp = (*pstack_a);
	*pstack_a = (*pstack_a)->next;
	swap = (*pstack_a)->next;
	while (swap->next)
		swap = swap->next;	
	swap->next = temp;
	temp->next = NULL;
	
	// t_list *swap;
	// int	save;

	// swap = (*pstack_a);
	// save = (*pstack_a)->content;
	// while (swap->next != NULL)
	// {
	// 	swap->content = swap->next->content;
	// 	swap = swap->next;
	// }
	// swap->content = save;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **pstack_b)

{
	t_list *swap;
	t_list *temp;
	
	temp = (*pstack_b);
	*pstack_b = (*pstack_b)->next;
	swap = (*pstack_b)->next;
	while (swap->next)
		swap = swap->next;	
	swap->next = temp;
	temp->next = NULL;
	
	ft_putstr_fd("rb\n", 1);
}

void rotate_both(t_list **pstack_a, t_list **pstack_b)
{
	fake_rotate_a(pstack_a);
	fake_rotate_b(pstack_b);
	ft_putstr_fd("rr\n", 1);
}