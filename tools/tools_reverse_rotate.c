/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:10:52 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/14 13:39:51 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void fake_reverse_rotate_a(t_list **pstack_a)
{
	t_list *swap;
	t_list *last;

	swap = (*pstack_a);
	while (swap->next != NULL)
	{
		if(swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;	
	swap->next = (*pstack_a);
	(*pstack_a) = swap;
}

void fake_reverse_rotate_b(t_list **pstack_b)
{
	t_list *swap;
	t_list *last;

	swap = (*pstack_b);
	while (swap->next != NULL)
	{
		if(swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;	
	swap->next = (*pstack_b);
	(*pstack_b) = swap;
} 

void reverse_rotate_a(t_list **pstack_a)
{
	t_list *swap;
	t_list *last;

	swap = (*pstack_a);
	while (swap->next != NULL)
	{
		if(swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;	
	swap->next = (*pstack_a);
	(*pstack_a) = swap;
	ft_putstr_fd("rra\n", 1);
}

void reverse_rotate_b(t_list **pstack_b)
{
	t_list *swap;
	t_list *last;

	swap = (*pstack_b);
	while (swap->next != NULL)
	{
		if(swap->next->next == NULL)
			last = swap;
		swap = swap->next;
	}
	last->next = NULL;	
	swap->next = (*pstack_b);
	(*pstack_b) = swap;
	ft_putstr_fd("rrb\n", 1);
} 

void reverse_rotate_both(t_list **pstack_a, t_list **pstack_b)
{
	fake_reverse_rotate_a(pstack_a);
	fake_reverse_rotate_b(pstack_b);
	ft_putstr_fd("rrr\n", 1);
} 
