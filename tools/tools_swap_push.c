/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:36:28 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/09 17:27:40 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **pstack_a)
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
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	swap_b(t_list **pstack_b)
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
	ft_putstr_fd("sb\n", 1);
	return ;
}

void	swap_both(t_list **pstack_a, t_list **pstack_b)
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
	ft_putstr_fd("ss\n", 1);
	return ;
}

void	push_a(t_list **pstack_a, t_list **pstack_b)
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
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **pstack_a, t_list **pstack_b)
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
	ft_putstr_fd("pb\n", 1);
}
