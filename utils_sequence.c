/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:15:37 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/11 16:11:43 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	secure_stay(t_prog *prog)
{
	t_list	*stack_a;

	stack_a = prog->stack_a;
	while (stack_a)
	{
		stack_a->stay = 0;
		stack_a = stack_a->next;
	}
}

void	init_swap(t_prog *prog)
{
	t_list	*stack_b;

	stack_b = prog->stack_b;
	while (stack_b)
	{
		stack_b->swap_a = 0;
		stack_b = stack_b->next;
	}
}

int	check_if_sequence(t_prog *prog)
{
	t_list	*stack_a;
	int		i;

	stack_a = prog->stack_a;
	i = 0;
	while (stack_a->next)
	{
		if (stack_a->next && stack_a->content < stack_a->next->content)
			i++;
		stack_a = stack_a->next;
	}
	return (i);
}
