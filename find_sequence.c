/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:26:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/04 18:21:14 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *init_sequence(t_prog *prog)
{
	t_list *stack_a;
	t_list *stack_first;
	t_list *stack_save;
	int i;

	stack_first = NULL;
	stack_save = NULL;
	stack_a = prog->stack_a;
	prog->strike = -1;
	while (stack_a->next)
	{
		i = 0;
		while (stack_a->content < stack_a->next->content)
		{
			if (i == 0 && check == 1)
				stack_first = stack_a;
			i++;
			stack_a = stack_a->next;
			check = 0;
		}
		if (prog->strike < i)
		{
			prog->strike = i;
			stack_save = stack_first;
			//check = 1;
		}
		stack_a = stack_a->next;
	}
	printf("valeur de strike %d\n", prog->strike);
	return (stack_save);
}

void secure_sequence(t_prog *prog)
{
	t_list *stack_a;
	t_list *stack_save;
	int i;
	int j;

	stack_a = prog->stack_a;
	i = 0;
	j = 0;
	k = 0;
	stack_save = init_sequence(prog);
	while (stack_a)
	{
		while (i++ < distance_to_top(prog, stack_save->index));
			stack_a = stack_a->next;
		while (stack_a && j <= prog->strike)
		{
			stack_a->stay = 1;
			stack_a = stack_a->next;
			j++;
		}
	}
	return (i);
}

void rotate_sequence(t_prog *prog)
{
	int i;
	int j;
	t_list *stack_save;

	stack_save = init_sequence;
	i = secure_sequence(prog);
	j = i + prog->strike;
	if (i >= prog->size/2)
	{
		i -= prog->size;
		while (i++ < (nega(prog->strike)))
			reverse_rotate_a(prog->stack_a);
		return ;
	}
	while (i-- > (i - (prog->strike)))
		rotate_a(prog->stack_a);
}
