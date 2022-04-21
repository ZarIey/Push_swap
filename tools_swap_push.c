/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:36:28 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/21 18:44:19 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list **pstack_a)
{
	t_list *swap;
	
	void *a = 0;
	void *b = 0;
	swap = (*pstack_a);
	a = swap->content;
	b = swap->next->content;
	swap->next->content = a;
	swap->content = b;
	ft_putstr_fd("sa\n", 3);
	return ;
}

void swap_b(t_list **pstack_b)
{
	t_list *swap;
	
	void *a = 0;
	void *b = 0;
	swap = (*pstack_b);
	a = swap->content;
	b = swap->next->content;
	swap->next->content = a;
	swap->content = b;
	ft_putstr_fd("sb\n", 3);
	return ;
}

void swap_both(t_list **pstack_a, t_list **pstack_b)
{
	t_list *swap;
	
	void *a = 0;
	void *b = 0;
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
	ft_putstr_fd("ss\n", 3);
	return ;
}

void push_a(t_list **pstack_a, t_list **pstack_b)
{
	ft_lstadd_front_content(pstack_a, ((*pstack_b)->content));
	ft_lstdel_first(pstack_b);
	ft_putstr_fd("pa\n", 1);
}

void push_b(t_list **pstack_a, t_list **pstack_b)
{
	ft_lstadd_front_content(pstack_b, ((*pstack_a)->content));
	ft_lstdel_first(pstack_a);
	ft_putstr_fd("pb\n", 1);
}
