/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:58:04 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/19 18:55:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int size_list(t_list *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}	

int get_mini(t_list *stack_a)
{
	int mini;

	mini = 2147483647;
	while (stack_a)
	{
		if (mini > stack_a->content)
			mini = stack_a->content;
		stack_a = stack_a->next;
	}
	return (mini);
}

int get_maxi(t_list *stack_a)
{
	int maxi;

	maxi = -2147483648;
	while (stack_a)
	{
		if (maxi < stack_a->content)
			maxi = stack_a->content;
		stack_a = stack_a->next;
	}
	return (maxi);
}	

int compare_big(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}