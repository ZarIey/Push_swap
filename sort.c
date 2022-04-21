/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:55:25 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/20 16:30:00 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void hard_push(t_list *stack_a)

void sort_triple(t_list **stack_a)
{
	t_list *swap;
	int a;
	int b;
	int c;
	
	swap = *stack_a;
	a = swap->content;
	b = swap->next->content;
	c = swap->next->next->content;
	if (a > b && b < c && a < c)
	{
		swap->next->content = a;
		swap->content = b;
	}
	if (a > b && b < c && a > c)
	{
		swap a et c
		swap->next->next->content = a;
		swap->content = c;
	}
	if 	
}

void 